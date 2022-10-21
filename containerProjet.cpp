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

	vboxLayout->addWidget(new Plugin(0, "test", "test", "test"));
}

ContainerProjet::~ContainerProjet()
{
	delete scrollAreaWidgetContents;
	delete vboxLayout;
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

