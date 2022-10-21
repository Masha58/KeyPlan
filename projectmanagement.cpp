#include "projectmanagement.h"

ProjectManagement::ProjectManagement(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	containerprojet_todo = new ContainerProjet();
	containerprojet_doing = new ContainerProjet();
	containerprojet_done = new ContainerProjet();

	ui.vl_area_todo->addWidget(containerprojet_todo);
	ui.vl_area_doing->addWidget(containerprojet_doing);
	ui.vl_area_done->addWidget(containerprojet_done);

	
	Plugin *plugin = new Plugin(0, "test", "test", "test");
	Plugin* plugin1 = new Plugin(1, "test", "test", "test");
	Plugin* plugin2 = new Plugin(2, "test", "test", "test");

	Logiciel* logiciel = new Logiciel(0, "test", "test", "test");
	Logiciel* logiciel1 = new Logiciel(1, "test", "test", "test");
	Logiciel* logiciel2 = new Logiciel(2, "test", "test", "test");

	Tache* tache1 = new Tache(1, "test", "test", "test");
	Tache* tache2 = new Tache(2, "test", "test", "test");

	ajout_projet(*tache2);
	ajout_projet(*logiciel);
	ajout_projet(*plugin);
	ajout_projet(*plugin1);
	ajout_projet(*tache1);
	ajout_projet(*plugin2);
	
	ajout_projet(*logiciel1);
	ajout_projet(*logiciel2);

	QPushButton::connect(ui.b_newtask_to_do, SIGNAL(clicked()), this, SLOT(ajout_projet_to_do()));
	//QPushButton::connect(ui.b_newtask_doing, SIGNAL(clicked()), this, SLOT(ajout_projet_doing()));
	//QPushButton::connect(ui.b_newtask_done, SIGNAL(clicked()), this, SLOT(ajout_projet_done()));
}

ProjectManagement::~ProjectManagement()
{
	for (unsigned int i = 0; i < tab_projets.size(); i++)
	{
		delete tab_projets[i];
	}
}

void ProjectManagement::ajout_projet_to_do()
{
	std::cout << "statut_";
	Tache* tache = new Tache(0, "test", "test", "test");
	ajout_projet(*tache);
}


void ProjectManagement::ajout_projet(Projet& projet)
{
	int statut = projet.getStatut();
	if (statut == 0)
		containerprojet_todo->vboxLayout->addWidget(&projet);
	else if(statut == 1)
		containerprojet_doing->vboxLayout->addWidget(&projet);
	else
		containerprojet_done->vboxLayout->addWidget(&projet);

	tab_projets.push_back(&projet);
}

//void ajout_projet_doing()