#include "lineEdit.h"

LineEdit::LineEdit(QString titre, QString color)
{
	setText(titre);
	setReadOnly(true);
	setMinimumSize(100, 25);
	setStyleSheet("background:none; border:1px solid rgb(250,250,250); border-radius:5px;color: " + color + ";");
}

void LineEdit::mouseDoubleClickEvent(QMouseEvent * event)
{
	setReadOnly(false);
}