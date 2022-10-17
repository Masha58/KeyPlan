#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "projet.h"
#include "plugin.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private:
    Ui::mainwindowClass ui;

    std::vector<Projet*> tab_projets;
};
