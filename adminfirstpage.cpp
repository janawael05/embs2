#include "adminfirstpage.h"
#include "ui_adminfirstpage.h"
#include "signinginforadmins.h"
#include "signingupforadmins.h"

adminlogin::adminlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminlogin)
{
    ui->setupUi(this);
}

adminlogin::~adminlogin()
{
    delete ui;
}
//1)the admin choose wheter they have an account or not, as each one of them has its own implementations.
//A)here what is chosen is that the admin has an account
void adminlogin::on_yesaccountadmin_clicked()
{
    // * hiding the current page of adminfirstpage class
    hide();
    // * making a pointer object points at the signinginforadmins class
    signinginforadmins * signinginforadmins = new class signinginforadmins(this);
    //* this is to view the login page of the admin
    signinginforadmins->show();
}
//B)here what is chosen that the admin does not have an account
void adminlogin::on_noaccountadmin_clicked()
{
    // *  hiding the current page of admingfirstpage class
    hide();
    // * making a pointer object points at the signingupforadmins class
    signingupforadmins * signingupforadmins = new class signingupforadmins(this);
    // * this is to view the signup page of the admin
    signingupforadmins->show();
}

