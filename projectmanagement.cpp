#include "projectmanagement.h"

ProjectManagement::ProjectManagement(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	menu = new MenuSelector();

	compteur = 1;

	containerprojet_todo = new ContainerProjet();
	containerprojet_doing = new ContainerProjet();
	containerprojet_done = new ContainerProjet();

	ui.vl_area_todo->addWidget(containerprojet_todo);
	ui.vl_area_doing->addWidget(containerprojet_doing);
	ui.vl_area_done->addWidget(containerprojet_done);

	QPushButton::connect(ui.b_newtask_to_do, &QPushButton::clicked, this, [this]() { ajout_projet(*containerprojet_todo->vboxLayout); });
	QPushButton::connect(ui.b_newtask_doing, &QPushButton::clicked, this, [this]() { ajout_projet(*containerprojet_doing->vboxLayout); });
	QPushButton::connect(ui.b_newtask_done, &QPushButton::clicked, this, [this]() { ajout_projet(*containerprojet_done->vboxLayout); });

}

ProjectManagement::~ProjectManagement()
{
	for (unsigned int i = 0; i < tab_projets.size(); i++)
	{
		delete tab_projets[i];
	}
	delete menu;
}

void ProjectManagement::ajout_projet(QVBoxLayout& layout)
{
	int return_value = menu->exec();

	if (return_value)
	{
		if (menu->getValueComboBox() == "Plugin")
		{
			Plugin* project = new Plugin(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });

		}
		else if (menu->getValueComboBox() == "Application")
		{
			Logiciel* project = new Logiciel(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });

		}
		else if (menu->getValueComboBox() == "Task")
		{
			Tache* project = new Tache(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });

		}
		else
		{
			Projet* project = new Projet();
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });

		}
		compteur++;

	}
}

void ProjectManagement::supprimer_projet(QString nom_projet)
{
	int position = 0;
	for (unsigned int i = 0; i < tab_projets.size(); i++)
	{
		if (tab_projets[i]->getNom_projet() == nom_projet)
		{
			position = i;
			break;
		}
	}

	tab_projets[position]->parentWidget()->layout()->removeWidget(tab_projets[position]);
	tab_projets[position]->setVisible(false);
	tab_projets.erase(tab_projets.begin() + position);

}