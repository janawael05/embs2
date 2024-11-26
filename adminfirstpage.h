#ifndef ADMINFIRSTPAGE_H
#define ADMINFIRSTPAGE_H

#include <QDialog>

namespace Ui {
class adminlogin;
}

class adminlogin : public QDialog
{
    Q_OBJECT

public:
    explicit adminlogin(QWidget *parent = nullptr);
    ~adminlogin();

private:
    Ui::adminlogin *ui;
private slots:
    void on_yesaccountadmin_clicked();
    void on_noaccountadmin_clicked();
};

#endif // ADMINFIRSTPAGE_H
