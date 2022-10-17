#include "projet.h"

Projet::Projet(int statut, QString type_projet, QString nom_projet, QString nom_client, QString description) :
	statut(statut),type_projet(type_projet), nom_projet(nom_projet), nom_client(nom_client), description(description)
{
	ui.setupUi(this);
	commentaire = "";

	if (type_projet == "logiciel")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(0, 188, 213);color:white;border-radius:3px;");
	else if(type_projet == "tache")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(253, 161, 21);color:white;border-radius:3px;");
	else if(type_projet == "plugin")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(84, 229, 154);color:white;border-radius:3px;");
		
	ui.la_titre_projet->setText(nom_projet);
	ui.la_tag_projet->setText(type_projet);
	ui.la_nom_client->setText(nom_client);

}

Projet::~Projet()
{}
