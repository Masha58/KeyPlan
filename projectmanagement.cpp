#include "projectmanagement.h"

ProjectManagement::ProjectManagement(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	Plugin *plugin = new Plugin(0, "test", "test", "test");
	Plugin* plugin1 = new Plugin(1, "test", "test", "test");
	Plugin* plugin2 = new Plugin(2, "test", "test", "test");

	Logiciel* logiciel = new Logiciel(0, "test", "test", "test");
	Logiciel* logiciel1 = new Logiciel(1, "test", "test", "test");
	Logiciel* logiciel2 = new Logiciel(2, "test", "test", "test");

	Tache* tache = new Tache(0, "test", "test", "test");
	Tache* tache1 = new Tache(1, "test", "test", "test");
	Tache* tache2 = new Tache(2, "test", "test", "test");

	ajout_projet(*plugin);
	ajout_projet(*plugin1);
	ajout_projet(*tache1);
	ajout_projet(*plugin2);
	ajout_projet(*tache2);
	ajout_projet(*logiciel);
	ajout_projet(*logiciel1);
	ajout_projet(*logiciel2);
	ajout_projet(*tache);
}

ProjectManagement::~ProjectManagement()
{
	for (unsigned int i = 0; i < tab_projets.size(); i++)
	{
		delete tab_projets[i];
	}
}

void ProjectManagement::ajout_projet(Projet& projet)
{
	int statut = projet.getStatut();
	if (statut == 0)
		ui.vl_todo_projet->addWidget(&projet);
	else if(statut == 1)
		ui.vl_doing_projet->addWidget(&projet);
	else
		ui.vl_done_projet->addWidget(&projet);

	tab_projets.push_back(&projet);
}
