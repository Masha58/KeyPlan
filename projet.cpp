#include "projet.h"
#include <QComboBox>

Projet::Projet(int statut, QString type_projet, QString nom_projet, QString nom_client, QString description) :
	statut(statut),type_projet(type_projet), nom_projet(nom_projet), nom_client(nom_client), description(description)
{
	ui.setupUi(this);
	commentaire = "";

	if (type_projet == "logiciel")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(0, 188, 213);color:white;border-radius:3px;");
	else if(type_projet == "tache")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(253, 161, 21);color:white;border-radius:3px;");
	else if(type_projet == "plugin")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(84, 229, 154);color:white;border-radius:3px;");
		
	ui.la_titre_projet->setText(nom_projet);
	ui.la_tag_projet->setText(type_projet);
	ui.la_nom_client->setText(nom_client);
    

}

Projet::~Projet()
{}

void Projet::mouseMoveEvent(QMouseEvent* event)
{

    QMimeData* mimeData = new QMimeData();
    QPixmap dragPixmap = grab();

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(dragPixmap);
    drag->setHotSpot(event->pos());

    //setParent(nan);

    //drag->exec(Qt::MoveAction);


    if (!(event->buttons() & Qt::LeftButton))
        return;
    if (!IsMinimumDistanceRiched(event))
    {
        return;
    }
    int y = event->globalY() - mouseClickY + oldY;
    int BottomBorder = parentWidget()->geometry().height() - this->geometry().height();
    if (y < 0) y = 0;
    else if (y > BottomBorder) y = BottomBorder;
    move(oldX, y);
}

void Projet::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
        dragStartPosition = event->pos();
    oldX = this->geometry().x();
    oldY = this->geometry().y();
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
