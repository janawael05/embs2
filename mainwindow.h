#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <map>
using namespace std;

namespace Ui {
class mainwindow;
}

class mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
    map<QString , QString>username_and_passowrduser;
    map<QString , QString>username_and_passowrdadmin;
    int performance = 0;

private slots:
    void on_adminpushbutton_clicked();

    void on_userpushbutton_clicked();

private:
    Ui::mainwindow *ui;

};

#endif // MAINWINDOW_H
