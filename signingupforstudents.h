#ifndef SIGNINGUPFORSTUDENTS_H
#define SIGNINGUPFORSTUDENTS_H

#include <QDialog>

namespace Ui {
class signingupforstudents;
}

class signingupforstudents : public QDialog
{
    Q_OBJECT

public:
    explicit signingupforstudents(QWidget *parent = nullptr);
    ~signingupforstudents();

private:
    Ui::signingupforstudents *ui;
};

#endif // SIGNINGUPFORSTUDENTS_H
