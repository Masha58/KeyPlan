#pragma once

#include <QWidget>
#include <QtGui>
#include <QtCore>

#include "ui_projet.h"

enum MoveDirection { MoveUp, MoveDown };

class Projet : public QWidget
{
	Q_OBJECT

public:
	Projet();
	Projet(int, QString, QString, QString, QString);
	~Projet();
	Ui::ProjetClass ui;

	int getStatut() { return statut; }
	QString getNom_projet() { return nom_projet; }
	bool IsMinimumDistanceRiched(QMouseEvent*);
	bool moveInLayout(QWidget* widget, MoveDirection direction);

protected:
	
	int statut; // 0 -> to do ; 1 -> doing ; 2 -> done ; (3 -> )
	QString nom_projet;
	QString type_projet;
	QString nom_client;
	QString description;
	QString commentaire;

	double oldX;
	double oldY;
	double mouseClickY;
	double mouseClickX;
	QPoint dragStartPosition;
	QMimeData* mimeData = nullptr;

public slots:
	void mouseMoveEvent(QMouseEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void paintEvent(QPaintEvent*);
};