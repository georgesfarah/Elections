#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <vector>
#include <string>

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(const std::vector<std::vector<std::string>> & langs,int active=0,QWidget *parent = nullptr);
    ~about();

private:
    Ui::about *ui;
};

#endif // ABOUT_H
