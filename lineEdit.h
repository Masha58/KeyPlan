#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>
#include <iostream>
#include <QWidget>
#include <QKeyEvent>
#include <QValidator>

class LineEdit : public QLineEdit
{

public:
	LineEdit(QString, QString);
};

#endif