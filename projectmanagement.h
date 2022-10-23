#pragma once

#include <QWidget>
#include <iostream>
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

	
private:
	int compteur;
	Ui::ProjectManagementClass ui;
	std::vector<Projet*> tab_projets;

	ContainerProjet *containerprojet_todo;
	ContainerProjet *containerprojet_doing;
	ContainerProjet* containerprojet_done;

	MenuSelector *menu;

private slots:
	void ajout_projet(QVBoxLayout&);
	void supprimer_projet(QString);
	void afficher_details(QString);
};
