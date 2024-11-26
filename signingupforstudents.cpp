#include "signingupforstudents.h"
#include "ui_signingupforstudents.h"

signingupforstudents::signingupforstudents(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signingupforstudents)
{
    ui->setupUi(this);
}

signingupforstudents::~signingupforstudents()
{
    delete ui;
}
