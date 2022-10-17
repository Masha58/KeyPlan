#include "plugin.h"

Plugin::Plugin(QString nom_projet, QString nom_client, QString description)
	:Projet("plugin", nom_projet, nom_client, description)
{
	nom_logiciel = "";
}

Plugin::~Plugin()
{}
