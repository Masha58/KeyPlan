#include "containerProjet.h"

ContainerProjet::ContainerProjet(int whatsthis):vboxLayout(QVBoxLayout(&scrollAreaWidgetContents))
{
	QString ssheet_back = "border:none; background:none; background-color:none;";
	QString ssheet_scroll = "QScrollBar::handle:vertical{background-color: red;min-height:5px;border-radius: 4px;}"
		"QScrollArea{background-color:none; border:none; background:none;}";

	scrollAreaWidgetContents.setStyleSheet(ssheet_back);
	scrollAreaWidgetContents.setWhatsThis(QString::number(whatsthis));

	vboxLayout.setSpacing(8);
	vboxLayout.setContentsMargins(4, 4, 4, 4);

	setAcceptDrops(true);
	setWidgetResizable(true);
	setStyleSheet(ssheet_scroll);
	setWidget(&scrollAreaWidgetContents);
	setSizeAdjustPolicy(AdjustToContents);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

ContainerProjet::~ContainerProjet() = default;


void ContainerProjet::dropEvent(QDropEvent* event)
{
	/*if (event->source()->parent() == &scrollAreaWidgetContents)
	{
		emit event->source().mouseReleaseEvent();
	}
	else
	{*/
		vboxLayout.addWidget(qobject_cast<QWidget*>(event->source()));
	//}
}
	


void ContainerProjet::dragEnterEvent(QDragEnterEvent* event)
{
	event->accept();
}

