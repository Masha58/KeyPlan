#include "dashboard.h"
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>

Dashboard::Dashboard(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


    ui.gl_chart_app->addWidget(&createPieChart());
    ui.gl_chart_task->addWidget(&createPieChart());
    ui.gl_chart_plugin->addWidget(&createPieChart());
    ui.gl_chart_general->addWidget(&createBarChart());
}

Dashboard::~Dashboard() = default;

QChartView& Dashboard::createBarChart()
{
    QBarSet* set0 = new QBarSet("Jane");
    QBarSet* set1 = new QBarSet("John");
    QBarSet* set2 = new QBarSet("Axel");
    QBarSet* set3 = new QBarSet("Mary");
    QBarSet* set4 = new QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    //![1]

    //![2]
    QBarSeries* series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    //![2]

    //![3]
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY = new QValueAxis();
    axisY->setRange(0, 15);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    //![4]

    //![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return *chartView;
}


QChartView& Dashboard::createPieChart()
{
    QPieSeries* series = new QPieSeries();
    series->append("Jane", 1);
    series->append("Joe", 2);
    series->append("Andy", 3);
    series->append("Barbara", 4);
    series->append("Axel", 5);
    //![1]

    //![2]
    QPieSlice* slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);
    //![2]

    //![3]
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple piechart example");
    chart->legend()->setVisible(true);
    //![3]

    //![4]
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return *chartView;
}


