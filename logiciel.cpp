#include "logiciel.h"

Logiciel::Logiciel(int statut, QString nom_projet, QString nom_client, QString description)
	:Projet(statut, nom_projet, "Application", nom_client, description)
{}

Logiciel::~Logiciel() = default;
