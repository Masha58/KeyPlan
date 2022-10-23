#include "tache.h"


Tache::Tache(int statut, QString nom_projet, QString nom_client, QString description)
	:Projet(statut, "Task", nom_projet, nom_client, description)
{
	type_tache = "";
}

Tache::~Tache()
{

}