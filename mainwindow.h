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

private slots:
    void change_fenetre(int);
    
};


/*
Couleur intéressante
bleu : rgb(0, 188, 213); --> Software
bleu foncé : rgb(3,123,186);
orange : rgb(253, 161, 21); --> Task
vert : rgb(84, 229, 154); --> Plugin
vert foncé : 97,186,85);
violet : rgb(192, 124, 222);
jaune : rgb(232,210,29);
*/
