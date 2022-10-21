#pragma once

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QScrollArea>
#include <QHBoxLayout>

class ContainerProjet : public QScrollArea
{
	Q_OBJECT
private:
	//QHBoxLayout* hboxLayout;
public:
	ContainerProjet();
	~ContainerProjet();

private slots:
	void dragEnterEvent(QDragEnterEvent*);
	void dropEvent(QDropEvent*);
};

