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

    tab_projets.push_back(new Plugin("test", "test", "test"));

    QComboBox::connect(ui.cb_menu, SIGNAL(currentIndexChanged(int)), this, SLOT(change_fenetre(int)));
}

mainwindow::~mainwindow()
{
    for (unsigned int i = 0; i < tab_projets.size(); i++)
    {
        delete tab_projets[i];
    }
    delete projectmanagement;
}

void mainwindow::change_fenetre(int index)
{
    mainStackedlayout->setCurrentIndex(index);
}
