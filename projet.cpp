#include "projet.h"

Projet::Projet(QString type_projet, QString nom_projet, QString nom_client, QString description):
	type_projet(type_projet),nom_projet(nom_projet), nom_client(nom_client), description(description)
{
	statut = 0;
	commentaire = "";
}

Projet::~Projet()
{}
