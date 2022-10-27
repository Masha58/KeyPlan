#include "plugin.h"

Plugin::Plugin(int statut, QString nom_projet, QString nom_client, QString description)
	:Projet(statut, nom_projet, "Plugin", nom_client, description), nom_logiciel("")
{
}

Plugin::~Plugin() = default;
