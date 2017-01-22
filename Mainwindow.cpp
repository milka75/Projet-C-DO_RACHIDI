#include "Mainwindow.h"
#include "ui_Mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialiser la graine
    qsrand(QDateTime::currentDateTime().toTime_t());

    // Actions des bouttons
    connect(ui->pb_vote,SIGNAL(clicked(bool)),this,SLOT(slot_vote()));
    connect(ui->pb_results,SIGNAL(clicked(bool)),this,SLOT(slot_open_resultwindow()));

    // Gestion de la liste de candidat dans l'ui
    connect(ui->pb_addCandidat,SIGNAL(clicked(bool)),this,SLOT(slot_addCandidat()));
    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slot_editCandidat()));
    connect(ui->pb_removeCandidat,SIGNAL(clicked(bool)),this,SLOT(slot_removeCandidat()));

}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Slots
void MainWindow::slot_vote()
{
    // Recuperer les valeurs de l'utilisateur dans l'ui
    data.NVotes = ui->spinBox->value();
    data.NCandidats = ui->listWidget->count();

    // Vote : Remplir la liste des bulletins
    data.ListeBulletin.clear();
    for(int i=0; i<data.NVotes; i++)
    {
        Bulletin monBulletin;
        monBulletin.vote(data.NCandidats);
        data.ListeBulletin.append(monBulletin);
    }

    // Remplir la liste des candidats
    data.ListeCandidats.clear();
    data.ListeCandidats.resize(data.NCandidats);
    for(int i=0; i<data.NCandidats; i++)
        data.ListeCandidats[i].rename(ui->listWidget->item(i)->text());

    // Decompte des bulletins
    for(int i=0; i<data.NVotes; i++)
    {
        for(int j=0; j<data.NCandidats; j++)
        {
            data.ListeCandidats[j].addVote(data.ListeBulletin[i].ListeResultats()[j]-1);
        }
    }

    // Remplir le tableau dans l'ui
    QStandardItemModel *model =new QStandardItemModel(data.NCandidats, 7);
    for(int i=0; i<data.NCandidats; i++)
    {
        for(int j=0; j<7; j++)
        {
            QStandardItem *item = new QStandardItem;
            item->setText(QString::number(data.ListeCandidats[i].ListeResultats()[j]));
            model->setItem(i,j,item);
        }
    }

    // Remplir la liste des Noms des candidats
    data.ListeNoms.clear();
    for(int i=0; i<data.NCandidats; i++)
    {
        data.ListeNoms.append(data.ListeCandidats[i].nom());
    }

    // Affiche les noms des candidats dans le tableau
    model->setVerticalHeaderLabels(data.ListeNoms);

    ui->tableView->setModel(model);

    // Reamplir la liste des scores des candidats
    data.ListeScores.clear();
    data.ListeScores.resize(7);
    for(int j=0; j<7; j++)
    {
        for(int i=0; i<data.NCandidats; i++)
        {
            data.ListeScores[j].append(data.ListeCandidats[i].ListeResultats()[j]);
        }
    }

}

void MainWindow:: slot_open_resultwindow()
{
    // Ouvrir la fenetre des scores
    ResultWindow* resultwindow = new ResultWindow(this, &data);
    resultwindow->show();
}

void MainWindow:: slot_addCandidat()
{
    // Ajouter un candidat
    ui->listWidget->addItem("Nouveau");
    //int n = ui->listWidget->count();
    //ui->listWidget->item(n)->setFlags (ui->listWidget->item(n)->flags () | Qt::ItemIsEditable);
}

void MainWindow:: slot_editCandidat()
{
    // modifier le nom d'un candidat
    ui->listWidget->currentItem()->setFlags (ui->listWidget->currentItem()->flags () | Qt::ItemIsEditable);
    ui->listWidget->editItem(ui->listWidget->currentItem());
}

void MainWindow:: slot_removeCandidat()
{
    // Supprimer un candidat
    delete ui->listWidget->currentItem();
}

