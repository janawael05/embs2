#include "mainwindow.h"
#include "User.h"
#include "ui_mainwindow.h"
#include "loginforuser.h"
#include "loginforadmins.h"
int performance = 0;

mainwindow::mainwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    username_and_passowrduser.insert({"Ahmed", "1234"});
    username_and_passowrduser["Jana"] = "2345";
    username_and_passowrduser["Noor"] = "3456";
    username_and_passowrdadmin.insert({"Ali", "1234"});
    username_and_passowrdadmin["Ibrahim"] = "2345";
    username_and_passowrdadmin["Youssef"] = "3456";
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_adminpushbutton_clicked()
{
    hide();
    loginforadmins* login1 = new class loginforadmins(username_and_passowrdadmin, this);
    login1->show();

}


void mainwindow::on_userpushbutton_clicked()
{
    hide();
    login *login =  new class login(username_and_passowrduser,this);
    login->show();
}

