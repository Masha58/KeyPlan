#pragma once

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
	
	QWidget* scrollAreaWidgetContents;
public:
	ContainerProjet();
	~ContainerProjet();
	QVBoxLayout* vboxLayout = nullptr;
	

private slots:
	void dragEnterEvent(QDragEnterEvent*);
	void dropEvent(QDropEvent*);
};

