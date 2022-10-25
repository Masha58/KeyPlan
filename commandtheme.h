#pragma once

#include <QMainWindow>
#include "ui_commandtheme.h"

class CommandTheme : public QMainWindow
{
	Q_OBJECT

public:
	CommandTheme(QWidget *parent = nullptr);
	~CommandTheme();

private:
	Ui::CommandThemeClass ui;
};
