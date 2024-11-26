#ifndef BOOKINGHISTORY_H
#define BOOKINGHISTORY_H

#include <QWidget>  // Ensure this is included
#include <QDialog>
#include <QTableWidget>

namespace Ui
{
    class BookingHistory;
}
class BookingHistory : public QWidget
{
    Q_OBJECT

public:
    explicit BookingHistory(QWidget *parent = nullptr);
    ~BookingHistory();

private:
    Ui::BookingHistory *ui;

    QTableWidget *historyTable;

    void loadBookingHistory();
};

#endif // BOOKINGHISTORY_H
