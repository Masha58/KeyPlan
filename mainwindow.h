#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "projet.h"
#include "plugin.h"
#include <QStackedLayout>
#include "projectmanagement.h"
#include "dashboard.h"
#include "commandtheme.h"

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private:
    Ui::mainwindowClass ui;

    Dashboard dashboard;
    CommandTheme commandTheme;
    QStackedLayout mainStackedlayout;
    ProjectManagement projectmanagement;

private slots:
    void change_fenetre(int);
    void closeTabTheme();
    void activateCommandTheme();
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

#endif