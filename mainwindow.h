#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "projet.h"
#include "plugin.h"
#include <QStackedLayout>
#include "projectmanagement.h"
#include "dashboard.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private:
    Ui::mainwindowClass ui;
    ProjectManagement *projectmanagement;
    Dashboard* dashboard;

    QStackedLayout *mainStackedlayout;

    std::vector<Projet*> tab_projets;

private slots:
    void change_fenetre(int);
    
};


/*
Couleur int�ressante
bleu : rgb(0, 188, 213);
bleu fonc� : rgb(3,123,186);
orange : rgb(253, 161, 21);
vert : rgb(84, 229, 154);
vert fonc� : 97,186,85);
violet : rgb(192, 124, 222);
jaune : rgb(232,210,29);
*/
