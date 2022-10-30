#pragma once

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <memory>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_projet.h"
#include "lineEdit.h"

enum MoveDirection { MoveUp, MoveDown };

class Projet : public QWidget
{
	Q_OBJECT

public:
	Projet(int, QString, QString, QString, QString);
	~Projet();
	Ui::ProjetClass ui;

	int getStatut() { return statut; }
	void setStatut(int newStatut) { statut = newStatut; }
	int getToken() { return token; }

	QString getParentWidget() { return parentWidget()->objectName(); }
	QFrame& getFrameDetails() { return *ui.fr_annexe; }
	QFrame& getFrameProjet() { return *ui.fr_projet; }
	QString getNom_projet() { return nom_projet; }
	QTextEdit& getTe_descriotion() { return *ui.te_description; }
	bool IsMinimumDistanceRiched(const QMouseEvent*) const;
	bool moveInLayout(QWidget*, MoveDirection direction) const;
	void setToken(int newtoken) { token = newtoken; }
	double getoldX() { return oldX; }
	double getoldY() { return oldY; }

protected:
	
	// bdd
	int statut; // 0 -> to do ; 1 -> doing ; 2 -> done ; (3 -> )
	QString nom_projet;
	QString type_projet;
	QString nom_client;
	QString description;
	QString commentaire = "";

	// autre
	int token = 0;
	double oldX = 0;
	double oldY = 0;
	double mouseClickY = 0;
	double mouseClickX = 0;

	QMimeData* mimeData;
	QPoint dragStartPosition;
	LineEdit lineEdit_titre;
	LineEdit lineEdit_nom_client;

public slots:
	void mouseMoveEvent(QMouseEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void paintEvent(QPaintEvent*);

	void maj_titre();

};