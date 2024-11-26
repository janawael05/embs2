#include "signinginforstrudents.h"
#include "ui_signinginforstrudents.h"

signinginforstrudents::signinginforstrudents(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signinginforstrudents)
{
    ui->setupUi(this);
}

signinginforstrudents::~signinginforstrudents()
{
    delete ui;
}
