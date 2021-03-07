#ifndef TUTO_H
#define TUTO_H

#include <QDialog>
#include <vector>
#include <string>

namespace Ui {
class tuto;
}

class tuto : public QDialog
{
    Q_OBJECT

public:
    explicit tuto(const std::vector<std::vector<std::string>> & langs,int active=0,QWidget *parent = nullptr);
    ~tuto();

private:
    Ui::tuto *ui;
};

#endif // TUTO_H
