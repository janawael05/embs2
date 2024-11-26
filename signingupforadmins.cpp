#include "signingupforadmins.h"
#include "ui_signingupforadmins.h"

signingupforadmins::signingupforadmins(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signingupforadmins)
{
    ui->setupUi(this);
}

signingupforadmins::~signingupforadmins()
{
    delete ui;
}
