/********************************************************************************
** Form generated from reading UI file 'mainwindowZYlsuR.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWZYLSUR_H
#define MAINWINDOWZYLSUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowClass
{
public:
    QAction *actionNouveau;
    QAction *actionImporter;
    QAction *actionExporter;
    QAction *actionTh_me;
    QAction *actionfhgf;
    QAction *actionChanger_d_utilisateur;
    QAction *actionSe_d_connecter;
    QAction *actionSe_connecter;
    QAction *actionSe_d_connecter_2;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_13;
    QFrame *fr_menu_haut;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer;
    QComboBox *cb_menu;
    QVBoxLayout *vl_projectmanagement;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuAide;
    QMenu *menu_dition;
    QMenu *menuProfile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName("mainwindowClass");
        mainwindowClass->resize(914, 635);
        mainwindowClass->setStyleSheet(QString::fromUtf8("*{\n"
"	font: 11pt \"Calibri\";\n"
"}\n"
"\n"
"QMainWindow{\n"
"	border-image: url(images/mainwindow/fond.jpg)  0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QMenuBar, QMenu\n"
"{\n"
"background: rgba(65,65,65,0.85);\n"
"color:white;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"background: rgba(65,65,65,0.95);\n"
"}\n"
"\n"
"/* QFrame */\n"
"\n"
"#fr_menu_haut\n"
"{\n"
"background: rgba(65,65,65,0.6);\n"
"}\n"
"\n"
"/* QToolBar */\n"
"\n"
"QToolBar {\n"
"padding:12px;\n"
"    background: rgba(65,65,65,0.6);\n"
"    spacing: 18px; /* spacing between items in the tool bar */\n"
"	border-bottom:2px solid rgb(245,245,250);\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"background: none; \n"
"border: none;\n"
"}\n"
"\n"
"\n"
"/* COMBOBOX */\n"
"\n"
"QComboBox{\n"
"font: 16pt \"Calibri\";\n"
"color : white;\n"
"background-color:rgba(0,0,0,0);\n"
"border : 1px solid rgba(31,48,92,0.0);\n"
"padding-left:5px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"border:0px;\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"image: url(images/mainwind"
                        "ow/arrow-down.png);\n"
