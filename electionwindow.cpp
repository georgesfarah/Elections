#include "electionwindow.h"
#include "ui_electionwindow.h"

#include "candidat.h"
#include "electeur.h"
#include <QFile>
#include <QTextStream>
#include <QTextStream>
#include <QRadioButton>
#include <QList>
#include <QMessageBox>

#include <iostream>

QList<QRadioButton *> allRButtons;

electionWindow::electionWindow(const std::vector<std::vector<std::string>> & langs,candidat& candidats,electeur& electeurs,int active,std::string id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::electionWindow),candidats(candidats),electeurs(electeurs),id(id)
{
    ui->setupUi(this);

    ui->label->setText(QString::fromStdString(langs[active][14]));
    ui->pushButton->setText(QString::fromStdString(langs[active][15]));

    std::vector<std::string> voterName=candidats.getName();

    for(auto elm:voterName){
        QString qstr1 = QString::fromStdString(elm);
        QRadioButton *Rbtn =new QRadioButton(qstr1, this);
        ui->gridLayout_3->addWidget(Rbtn);
        allRButtons.push_back(Rbtn);
    }

}

electionWindow::~electionWindow()
{
    for(auto elm:allRButtons){delete elm;}
    allRButtons.clear();

    delete ui;
}

void electionWindow::on_pushButton_clicked() //permet de savoir quel boutton a ete choisi
{
    bool isCheck(false);

    QMessageBox::StandardButton reply=QMessageBox::question(this,"Confirmer","Etes-vous sur de vouloir continuer ? ",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::No){return;}

    std::vector<std::string> candidatsId=candidats.getId();
    for(int i=0;i<allRButtons.size();++i){
        if(allRButtons[i]->isChecked()){

           std::string candidatId=candidatsId[i];

           candidats.addVote(candidatId);
           candidats.saveConfigs();

           electeurs.setVoted(id);
           electeurs.saveConfigs();

           this->close();
           isCheck = true;

        }
    }
    if (isCheck == false)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Veuillez sélectionner un candidat !");
        messageBox.setFixedSize(500,200);
    }
}
