#include "projectmanagement.h"

ProjectManagement::ProjectManagement(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	menu = new MenuSelector();

	compteur = 1;

	containerprojet_todo = new ContainerProjet(0);
	containerprojet_doing = new ContainerProjet(1);
	containerprojet_done = new ContainerProjet(2);

	ui.vl_area_todo->addWidget(containerprojet_todo);
	ui.vl_area_doing->addWidget(containerprojet_doing);
	ui.vl_area_done->addWidget(containerprojet_done);

	maj_bdd();

	QPushButton::connect(ui.b_newtask_to_do, &QPushButton::clicked, this, [this]() { ajout_projet(*containerprojet_todo->vboxLayout); });
	QPushButton::connect(ui.b_newtask_doing, &QPushButton::clicked, this, [this]() { ajout_projet(*containerprojet_doing->vboxLayout); });
	QPushButton::connect(ui.b_newtask_done, &QPushButton::clicked, this, [this]() { ajout_projet(*containerprojet_done->vboxLayout); });

}

ProjectManagement::~ProjectManagement()
{
	m_db.close();
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
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });
		
		}
		else if (menu->getValueComboBox() == "Application")
		{
			Logiciel* project = new Logiciel(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });
		
		}
		else if (menu->getValueComboBox() == "Task")
		{
			Tache* project = new Tache(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });
		
		}
		else
		{
			Projet* project = new Projet();
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });

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

void ProjectManagement::afficher_details(QString nom_projet)
{
	int position = 0;
	for (unsigned int i = 0; i < tab_projets.size(); i++)
	{
		if (tab_projets[i]->getNom_projet() == nom_projet)
		{
			bool a = tab_projets[position]->parentWidget()->whatsThis() == containerprojet_todo->getScrollAreaWidgetContent().whatsThis();
			position = i;
			break;
		}
	}

	if (tab_projets[position]->getToken())
	{
		tab_projets[position]->setToken(0);
		tab_projets[position]->getFrameDetails().setVisible(false);
		tab_projets[position]->getFrameProjet().setMinimumSize(50, 120);
		tab_projets[position]->getFrameProjet().setMaximumSize(500, 120);
	}
	else
	{
		tab_projets[position]->setToken(1);
		tab_projets[position]->getFrameDetails().setVisible(true);
		tab_projets[position]->getFrameProjet().setMinimumSize(50, 300);
		tab_projets[position]->getFrameProjet().setMaximumSize(500, 300);
	}
}

void ProjectManagement::databaseConnect(QSqlDatabase m_db)
{
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("bdd/bdd");

	if (!m_db.open())
	{
		qDebug() << "Error: connection with database failed";
	}
	else
	{
		qDebug() << "Database: connection ok";
	}
}

void ProjectManagement::addBonLayout(Projet &projet)
{
	if (projet.getStatut() == 0)
	{
		containerprojet_todo->vboxLayout->addWidget(&projet);
	}
	else if (projet.getStatut() == 1)
	{
		containerprojet_doing->vboxLayout->addWidget(&projet);
	}
	if (projet.getStatut() == 2)
	{
		containerprojet_done->vboxLayout->addWidget(&projet);
	}
}


void ProjectManagement::maj_bdd()
{
	databaseConnect(m_db);
	QSqlQuery query;
	query.prepare("SELECT id_projet, statut, nom_projet, type_projet, nom_client, description, commentaire FROM PROJET");

	if (!query.exec())
		qWarning() << "Error vmaj bdd : " << query.lastError().text();

	while (query.next())
	{

		if (query.value(3).toString() == "Task")
		{
			Tache* project = new Tache(query.value(1).toInt(), query.value(2).toString(), query.value(4).toString(), query.value(5).toString());
			addBonLayout(*project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });

		}
		else if (query.value(3).toString() == "Plugin")
		{
			Plugin* project = new Plugin(query.value(1).toInt(), query.value(2).toString(), query.value(4).toString(), query.value(5).toString());
			addBonLayout(*project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });

		}
		else if (query.value(3).toString() == "Application")
		{
			Logiciel* project = new Logiciel(query.value(1).toInt(), query.value(2).toString(), query.value(4).toString(), query.value(5).toString());
			addBonLayout(*project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });

		}
		
	}
}