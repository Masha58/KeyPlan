#include "menuselector.h"

MenuSelector::MenuSelector(QWidget *parent)
	: QDialog(parent), ok(QPushButton("Ok")), cancel(QPushButton("Cancel"))
{
	setWindowTitle("Selection");

	hbox.addWidget(&ok);
	hbox.addWidget(&cancel);

	comboBox.addItem("Application");
	comboBox.addItem("Plugin");
	comboBox.addItem("Task");
	comboBox.setMinimumSize(100, 25);

	vbox.addWidget(new QLabel("Choose type of project"));
	vbox.addWidget(&comboBox);
	vbox.addLayout(&hbox);
	setLayout(&vbox);

	QPushButton::connect(&ok, SIGNAL(clicked()), this, SLOT(accept()));
	QPushButton::connect(&cancel, SIGNAL(clicked()), this, SLOT(reject()));

}

MenuSelector::~MenuSelector() = default;

void MenuSelector::accepter()
{
	accept();
}

void MenuSelector::rejeter()
{
	reject();
}
