#include "tache.h"


Tache::Tache(QString nom_projet, QString nom_client, QString description)
	:Projet("tache", nom_projet, nom_client, description)
{
	annexe = "";
}

Tache::~Tache()
{

}