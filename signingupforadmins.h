#ifndef SIGNINGUPFORADMINS_H
#define SIGNINGUPFORADMINS_H

#include <QDialog>

namespace Ui {
class signingupforadmins;
}

class signingupforadmins : public QDialog
{
    Q_OBJECT

public:
    explicit signingupforadmins(QWidget *parent = nullptr);
    ~signingupforadmins();

private:
    Ui::signingupforadmins *ui;
};

#endif // SIGNINGUPFORADMINS_H
