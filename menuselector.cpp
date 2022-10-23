#include "menuselector.h"

MenuSelector::MenuSelector(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle("Selection");
	vbox = new QVBoxLayout();
	hbox = new QHBoxLayout();
	ok = new QPushButton("Ok");
	cancel = new QPushButton("Cancel");
	hbox->addWidget(ok);
	hbox->addWidget(cancel);

	comboBox = new QComboBox();
	comboBox->addItem("Application");
	comboBox->addItem("Plugin");
	comboBox->addItem("Task");
	comboBox->setMinimumSize(100, 25);

	vbox->addWidget(new QLabel("Choose type of project"));
	vbox->addWidget(comboBox);
	vbox->addLayout(hbox);
	setLayout(vbox);

	QPushButton::connect(ok, SIGNAL(clicked()), this, SLOT(accept()));
	QPushButton::connect(cancel, SIGNAL(clicked()), this, SLOT(reject()));

}

MenuSelector::~MenuSelector()
{
	delete vbox;
	delete comboBox;
}

void MenuSelector::accepter()
{
	accept();
}

void MenuSelector::rejeter()
{
	reject();
}
