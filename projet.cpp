#include "projet.h"

const QString color_app = "";
const QString color_plugin = "";
const QString color_task = "";

Projet::Projet(int statut, QString nom_projet, QString type_projet, QString nom_client, QString description) :
	statut(statut), nom_projet(nom_projet), type_projet(type_projet), nom_client(nom_client), description(description),
    lineEdit_titre(LineEdit(nom_projet, "black")), lineEdit_nom_client(LineEdit(nom_client, "rgb(90, 90, 90)"))
{
	ui.setupUi(this);

	if (type_projet == "Application")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(0, 188, 213);color:white;border-radius:3px;");
	else if(type_projet == "Task")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(253, 161, 21);color:white;border-radius:3px;");
	else if(type_projet == "Plugin")
		ui.la_tag_projet->setStyleSheet("background-color: rgb(84, 229, 154);color:white;border-radius:3px;");
		
	ui.la_tag_projet->setText(type_projet);
    ui.te_description->setText(description);
    ui.hl_nom_client->addWidget(&lineEdit_nom_client);
    ui.vl_titre->addWidget(&lineEdit_titre);
    ui.fr_annexe->setVisible(false);
    ui.fr_projet->setMaximumSize(500, 120);

    LineEdit::connect(&lineEdit_titre, SIGNAL(editingFinished()), this, SLOT(maj_titre()));
    LineEdit::connect(&lineEdit_nom_client, SIGNAL(editingFinished()), this, SLOT(maj_nomclient()));
    QTextEdit::connect(ui.te_description, SIGNAL(textChanged()), this, SLOT(maj_description()));

    QPushButton::connect(ui.b_plus, &QPushButton::clicked, this, [this]() { ajouter_job("New Job", 0); });
    QPushButton::connect(ui.b_moins, SIGNAL(clicked()), this,SLOT(supprimer_job()));
    QListWidget::connect(ui.lw_jobs, SIGNAL(itemChanged(QListWidgetItem*)), this, SLOT(maj_job(QListWidgetItem*)));
}

void Projet::maj_titre()
{
    QSqlQuery query;
    query.prepare("UPDATE PROJETS SET nom_projet = :newNomp WHERE nom_projet = :nomp and nom_client = :nomc and type_projet = :typep");
    query.bindValue(":nomp", nom_projet);
    query.bindValue(":nomc", nom_client);
    query.bindValue(":typep", type_projet);
    query.bindValue(":newNomp", lineEdit_titre.text());

    if (!query.exec())
        qWarning() << "Error maj_titre: " << query.lastError().text();
    
    nom_projet = lineEdit_titre.text();
}

void Projet::maj_nomclient()
{
    QSqlQuery query;
    query.prepare("UPDATE PROJETS SET nom_client = :nomc WHERE nom_projet = :nomp");
    query.bindValue(":nomp", nom_projet);
    query.bindValue(":nomc", lineEdit_nom_client.text());

    if (!query.exec())
        qWarning() << "Error maj_nomclient : " << query.lastError().text();

    nom_client = lineEdit_nom_client.text();
}

void Projet::maj_description()
{
    QSqlQuery query;
    query.prepare("UPDATE PROJETS SET description = :description WHERE nom_projet = :nomp");
    query.bindValue(":nomp", nom_projet);
    query.bindValue(":description", ui.te_description->toPlainText());

    if (!query.exec())
        qWarning() << "Error maj_description : " << query.lastError().text();

    description = ui.te_description->toPlainText();
}

void Projet::maj_nb_job()
{
    int completed_job = 0;
    for (int i = 0; i < ui.lw_jobs->count(); i++)
    {
        if (ui.lw_jobs->item(i)->checkState() == Qt::Checked)
        {
            completed_job++;
        }
    }
    ui.la_nb_jobs->setText(QString::number(completed_job) + "/" + QString::number(ui.lw_jobs->count()));
}

