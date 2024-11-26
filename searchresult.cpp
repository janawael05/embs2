#include "searchresult.h"
#include "ui_searchresult.h"
#include "Event.h"
#include <vector>
#include <iostream>
using namespace std;
searchresult::searchresult(vector<Event>vec,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::searchresult)
{
    ui->setupUi(this);


searchresult::~searchresult()
{
    delete ui;
}



