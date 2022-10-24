#include "containerProjet.h"

ContainerProjet::ContainerProjet(int whatsthis)
{
	QString ssheet_back = "border:none; background:none; background-color:none;";

	scrollAreaWidgetContents = new QWidget();
	scrollAreaWidgetContents->setStyleSheet(ssheet_back);
	scrollAreaWidgetContents->setWhatsThis(QString::number(whatsthis));

	vboxLayout = new QVBoxLayout(scrollAreaWidgetContents);
	vboxLayout->setSpacing(8);
	vboxLayout->setContentsMargins(4, 4, 4, 4);

	setAcceptDrops(true);
	setWidgetResizable(true);
	setStyleSheet(ssheet_back);
	setWidget(scrollAreaWidgetContents);
	setSizeAdjustPolicy(AdjustToContents);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

ContainerProjet::~ContainerProjet()
{
	delete vboxLayout;
	delete scrollAreaWidgetContents;
}

void ContainerProjet::dropEvent(QDropEvent* event)
{
	vboxLayout->addWidget(qobject_cast<QWidget*>(event->source()));
}


void ContainerProjet::dragEnterEvent(QDragEnterEvent* event)
{
	event->accept();
}