"width:15px;\n"
"height:15px;\n"
"margin-right:8px;\n"
"margin-left:8px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color:rgb(65,65,65);\n"
"	background:rgb(217,225,227);\n"
"	border: 1px solid rgb(250,250,250);\n"
"}\n"
"\n"
""));
        actionNouveau = new QAction(mainwindowClass);
        actionNouveau->setObjectName("actionNouveau");
        actionNouveau->setCheckable(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/mainwindow/newTask.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNouveau->setIcon(icon);
        actionImporter = new QAction(mainwindowClass);
        actionImporter->setObjectName("actionImporter");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/mainwindow/importer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImporter->setIcon(icon1);
        actionExporter = new QAction(mainwindowClass);
        actionExporter->setObjectName("actionExporter");
        actionTh_me = new QAction(mainwindowClass);
        actionTh_me->setObjectName("actionTh_me");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/mainwindow/pantone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTh_me->setIcon(icon2);
        actionfhgf = new QAction(mainwindowClass);
        actionfhgf->setObjectName("actionfhgf");
        actionChanger_d_utilisateur = new QAction(mainwindowClass);
        actionChanger_d_utilisateur->setObjectName("actionChanger_d_utilisateur");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/mainwindow/user.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChanger_d_utilisateur->setIcon(icon3);
        actionSe_d_connecter = new QAction(mainwindowClass);
        actionSe_d_connecter->setObjectName("actionSe_d_connecter");
        actionSe_connecter = new QAction(mainwindowClass);
        actionSe_connecter->setObjectName("actionSe_connecter");
        actionSe_connecter->setIcon(icon3);
        actionSe_d_connecter_2 = new QAction(mainwindowClass);
        actionSe_d_connecter_2->setObjectName("actionSe_d_connecter_2");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/mainwindow/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSe_d_connecter_2->setIcon(icon4);
        centralWidget = new QWidget(mainwindowClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout_13 = new QVBoxLayout(centralWidget);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_13->setContentsMargins(0, 0, -1, 6);
        fr_menu_haut = new QFrame(centralWidget);
        fr_menu_haut->setObjectName("fr_menu_haut");
        fr_menu_haut->setMinimumSize(QSize(0, 70));
        fr_menu_haut->setMaximumSize(QSize(16777215, 70));
        horizontalLayout = new QHBoxLayout(fr_menu_haut);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        label_10 = new QLabel(fr_menu_haut);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(150, 0));
        label_10->setMaximumSize(QSize(150, 16777215));
        label_10->setStyleSheet(QString::fromUtf8("image:url(images/mainwindow/logo_menu.png);"));

        horizontalLayout->addWidget(label_10, 0, Qt::AlignLeft);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cb_menu = new QComboBox(fr_menu_haut);
        cb_menu->addItem(QString());
        cb_menu->addItem(QString());
        cb_menu->setObjectName("cb_menu");
        cb_menu->setMinimumSize(QSize(210, 0));

        horizontalLayout->addWidget(cb_menu);


        verticalLayout_13->addWidget(fr_menu_haut);

        vl_projectmanagement = new QVBoxLayout();
        vl_projectmanagement->setSpacing(6);
        vl_projectmanagement->setObjectName("vl_projectmanagement");

        verticalLayout_13->addLayout(vl_projectmanagement);

        mainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainwindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 914, 25));
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName("menuFichier");
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName("menuAide");
        menu_dition = new QMenu(menuBar);
        menu_dition->setObjectName("menu_dition");
        menuProfile = new QMenu(menuBar);
        menuProfile->setObjectName("menuProfile");
        mainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainwindowClass);
        mainToolBar->setObjectName("mainToolBar");
        mainToolBar->setMovable(false);
        mainToolBar->setOrientation(Qt::Vertical);
        mainToolBar->setIconSize(QSize(42, 42));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        mainToolBar->setFloatable(true);
        mainwindowClass->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(mainwindowClass);
        statusBar->setObjectName("statusBar");
        mainwindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menu_dition->menuAction());
        menuBar->addAction(menuProfile->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionImporter);
        menu_dition->addAction(actionTh_me);
        menuProfile->addAction(actionSe_connecter);
        menuProfile->addAction(actionSe_d_connecter_2);
        mainToolBar->addAction(actionSe_connecter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNouveau);
        mainToolBar->addAction(actionImporter);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSe_d_connecter_2);

        retranslateUi(mainwindowClass);

        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QCoreApplication::translate("mainwindowClass", "mainwindow", nullptr));
        actionNouveau->setText(QCoreApplication::translate("mainwindowClass", "Nouveau", nullptr));
#if QT_CONFIG(tooltip)
        actionNouveau->setToolTip(QCoreApplication::translate("mainwindowClass", "Nouvelle t\303\242che", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNouveau->setShortcut(QCoreApplication::translate("mainwindowClass", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionImporter->setText(QCoreApplication::translate("mainwindowClass", "Importer", nullptr));
#if QT_CONFIG(tooltip)
        actionImporter->setToolTip(QCoreApplication::translate("mainwindowClass", "Importer", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionImporter->setShortcut(QCoreApplication::translate("mainwindowClass", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExporter->setText(QCoreApplication::translate("mainwindowClass", "Exporter", nullptr));
        actionTh_me->setText(QCoreApplication::translate("mainwindowClass", "Th\303\250me", nullptr));
        actionfhgf->setText(QCoreApplication::translate("mainwindowClass", "fhgf", nullptr));
        actionChanger_d_utilisateur->setText(QCoreApplication::translate("mainwindowClass", "Changer d'utilisateur", nullptr));
        actionSe_d_connecter->setText(QCoreApplication::translate("mainwindowClass", "Se d\303\251connecter", nullptr));
        actionSe_connecter->setText(QCoreApplication::translate("mainwindowClass", "Se connecter", nullptr));
        actionSe_d_connecter_2->setText(QCoreApplication::translate("mainwindowClass", "Se d\303\251connecter", nullptr));
        label_10->setText(QString());
        cb_menu->setItemText(0, QCoreApplication::translate("mainwindowClass", "Project Management", nullptr));
        cb_menu->setItemText(1, QCoreApplication::translate("mainwindowClass", "Dashboard", nullptr));

        menuFichier->setTitle(QCoreApplication::translate("mainwindowClass", "File", nullptr));
        menuAide->setTitle(QCoreApplication::translate("mainwindowClass", "Help", nullptr));
        menu_dition->setTitle(QCoreApplication::translate("mainwindowClass", "Edit", nullptr));
        menuProfile->setTitle(QCoreApplication::translate("mainwindowClass", "Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWZYLSUR_H
