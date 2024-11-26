#include "listofbooks.h"
#include "ui_listofbooks.h"
#include "newaddedbooks.h"
#include "mainwindow.h"
#include "adminfirstpage.h"

listofbooks::listofbooks(QWidget *parent)
    : QDialog(parent), ui(new Ui::listofbooks)
{
    ui->setupUi(this);
    listofbooks *bookListWindow = new listofbooks(this);  // Create an instance of the listofbooks class
    // bookListWindow->addBook(newbook);    // Add the new book to the list
}

listofbooks::~listofbooks()
{
    delete ui;
}

void listofbooks::addBook(const QString &bookName)
{
    ui->listWidget->addItem(bookName);  // Add the new book to the list widget
}
