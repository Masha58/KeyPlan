#include "lineEdit.h"

LineEdit::LineEdit(QString titre, QString color)
{
	setText(titre);
	setReadOnly(true);
	setMinimumSize(100, 25);
	setStyleSheet("background:none; border:1px solid rgb(250,250,250); border-radius:5px;color: " + color + ";");
}


LineEdit::~LineEdit()
{

}

void LineEdit::mouseDoubleClickEvent(QMouseEvent * event)
{
	setReadOnly(false);
}

void LineEdit::keyPressEvent(QKeyEvent * keyEvent)
{

	if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Escape)
	{
		setReadOnly(true);

		// TO DO : save in database
	}
	else
	{
		QLineEdit::keyPressEvent(keyEvent);
	}
}
