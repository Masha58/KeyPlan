#pragma once

#include <QMainWindow>
#include "ui_commandtheme.h"
#include <QRadioButton>
#include <QPushButton>

class CommandTheme : public QMainWindow
{
	Q_OBJECT

public:
	CommandTheme(QWidget *parent = nullptr);
	~CommandTheme();
	QPushButton& getB_valider() { return *ui.b_valider; }
	QRadioButton& getRb_1() { return *ui.rb_1; }
	QRadioButton& getRb_2() { return *ui.rb_2; }
	QRadioButton& getRb_3() { return *ui.rb_3; }
	QRadioButton& getRb_4() { return *ui.rb_4; }

private:
	Ui::CommandThemeClass ui;

};
