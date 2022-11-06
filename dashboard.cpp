#include "dashboard.h"
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QSqlQuery>
#include <QSqlError>

void databaseConnect_dashboard()
{
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("bdd/bdd");

    if (!m_db.open())
        qDebug() << "Error: connection with database failed";
    else
        qDebug() << "Database: connection ok";
}

Dashboard::Dashboard(QWidget *parent)
	: QWidget(parent), max(0)
{
	ui.setupUi(this);
    databaseConnect_dashboard();

    setChiffre("0", *ui.la_num_project_todo);
    setChiffre("1", *ui.la_num_project_doing);
    setChiffre("2", *ui.la_num_project_done);
    setChiffre("3", *ui.la_num_project_archived);

    ui.gl_chart_app->addWidget(&createPieChart("Apps Summary", "Application"));
    ui.gl_chart_task->addWidget(&createPieChart("Tasks Summary", "Task"));
    ui.gl_chart_plugin->addWidget(&createPieChart("Plugins Summary", "Plugin"));
    ui.gl_chart_general->addWidget(&createBarChart());
}

void Dashboard::maj_dashboard()
{
    max = 0;

    ui.gl_chart_app->removeItem(ui.gl_chart_app->itemAt(0));
    ui.gl_chart_task->removeItem(ui.gl_chart_task->itemAt(0));
    ui.gl_chart_plugin->removeItem(ui.gl_chart_plugin->itemAt(0));
    ui.gl_chart_general->removeItem(ui.gl_chart_general->itemAt(0));

    setChiffre("0", *ui.la_num_project_todo);
    setChiffre("1", *ui.la_num_project_doing);
    setChiffre("2", *ui.la_num_project_done);
    setChiffre("3", *ui.la_num_project_archived);

    ui.gl_chart_app->addWidget(&createPieChart("Apps Summary", "Application"));
    ui.gl_chart_task->addWidget(&createPieChart("Tasks Summary", "Task"));
    ui.gl_chart_plugin->addWidget(&createPieChart("Plugins Summary", "Plugin"));
    ui.gl_chart_general->addWidget(&createBarChart());
}

Dashboard::~Dashboard() = default;

QChartView& Dashboard::createBarChart()
{
    QBarSet* set0 = new QBarSet("Application");
    QBarSet* set1 = new QBarSet("Plugin");
    QBarSet* set2 = new QBarSet("Task");

    *set0 << getChiffre("0", "Application") << getChiffre("1", "Application") << getChiffre("2", "Application");
    *set1 << getChiffre("0", "Plugin") << getChiffre("1", "Plugin") << getChiffre("2", "Plugin");
    *set2 << getChiffre("0", "Task") << getChiffre("1", "Task") << getChiffre("2", "Task");

    QBarSeries* series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Summary of projects");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "To Do" << "Doing" << "To do";
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, max);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return *chartView;
}


QChartView& Dashboard::createPieChart(QString titre, QString typeProject)
{
    QPieSeries* series = new QPieSeries();
    series->append("To Do", getChiffre("0", typeProject));
    series->append("Doing", getChiffre("1", typeProject));
    series->append("Done", getChiffre("2", typeProject));

    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(titre);
    chart->legend()->setVisible(true);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return *chartView;
}


void Dashboard::setChiffre(QString statut, QLabel& label)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PROJETS WHERE statut = :stat");
    query.bindValue(":stat", statut);

    if (!query.exec())
        qWarning() << "Error setChiffre : " << query.lastError().text();

    while (query.next())
        label.setText(query.value(0).toString());
}

int Dashboard::getChiffre(QString statut, QString typeProjet)
{
    int result = 0;
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PROJETS WHERE statut = :stat AND type_projet = :type");
    query.bindValue(":stat", statut);
    query.bindValue(":type", typeProjet);

    if (!query.exec())
        qWarning() << "Error getChiffre : " << query.lastError().text();

    while (query.next())
        result = query.value(0).toInt();

    if (result > max)
        max = result;

    return result;
}