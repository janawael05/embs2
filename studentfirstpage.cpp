#include "studentfirstpage.h"
#include "ui_studentfirstpage.h"
#include "signinginforstrudents.h"
#include "signingupforstudents.h"

studentlogin::studentlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentlogin)
{
    ui->setupUi(this);
}

studentlogin::~studentlogin()
{
    delete ui;
}
//1)the student choose wheter they have account or not, as each one of them has its own implementations.
//A)here what is chosen is that the student has an account
void studentlogin::on_yesaccountstudent_clicked()
{
    // * hiding the current page of studentfirstpage class
    hide();
    // * making a pointer object points at the class signinginforstrudents to use its functions
    signinginforstrudents * signinginforstrudents = new class signinginforstrudents(this);
    // * this is to view the login page of the student
    signinginforstrudents->show();
}
//B)here what is chosen is that the student does not have an account
void studentlogin::on_noaccountstudent_clicked()
{
    // * hiding the current page of studentfirstpage class
    hide();
    // * making a pointer object points at the class signingupforstrudents to use its functions
    signingupforstudents * signingupforstudents = new class signingupforstudents(this);
    // * this is to view the signup page of the student
    signingupforstudents->show();
}

