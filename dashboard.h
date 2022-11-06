#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include "ui_dashboard.h"

class Dashboard : public QWidget
{
	Q_OBJECT

public:
	Dashboard(QWidget *parent = nullptr);
	~Dashboard();
	QChartView& createPieChart();
	QChartView& createBarChart();

private:
	Ui::DashboardClass ui;
};

#endif