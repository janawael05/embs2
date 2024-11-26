#ifndef STUDENTFIRSTPAGE_H
#define STUDENTFIRSTPAGE_H

#include <QDialog>

namespace Ui {
class studentlogin;
}

class studentlogin : public QDialog
{
    Q_OBJECT

public:
    explicit studentlogin(QWidget *parent = nullptr);
    ~studentlogin();

private:
    Ui::studentlogin *ui;
     QString m_username; // To store the username

private slots:
    void on_yesaccountstudent_clicked();
    void on_noaccountstudent_clicked();

};

#endif // STUDENTFIRSTPAGE_H
