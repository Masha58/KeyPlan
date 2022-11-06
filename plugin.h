#ifndef PLUGIN_H
#define PLUGIN_H

#include <QWidget>
#include "projet.h"

class Plugin : public Projet
{
	Q_OBJECT

public:
	Plugin(int, QString, QString, QString);
	~Plugin();

private:
	QString nom_logiciel;

};

#endif