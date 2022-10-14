#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent): QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("KeyPlan");
}

mainwindow::~mainwindow()
{}
