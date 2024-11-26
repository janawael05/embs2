#ifndef LISTOFBOOKS_H
#define LISTOFBOOKS_H

#include <QDialog>

namespace Ui {
class listofbooks;
}

class listofbooks : public QDialog
{
    Q_OBJECT

public:
    explicit listofbooks(QWidget *parent = nullptr);
    ~listofbooks();


private:
    Ui::listofbooks *ui;
public slots:
    void addBook(const QString &bookName);
};

#endif // LISTOFBOOKS_H
