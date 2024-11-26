#ifndef SIGNINGINFORADMINS_H
#define SIGNINGINFORADMINS_H

#include <QDialog>

namespace Ui {
class signinginforadmins;
}

class signinginforadmins : public QDialog
{
    Q_OBJECT

public:
    explicit signinginforadmins(QWidget *parent = nullptr);
    ~signinginforadmins();

private slots:
    void on_pushButton_clicked();

    void on_showlistofbooks_clicked();

    void on_addbooks_clicked();

private:
    Ui::signinginforadmins *ui;
};

#endif // SIGNINGINFORADMINS_H
