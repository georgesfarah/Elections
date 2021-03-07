#ifndef ELECTIONWINDOW_H
#define ELECTIONWINDOW_H

#include <QDialog>
#include <vector>
#include <string>

#include "candidat.h"
#include "electeur.h"

namespace Ui {
class electionWindow;
}

class electionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit electionWindow(const std::vector<std::vector<std::string>> & langs,candidat& candidats,electeur& electeurs,int active,std::string id,QWidget *parent = nullptr);
    ~electionWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::electionWindow *ui;
    candidat& candidats;
    electeur& electeurs;
    std::string id;
};

#endif // ELECTIONWINDOW_H
