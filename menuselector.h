#pragma once

#include <QDialog>
#include <QMessageBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class MenuSelector : public QDialog
{
	Q_OBJECT

public:
	MenuSelector(QWidget *parent = nullptr);
	~MenuSelector();

	QString getValueComboBox() { return comboBox->currentText(); };

private:
	QVBoxLayout* vbox;
	QHBoxLayout* hbox;
	QComboBox* comboBox;
	QPushButton* ok;
	QPushButton* cancel;

private slots:
	void accepter();
	void rejeter();
};
