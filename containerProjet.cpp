#include "containerProjet.h"

ContainerProjet::ContainerProjet(int whatsthis): vboxLayout(QVBoxLayout(&scrollAreaWidgetContents))
{
	QString ssheet_back = "border:none; background:none; background-color:none;";
	QString ssheet_scroll = "QScrollBar::handle:vertical{background-color: rgb(220,220,220);width:3px; height:3px;border-radius: 4px;}"
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
	vboxLayout.addWidget(qobject_cast<QWidget*>(event->source()));

	qobject_cast<Projet*>(event->source())->setStatut(scrollAreaWidgetContents.whatsThis().toInt());

	// MAJ BDD
	QSqlQuery query;
	query.prepare("UPDATE PROJETS SET statut = :newStatut WHERE nom_projet = :nomp");
	query.bindValue(":nomp", qobject_cast<Projet*>(event->source())->getNom_projet());
	query.bindValue(":newStatut", scrollAreaWidgetContents.whatsThis().toInt());

	if (!query.exec())
		qWarning() << "Error dropEvent : " << query.lastError().text();
	
}
	


void ContainerProjet::dragEnterEvent(QDragEnterEvent* event)
{
	event->accept();
}

