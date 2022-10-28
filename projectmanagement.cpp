#include "projectmanagement.h"

struct second_deleter
{
	template <typename T>
	void operator()(const T& pX) const
	{
		delete pX;
	}
};

ProjectManagement::ProjectManagement(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.vl_area_todo->addWidget(&containerprojet_todo);
	ui.vl_area_doing->addWidget(&containerprojet_doing);
	ui.vl_area_done->addWidget(&containerprojet_done);

	maj_bdd();

	QPushButton::connect(ui.b_newtask_to_do, &QPushButton::clicked, this, [this]() { ajout_projet(containerprojet_todo.vboxLayout); });
	QPushButton::connect(ui.b_newtask_doing, &QPushButton::clicked, this, [this]() { ajout_projet(containerprojet_doing.vboxLayout); });
	QPushButton::connect(ui.b_newtask_done, &QPushButton::clicked, this, [this]() { ajout_projet(containerprojet_done.vboxLayout); });

}

ProjectManagement::~ProjectManagement()
{
	m_db.close();
	std::for_each(tab_projets.begin(), tab_projets.end(), second_deleter());
}

void ProjectManagement::ajout_projet(QVBoxLayout& layout)
{
	int return_value = menu.exec();

	if (return_value)
	{
		if (menu.getValueComboBox() == "Plugin")
		{
			auto* project = new Plugin(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });
		
		}
		else if (menu.getValueComboBox() == "Application")
		{
			auto* project = new Logiciel(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
			layout.addWidget(project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });
		
		}
		else
		{
			auto* project = new Tache(0, "Titre " + QString::number(compteur), "Nom client", "Undefined");
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
			//bool a = tab_projets[position]->parentWidget()->whatsThis() == containerprojet_todo.getScrollAreaWidgetContent().whatsThis();
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

void ProjectManagement::databaseConnect() const
{
	QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("bdd/bdd");

	if (!m_db.open())
		qDebug() << "Error: connection with database failed";
	else
		qDebug() << "Database: connection ok";
}

void ProjectManagement::addBonLayout(Projet &projet)
{
	if (projet.getStatut() == 0)
	{
		containerprojet_todo.vboxLayout.addWidget(&projet);
	}
	else if (projet.getStatut() == 1)
	{
		containerprojet_doing.vboxLayout.addWidget(&projet);
	}
	if (projet.getStatut() == 2)
	{
		containerprojet_done.vboxLayout.addWidget(&projet);
	}
}


void ProjectManagement::maj_bdd()
{
	databaseConnect();
	QSqlQuery query;
	query.prepare("SELECT id_projet, statut, nom_projet, type_projet, nom_client, description, commentaire FROM PROJET");

	if (!query.exec())
		qWarning() << "Error vmaj bdd : " << query.lastError().text();

	while (query.next())
	{

		if (query.value(3).toString() == "Task")
		{
			auto* project = new Tache(query.value(1).toInt(), query.value(2).toString(), query.value(4).toString(), query.value(5).toString());
			addBonLayout(*project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });

		}
		else if (query.value(3).toString() == "Plugin")
		{
			auto* project = new Plugin(query.value(1).toInt(), query.value(2).toString(), query.value(4).toString(), query.value(5).toString());
			addBonLayout(*project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });

		}
		else if (query.value(3).toString() == "Application")
		{
			auto* project = new Logiciel(query.value(1).toInt(), query.value(2).toString(), query.value(4).toString(), query.value(5).toString());
			addBonLayout(*project);
			tab_projets.push_back(project);
			QPushButton::connect(project->ui.b_supprimer, &QPushButton::clicked, project, [this, project]() { supprimer_projet(project->getNom_projet()); });
			QPushButton::connect(project->ui.b_detail, &QPushButton::clicked, project, [this, project]() { afficher_details(project->getNom_projet()); });

		}
	}
}


//void ui_clearLayout(QLayout* layout)
//{
//	while (!layout->isEmpty())
//	{
//		QWidget const* w = layout->takeAt(0)->widget();
//		QLayout* hb = layout->takeAt(0)->layout();
//		if (hb)
//		{
//			while (!hb->isEmpty())
//			{
//				QWidget* w = hb->layout()->takeAt(0)->widget();
//				QLayout* ssLayout = hb->layout()->takeAt(0)->layout();
//				if (w)
//					hb->removeWidget(w);
//				if (ssLayout)
//					hb->removeItem(ssLayout);
//			}
//			layout->removeItem(hb);
//		}
//	}
//}
