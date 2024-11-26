#include "newaddedbooks.h"
#include "ui_newaddedbooks.h"
#include "signinginforadmins.h"

newaddedbooks::newaddedbooks(QWidget *parent)
    : QDialog(parent), ui(new Ui::newaddedbooks)
{
    ui->setupUi(this);
    QString newbook = ui->addyourbook->text();  // Get the new book title


}

newaddedbooks::~newaddedbooks()
{
    delete ui;
}

void newaddedbooks::on_returnbacktoyourlist_clicked()
{
    hide();
    signinginforadmins *signin = new signinginforadmins(this);
    signin->show();
}
