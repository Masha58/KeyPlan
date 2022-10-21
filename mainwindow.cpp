#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent): QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("KeyPlan (beta version)");

    // initialisation des attributs layout
    projectmanagement = new ProjectManagement();
    dashboard = new Dashboard();
    mainStackedlayout = new QStackedLayout();

    // agencement des layouts 
    ui.vl_projectmanagement->addLayout(mainStackedlayout);
    mainStackedlayout->addWidget(projectmanagement);
    mainStackedlayout->addWidget(dashboard);
    mainStackedlayout->setCurrentIndex(0);

    QComboBox::connect(ui.cb_menu, SIGNAL(currentIndexChanged(int)), this, SLOT(change_fenetre(int)));

}

mainwindow::~mainwindow()
{
    delete projectmanagement;
}

void mainwindow::change_fenetre(int index)
{
    mainStackedlayout->setCurrentIndex(index);
}