void Projet::maj_job(QListWidgetItem* item)
{
    maj_nb_job();
    
    QString currentText = item->text();

    // on vérifie si le job que l'on veut ajouter n'existe pas déjà
    int estPresent = 0;
    int index = 0;
    for (int i = 0; i < ui.lw_jobs->count(); i++)
    {
        if (ui.lw_jobs->item(i)->text() == currentText)
        {
            estPresent++;
            index = i;
        }
    }

    if (estPresent > 1)
    {
        ui.la_infos->setText("Job already exists");
    }
    else
    {
        ui.la_infos->setText("");
        // on récupère l'id du projet associé au job nouvellement créé
        int idprojet = 0;
        QSqlQuery query;
        query.prepare("SELECT id_projet FROM PROJETS where nom_projet = :nomp");
        query.bindValue(":nomp", nom_projet);

        if (!query.exec())
            qWarning() << "maj_job 1er : " << query.lastError().text();

        while (query.next())
        {
            idprojet = query.value(0).toInt();
        }

        if (index >= list_job.size())
        {
            // on insère le nouveau job
            query.prepare("INSERT INTO JOBS(id_projet, nom_job, job_fait) VALUES(:id, :nomj, 0)");
            query.bindValue(":id", idprojet);
            query.bindValue(":nomj", currentText);
            if (!query.exec())
                qWarning() << "Error maj_job : " << query.lastError().text();
        }
        else
        {
            int fait = ui.lw_jobs->item(index)->checkState() == Qt::Checked ? 1: 0;

            // on maj le job
            query.prepare("UPDATE JOBS SET nom_job = :newj, job_fait = :fait WHERE id_projet = :id_projet and nom_job = :altj");
            query.bindValue(":newj", currentText );
            query.bindValue(":id_projet", idprojet);
            query.bindValue(":altj", list_job[index]);
            query.bindValue(":fait", fait);
            if (!query.exec())
                qWarning() << "Error maj_job bis : " << query.lastError().text();
            
        }
        list_job[index] = currentText;
    }
}


void Projet::ajouter_job(QString nom, int fait)
{
    ajouter_listWidgetItem(nom, fait);

    // on vérifie si le job que l'on veut ajouter n'existe pas déjà
    int estPresent = 0;
    for (int i = 0; i < ui.lw_jobs->count(); i++)
    {
        if (ui.lw_jobs->item(i)->text() == nom)
        {
            estPresent ++;
        }
    }

    if (estPresent > 1)
    {
        ui.la_infos->setText("Job already exists");
    }
    else
    {
        ui.la_infos->setText("");
        // on récupère l'id du projet associé au job nouvellement créé
        int idprojet = 0;
        QSqlQuery query;
        query.prepare("SELECT id_projet FROM PROJETS where nom_projet = :nomp");
        query.bindValue(":nomp", nom_projet);

        if (!query.exec())
            qWarning() << "ajouter_job : " << query.lastError().text();

        while (query.next())
        {
            idprojet = query.value(0).toInt();
        }

        // on insère le nouveau job
        query.prepare("INSERT INTO JOBS(id_projet, nom_job, job_fait) VALUES(:id, :nomj, :jobF)");
        query.bindValue(":id", idprojet);
        query.bindValue(":nomj", nom);
        query.bindValue(":jobF", fait);

        if (!query.exec())
            qWarning() << "Error ajouter_job bis : " << query.lastError().text();
        maj_nb_job();
    }
}

void Projet::supprimer_job()
{
    if (ui.lw_jobs->currentItem() != nullptr)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM JOBS WHERE id_projet = :id AND nom_job = :nomj");
        query.bindValue(":id", getIdProjet());
        query.bindValue(":nomj", ui.lw_jobs->currentItem()->text());

        if (!query.exec())
            qWarning() << "Error supprimer_job : " << query.lastError().text();

        list_job.erase(remove(list_job.begin(), list_job.end(), ui.lw_jobs->currentItem()->text()), list_job.end());

        delete ui.lw_jobs->takeItem(ui.lw_jobs->row(ui.lw_jobs->currentItem()));
        maj_nb_job();
    }
}

void Projet::ajouter_listWidgetItem(QString nom, int fait)
{
    auto* listWidgetItem = new  QListWidgetItem(nom);
    fait == 1 ? listWidgetItem->setCheckState(Qt::Checked) : listWidgetItem->setCheckState(Qt::Unchecked);
    listWidgetItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    ui.lw_jobs->addItem(listWidgetItem);
    list_job.push_back(nom);
}

Projet::~Projet() = default;

int Projet::getIdProjet()
{
    int id = 0;

    QSqlQuery query;
    query.prepare("SELECT id_projet FROM PROJETS WHERE nom_projet = :nomp");
    query.bindValue(":nomp", nom_projet);

    if (!query.exec())
        qWarning() << "getIdProjet" << query.lastError().text();

    while (query.next())
    {
        id = query.value(0).toInt();
    }

    return id;
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

bool Projet::IsMinimumDistanceRiched(const QMouseEvent* event) const
{
    return (event->pos() - dragStartPosition).manhattanLength() >= QApplication::startDragDistance();
}

bool Projet::moveInLayout(QWidget* widget, MoveDirection direction) const
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
