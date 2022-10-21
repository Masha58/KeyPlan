#include "logiciel.h"

Logiciel::Logiciel(int statut, QString nom_projet, QString nom_client, QString description)
	:Projet(statut, "logiciel", nom_projet, nom_client, description)
{}

Logiciel::~Logiciel()
{}
