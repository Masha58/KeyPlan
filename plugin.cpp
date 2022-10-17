#include "plugin.h"

Plugin::Plugin(int statut, QString nom_projet, QString nom_client, QString description)
	:Projet(statut, "plugin", nom_projet, nom_client, description)
{
	nom_logiciel = "";
}

Plugin::~Plugin()
{}
