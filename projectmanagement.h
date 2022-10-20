#pragma once

#include <QWidget>
#include <iostream>
#include "ui_projectmanagement.h"
#include "projet.h"
#include "plugin.h"
#include "logiciel.h"
#include "tache.h"

class ProjectManagement : public QWidget
{
	Q_OBJECT

public:
	ProjectManagement(QWidget *parent = nullptr);
	~ProjectManagement();

	
private:
	Ui::ProjectManagementClass ui;
	std::vector<Projet*> tab_projets;

private slots:
	void ajout_projet_to_do();
	void ajout_projet(Projet&);
};
