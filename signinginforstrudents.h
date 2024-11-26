#ifndef SIGNINGINFORSTRUDENTS_H
#define SIGNINGINFORSTRUDENTS_H

#include <QDialog>

namespace Ui {
class signinginforstrudents;
}

class signinginforstrudents : public QDialog
{
    Q_OBJECT

public:
    explicit signinginforstrudents(QWidget *parent = nullptr);
    ~signinginforstrudents();

private:
    Ui::signinginforstrudents *ui;
};

#endif // SIGNINGINFORSTRUDENTS_H
