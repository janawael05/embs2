#ifndef NEWADDEDBOOKS_H
#define NEWADDEDBOOKS_H

#include <QDialog>

namespace Ui {
class newaddedbooks;
}

class newaddedbooks : public QDialog
{
    Q_OBJECT

public:
    explicit newaddedbooks(QWidget *parent = nullptr);
    ~newaddedbooks();

private slots:
    void on_addedbook_clicked();

    void on_returnbacktoyourlist_clicked();

private:
    Ui::newaddedbooks *ui;
};

#endif // NEWADDEDBOOKS_H
