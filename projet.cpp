#include "projet.h"
#include <QComboBox>

QString color_app = "";
QString color_plugin = "";
QString color_task = "";

Projet::Projet()
{
    ui.setupUi(this);
    
    commentaire = "";

    statut = 0;
    type_projet = "Undefined";
    nom_projet = "New Project";
    nom_client = "Nom client";
    description = "";
    commentaire = "";

    lineEdit_titre = new LineEdit(nom_projet, "black");
    lineEdit_nom_client = new LineEdit(nom_client, "rgb(90, 90, 90)");

    ui.la_tag_projet->setText(type_projet);

    ui.vl_titre->addWidget(lineEdit_titre);
    ui.hl_nom_client->addWidget(lineEdit_nom_client);
}

Projet::Projet(int statut, QString type_projet, QString nom_projet, QString nom_client, QString description) :
	statut(statut),type_projet(type_projet), nom_projet(nom_projet), nom_client(nom_client), description(description)
{
	ui.setupUi(this);
	commentaire = "";

	if (type_projet == "Application")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(0, 188, 213);color:white;border-radius:3px;");
	else if(type_projet == "Task")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(253, 161, 21);color:white;border-radius:3px;");
	else if(type_projet == "Plugin")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(84, 229, 154);color:white;border-radius:3px;");
		
	ui.la_tag_projet->setText(type_projet);


    lineEdit_titre = new LineEdit(nom_projet, "black");
    lineEdit_nom_client = new LineEdit(nom_client, "rgb(90, 90, 90)");
    ui.hl_nom_client->addWidget(lineEdit_nom_client);
    ui.vl_titre->addWidget(lineEdit_titre);

}

Projet::~Projet()
{
    delete mimeData;
    delete lineEdit_titre;
}

void Projet::mouseMoveEvent(QMouseEvent* event)
{

    mimeData = new QMimeData();
    QPixmap dragPixmap = grab();

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(dragPixmap);
    drag->setHotSpot(event->pos());

    drag->exec(Qt::MoveAction);
}

void Projet::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
        dragStartPosition = event->pos();
    oldX = geometry().x();
    oldY = geometry().y();
    mouseClickX = event->globalX();
    mouseClickY = event->globalY();
}

bool Projet::IsMinimumDistanceRiched(QMouseEvent* event)
{
    return (event->pos() - dragStartPosition).manhattanLength() >= QApplication::startDragDistance();
}

bool Projet::moveInLayout(QWidget* widget, MoveDirection direction)
{
    QVBoxLayout* myLayout = qobject_cast<QVBoxLayout*>(widget->parentWidget()->layout());

    if (!widget)
    {
        return false;
    }
    const int index = myLayout->indexOf(widget);
    if (direction == MoveUp && index == 0)
    {
        return false;
    }
    if (direction == MoveDown && index == myLayout->count() - 1)
    {
        return false;
    }
    const int newIndex = direction == MoveUp ? index - 1 : index + 1;

    myLayout->removeWidget(widget);
    myLayout->insertWidget(newIndex, widget);
    return true;
}

void Projet::paintEvent(QPaintEvent*)
{
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void Projet::mouseReleaseEvent(QMouseEvent*)
{
    int y = geometry().y();
    MoveDirection direct;
    int offset = 0;
    if (oldY > y)
    {
        offset = oldY - y;
        direct = MoveUp;
    }
    else if (oldY < y)
    {
        offset = y - oldY;
        direct = MoveDown;
    }
    int count = offset / height();
    for (int i = 0; i < count; i++)
    {
        moveInLayout(this, direct);
    }
    update();
    QVBoxLayout* myLayout = qobject_cast<QVBoxLayout*>(this->parentWidget()->layout());
    myLayout->update();
    this->saveGeometry();
}
