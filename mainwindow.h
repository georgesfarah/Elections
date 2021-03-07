#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<vector>
#include<string>

#include "candidat.h"
#include "electeur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(candidat& candidats,electeur& electeurs,const std::vector<std::vector<std::string>> & langs,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_pass_returnPressed();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    candidat& candidats;
    electeur& electeurs;

    const std::vector<std::vector<std::string>> & langs;
};
#endif // MAINWINDOW_H
