#pragma once

#include <QWidget>
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

	void ajout_projet(Projet &);

private:
	Ui::ProjectManagementClass ui;
	std::vector<Projet*> tab_projets;
};
