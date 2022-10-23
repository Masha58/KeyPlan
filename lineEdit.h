#pragma once

#include <QLineEdit>
#include <iostream>
#include <QWidget>
#include <QKeyEvent>

class LineEdit : public QLineEdit
{
private:
public:
	LineEdit(QString, QString);
	~LineEdit();

private slots:
	void mouseDoubleClickEvent(QMouseEvent*event);
	void keyPressEvent(QKeyEvent *);

};

