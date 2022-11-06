#ifndef LOGICIEL_H
#define LOGICIEL_H

#include <QObject>
#include "projet.h"

class Logiciel  : public Projet
{
	Q_OBJECT

public:
	Logiciel(int, QString, QString, QString);
	~Logiciel();

private:
	QString type_logiciel;
	QString plateforme;
};

#endif