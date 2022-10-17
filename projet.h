#pragma once

#include <QWidget>
#include "ui_projet.h"

class Projet : public QWidget
{
	Q_OBJECT

public:
	Projet(int, QString, QString, QString, QString);
	~Projet();

	int getStatut() { return statut; }

protected:
	Ui::ProjetClass ui;
	int statut; // 0 -> to do ; 1 -> doing ; 2 -> done ; (3 -> )
	QString nom_projet;
	QString type_projet;
	QString nom_client;
	QString description;
	QString commentaire;
};