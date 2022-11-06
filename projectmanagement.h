#ifndef PROJECTMANAGEMENT_H
#define PROJECTMANAGEMENT_H

#include <QWidget>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <memory>
#include <QtGui>
#include <QtCore>
#include "ui_projectmanagement.h"
#include "projet.h"
#include "plugin.h"
#include "logiciel.h"
#include "tache.h"
#include "containerProjet.h"
#include "menuselector.h"


class ProjectManagement : public QWidget
{
	Q_OBJECT

public:
	ProjectManagement(QWidget *parent = nullptr);
	~ProjectManagement();
	void maj_bdd();
	//void databaseConnect();
	void maj_statut();
	void creationProjet(Projet&, QVBoxLayout&);
	void creationJobs(Projet&);


	QVBoxLayout& returnLayoutFromProjet(Projet&);

private:
	int compteur = 1;
	//QSqlDatabase m_db;
	Ui::ProjectManagementClass ui;
	std::vector<Projet*> tab_projets;

	ContainerProjet containerprojet_todo = ContainerProjet(0);
	ContainerProjet containerprojet_doing = ContainerProjet(1);
	ContainerProjet containerprojet_done = ContainerProjet(2);

	MenuSelector menu;

private slots:
	void ajout_projet(QVBoxLayout&);
	void supprimer_projet(QString);
	void afficher_details(QString);
};

#endif