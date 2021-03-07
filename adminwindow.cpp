#include "adminwindow.h"
#include "ui_adminwindow.h"

#include <vector>
#include <string>
#include <QString>

#include <QFile>
#include <QTextStream>
#include <QTextStream>
#include <QMessageBox>

#include "candidat.h"
#include "electeur.h"
using namespace std;

vector<QLabel*> layout4;
vector<QLabel*> layout5;

adminWindow::adminWindow(const std::vector<std::vector<std::string>> & langs,candidat& candidats,electeur& electeurs,int active,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminWindow),candidats(candidats),electeurs(electeurs)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window);

    ui->label_3->setText(QString::fromStdString(langs[active][12]));
    ui->label_4->setText(QString::fromStdString(langs[active][13]));
    ui->pushButton->setText(QString::fromStdString(langs[active][26]));


}

adminWindow::~adminWindow()
{
    for(auto elm:layout4){delete elm;}
    for(auto elm:layout5){delete elm;}
    layout4.clear();
    layout5.clear();

    delete ui;
}

void adminWindow::on_pushButton_clicked()
{
     QString candidatsNames=ui->lineEdit_candidats->text();
     QString nombreElecteurs=ui->spinBox_candidats->text();

     if (candidatsNames == "")  //check if all fields are filled correctly
     {

         QMessageBox messageBox;
         messageBox.critical(0,"Erreur","La plage de candidats ne peut pas être vide !");
         messageBox.setFixedSize(500,200);
         return;
     }

     if ( nombreElecteurs.toInt() <= 0 )
     {
         QMessageBox messageBox;
         messageBox.critical(0,"Erreur","Le nombre d’électeurs doit être positif !");
         messageBox.setFixedSize(500,200);
         return;
     }


     QMessageBox::StandardButton reply=QMessageBox::question(this,"Confirmer","Tous paramètres enregistrés seront écrasés ! \nVoulez-vous continuer ?",QMessageBox::Yes|QMessageBox::No);
     if(reply==QMessageBox::No){return;}




     vector<string> candidatsVector({});
    for(auto elm:candidatsNames.split(",")){
        candidatsVector.push_back(elm.toStdString());
    }
    candidatsVector.push_back("Vote Blanc");

    candidats.updateConfigs(candidatsVector);
    candidats.saveConfigs();

     electeurs.updateConfigs(nombreElecteurs.toInt());
     electeurs.saveConfigs();



     QMessageBox msgBox;
     msgBox.setWindowTitle("Succès");
     msgBox.setText("Paramètres enregistrés !");
     msgBox.exec();



}

void adminWindow::on_tabWidget_tabBarClicked(int index) // cette methode permet la mise a jour des onglets
{
 if(index==2){//update electeur

     for(auto elm:layout5){delete elm;}
     layout5.clear();

     vector<string> electeurId=electeurs.getId();
     vector<string> electeurPass=electeurs.getPass();
     vector<string> electeurCanVote=electeurs.getCanVote();

     for(size_t i=0;i<electeurId.size();++i) {
         QString qstr1 = QString::fromStdString(electeurId[i]);
         QString qstr2 = QString::fromStdString(electeurPass[i]);
         QString qstr3;
         if(electeurCanVote[i]=="0"){qstr3="Yes";}
         else{qstr3="No";}

         QLabel* qlabel1=new QLabel("id: "+qstr1, this);
         QLabel* qlabel2=new QLabel("password: "+qstr2, this);
         QLabel* qlabel3=new QLabel("canVote: "+qstr3, this);

         qlabel2->setTextInteractionFlags(Qt::TextSelectableByMouse);

         ui->gridLayout_5->addWidget(qlabel1);
         ui->gridLayout_5->addWidget(qlabel2);
         ui->gridLayout_5->addWidget(qlabel3);

         layout5.push_back(qlabel1);
         layout5.push_back(qlabel2);
         layout5.push_back(qlabel3);
     }

 }
 if(index==1){

     for(auto elm:layout4){delete elm;}
     layout4.clear();

     vector<string> voterId=candidats.getId();
     vector<string> voterName=candidats.getName();
     vector<string> voterVotes=candidats.getVotes();

     for(size_t i=0;i<voterId.size();++i) {
         QString qstr1 = QString::fromStdString(voterId[i]);
         QString qstr2 = QString::fromStdString(voterName[i]);
         QString qstr3 = QString::fromStdString(voterVotes[i]);

         QLabel* qlabel1=new QLabel("id: "+qstr1, this);
         QLabel* qlabel2=new QLabel("name: "+qstr2, this);
         QLabel* qlabel3=new QLabel("votes: "+qstr3, this);

         ui->gridLayout_4->addWidget(qlabel1);
         ui->gridLayout_4->addWidget(qlabel2);
         ui->gridLayout_4->addWidget(qlabel3);

         layout4.push_back(qlabel1);
         layout4.push_back(qlabel2);
         layout4.push_back(qlabel3);

     }

 }

}
