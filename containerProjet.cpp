#include "containerProjet.h"

ContainerProjet::ContainerProjet()
{
	setStyleSheet("QScrollArea{border:1px solid rgba(0,0,0,0); background:rgba(0,0,0,0); }");

	setAcceptDrops(true);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setWidgetResizable(true);
	setSizeAdjustPolicy(AdjustToContents);

	scrollAreaWidgetContents = new QWidget();
	vboxLayout = new QVBoxLayout(scrollAreaWidgetContents);
	vboxLayout->setSpacing(4);
	vboxLayout->setContentsMargins(4, 4, 4, 4);

	setWidget(scrollAreaWidgetContents);
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

