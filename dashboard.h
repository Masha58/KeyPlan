#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include "ui_dashboard.h"

class Dashboard : public QWidget
{
	Q_OBJECT

public:
	Dashboard(QWidget *parent = nullptr);
	~Dashboard();

private:
	Ui::DashboardClass ui;
};

#endif