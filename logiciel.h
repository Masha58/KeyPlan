#pragma once

#include <QObject>
#include "projet.h"

class Logiciel  : public Projet
{
	Q_OBJECT

public:
	Logiciel(QString, QString, QString);
	~Logiciel();

private:
	QString type_logiciel;
	QString plateforme;
};
