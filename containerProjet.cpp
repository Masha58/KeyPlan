#include "containerProjet.h"

ContainerProjet::ContainerProjet()
{
	setAcceptDrops(true);
	//hboxLayout = new QHBoxLayout();
	//setLayout(hboxLayout);
}

ContainerProjet::~ContainerProjet()
{
	//delete hboxLayout;
}

void ContainerProjet::dropEvent(QDropEvent* event)
{

	if (event->source() != this)
	{
		event->source()->setParent(this);
		layout()->addWidget(qobject_cast<QWidget*>(event->source()));
	}
}


void ContainerProjet::dragEnterEvent(QDragEnterEvent* event)
{
	event->accept();
}

