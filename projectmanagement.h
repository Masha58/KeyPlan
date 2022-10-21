#pragma once

#include <QWidget>
#include <iostream>
#include "ui_projectmanagement.h"
#include "projet.h"
#include "plugin.h"
#include "logiciel.h"
#include "tache.h"
#include "containerProjet.h"

class ProjectManagement : public QWidget
{
	Q_OBJECT

public:
	ProjectManagement(QWidget *parent = nullptr);
	~ProjectManagement();

	
private:
	Ui::ProjectManagementClass ui;
	std::vector<Projet*> tab_projets;

	ContainerProjet *containerprojet_todo;
	ContainerProjet *containerprojet_doing;
	ContainerProjet* containerprojet_done;

private slots:
	void ajout_projet_to_do();
	void ajout_projet_doing();
	void ajout_projet_done();
	void ajout_projet(Projet&);
};
