#include "tuto.h"
#include "ui_tuto.h"

tuto::tuto(const std::vector<std::vector<std::string>> & langs,int active,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tuto)
{
    ui->setupUi(this);

    ui->label->setText(QString::fromStdString(langs[active][18]));
    ui->label_3->setText(QString::fromStdString(langs[active][19]));
    ui->label_4->setText(QString::fromStdString(langs[active][21]));
    ui->label_5->setText(QString::fromStdString(langs[active][22]));
    ui->label_6->setText(QString::fromStdString(langs[active][23]));
    ui->label_2->setText(QString::fromStdString(langs[active][24]));
    ui->label_7->setText(QString::fromStdString(langs[active][25]));
}

tuto::~tuto()
{
    delete ui;
}
