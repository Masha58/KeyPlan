#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent): QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("KeyPlan");

    tab_projets.push_back(new Plugin("test", "test", "test"));
}

mainwindow::~mainwindow()
{
    for (unsigned int i = 0; i < tab_projets.size(); i++)
    {
        delete tab_projets[i];
    }
}
