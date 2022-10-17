#pragma once

#include <QWidget>
#include "ui_projectmanagement.h"

class ProjectManagement : public QWidget
{
	Q_OBJECT

public:
	ProjectManagement(QWidget *parent = nullptr);
	~ProjectManagement();

private:
	Ui::ProjectManagementClass ui;
};
