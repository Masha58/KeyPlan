#include "mainwindow.h"

QString styleSheetMW = "*{font: 11pt 'Calibri';}"
"QMenuBar, QMenu{background: rgba(65,65,65,0.85);color:white;}"
"QMenuBar::item:selected{background: rgba(65,65,65,0.95);}"
"#fr_menu_haut{background: rgba(65,65,65,0.6);}QToolBar{padding:12px;background: rgba(65,65,65,0.6);spacing: 18px;border-bottom:2px solid rgb(245,245,250);}"
"QToolButton:hover{background: none;border: none;}"
"QComboBox{font:16pt 'Calibri';color:white;background-color:rgba(0,0,0,0);border:1px solid rgba(31,48,92,0.0);padding-left:5px;}"
"QComboBox::drop-down{border:0px;}"
"QComboBox::down-arrow{image: url(images/mainwindow/arrow-down.png);width:15px;height:15px;margin-right:8px;margin-left:8px;}"
"QComboBox QAbstractItemView{color:rgb(65,65,65);background:rgb(217,225,227); border: 1px solid rgb(250,250,250);}";

mainwindow::mainwindow(QWidget *parent): QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("KeyPlan (beta version)");

    // initialisation des attributs layout
    projectmanagement = new ProjectManagement();
    dashboard = new Dashboard();
    mainStackedlayout = new QStackedLayout();
    commandTheme = new CommandTheme();

    // agencement des layouts 
    ui.vl_projectmanagement->addLayout(mainStackedlayout);
    mainStackedlayout->addWidget(projectmanagement);
    mainStackedlayout->addWidget(dashboard);
    mainStackedlayout->setCurrentIndex(0);

    QComboBox::connect(ui.cb_menu, SIGNAL(currentIndexChanged(int)), this, SLOT(change_fenetre(int)));
    connect(ui.actionTh_me, SIGNAL(triggered()), this, SLOT(activateCommandTheme()));

    QPushButton::connect(&commandTheme->getB_valider(), SIGNAL(clicked()), this, SLOT(closeTabTheme()));

}

mainwindow::~mainwindow()
{
    delete projectmanagement;
}

void mainwindow::change_fenetre(int index)
{
    mainStackedlayout->setCurrentIndex(index);

    if (index == 0)
    {
        projectmanagement->maj_bdd();
    }
    else
    {

    }
}

void mainwindow::activateCommandTheme()
{
    commandTheme->show();
}

void mainwindow::closeTabTheme()
{
    if (commandTheme->getRb_1().isChecked())
    {
        setStyleSheet(styleSheetMW + "QMainWindow{border-image: url(images/mainwindow/fond.jpg)  0 0 0 0 stretch stretch;}");
    }
    else if (commandTheme->getRb_2().isChecked())
    {
        setStyleSheet(styleSheetMW + "QMainWindow{border-image: url(images/mainwindow/fond_2.jpg)  0 0 0 0 stretch stretch;}");
    }
    else if (commandTheme->getRb_3().isChecked())
    {
        setStyleSheet(styleSheetMW + "QMainWindow{border-image: url(images/mainwindow/fond_3.jpg)  0 0 0 0 stretch stretch;}");
    }
    else if (commandTheme->getRb_4().isChecked())
    {
        setStyleSheet(styleSheetMW + "QMainWindow{border-image: url(images/mainwindow/fond_4.jpg)  0 0 0 0 stretch stretch;}");
    }
    commandTheme->hide();
}