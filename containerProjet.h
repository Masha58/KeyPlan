#ifndef CONTAINERPROJET_H
#define CONTAINERPROJET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QScrollArea>
#include <QVBoxLayout>
#include "plugin.h"
#include "projet.h"

class ContainerProjet : public QScrollArea
{
	Q_OBJECT
private:
	QWidget scrollAreaWidgetContents;
	std::vector<Projet*> tab_projets;

public:
	ContainerProjet(int);
	~ContainerProjet();

	QVBoxLayout vboxLayout;
	QWidget& getScrollAreaWidgetContent() { return scrollAreaWidgetContents; }
	

private slots:
	void dragEnterEvent(QDragEnterEvent*);
	void dropEvent(QDropEvent*);
};

#endif

