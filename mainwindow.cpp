#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "adminwindow.h"
#include "electionwindow.h"
#include "electeur.h"
#include "candidat.h"
#include "about.h"
#include "tuto.h"

#include <QMessageBox>

#include <vector>
#include<string>


MainWindow::MainWindow(candidat& candidats,electeur& electeurs,const std::vector<std::vector<std::string>> & langs,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),candidats(candidats),electeurs(electeurs),langs(langs)
{
    ui->setupUi(this);

    for(auto & elm:langs){QString qstr=QString::fromStdString(elm[0]);ui->comboBox->addItem(qstr);}
    on_comboBox_currentIndexChanged(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString user=ui->lineEdit_user->text();
    QString pass=ui->lineEdit_pass->text();
    int i=ui->comboBox->currentIndex();

    if(user=="admin" && pass=="admin"){adminWindow a(langs,candidats,electeurs,i);a.exec();}
    else if(user=="electeur"){

        std::vector<std::string> motsDePasse=electeurs.getPass();
        std::vector<std::string> userCanVote=electeurs.getCanVote();
        std::vector<std::string> userId=electeurs.getId();

        std::string passIsValid="-1";
        for(size_t i=0;i<motsDePasse.size();++i){
            if(motsDePasse[i]==pass.toStdString() && userCanVote[i]=="0"){passIsValid=userId[i];}
        }

        if(passIsValid!="-1"){electionWindow a(langs,candidats,electeurs,i,passIsValid,this);a.exec();}
        else{
            QMessageBox messageBox;
            messageBox.critical(0,"Erreur","Mauvais paramètres de connexion");
            messageBox.setFixedSize(500,200);
        }
    }
    else{
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Mauvais paramètres de connexion");
        messageBox.setFixedSize(500,200);
    }

    ui->lineEdit_user->setText("electeur");
    ui->lineEdit_pass->clear();


}

void MainWindow::on_lineEdit_pass_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::on_pushButton_2_clicked()
{
    int i=ui->comboBox->currentIndex();
    about a(langs,i);
    a.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    int i=ui->comboBox->currentIndex();
    tuto a(langs,i);
    a.exec();
}

void MainWindow::on_comboBox_currentIndexChanged(int active)
{
    ui->label->setText(QString::fromStdString(langs[active][1]));
    ui->label_2->setText(QString::fromStdString(langs[active][2]));
    ui->label_3->setText(QString::fromStdString(langs[active][3]));
    ui->pushButton->setText(QString::fromStdString(langs[active][4]));
    ui->pushButton_3->setText(QString::fromStdString(langs[active][5]));
    ui->pushButton_2->setText(QString::fromStdString(langs[active][6]));

}
