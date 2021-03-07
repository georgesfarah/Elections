#include "about.h"
#include "ui_about.h"

about::about(const std::vector<std::vector<std::string>> & langs,int active,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    ui->label->setText(QString::fromStdString(langs[active][7]));
    ui->label_2->setText(QString::fromStdString(langs[active][8]));

}

about::~about()
{
    delete ui;
}
