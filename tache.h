#ifndef TACHE_H
#define TACHE_H

#include "projet.h"

class Tache : public Projet
{
private:
	QString type_tache;
public:
	Tache(int, QString, QString, QString);
	~Tache();
};

#endif