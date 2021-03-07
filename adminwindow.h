#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <vector>
#include <string>

#include "candidat.h"
#include "electeur.h"

namespace Ui {
class adminWindow;
}

class adminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminWindow(const std::vector<std::vector<std::string>> & langs,candidat& candidats,electeur& electeurs,int active=0,QWidget *parent = nullptr);
    ~adminWindow();

private slots:
    void on_pushButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::adminWindow *ui;
    candidat& candidats;
    electeur& electeurs;
};

#endif // ADMINWINDOW_H
