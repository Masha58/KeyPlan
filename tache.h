#pragma once
#include "projet.h"

class Tache : public Projet
{
private:
	QString annexe;
public:
	Tache(QString, QString, QString);
	~Tache();
};

