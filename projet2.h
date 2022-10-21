#pragma once

#include <QMainWindow>

class Projet : public QMainWindow
{
	Q_OBJECT

public:
	Projet(QString, QString, QString, QString);
	~Projet();

protected:
	int statut; // 0 -> to do ; 1 -> doing ; 2 -> done ; (3 -> )
	QString nom_projet;
	QString type_projet;
	QString nom_client;
	QString description;
	QString commentaire;

};