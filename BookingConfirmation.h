#ifndef BOOKINGCONFIRMATION_H
#define BOOKINGCONFIRMATION_H


#include <QDialog>


namespace Ui {
class BookingConfirmation;
}

class BookingConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit BookingConfirmation(QWidget *parent = nullptr);
    ~BookingConfirmation();

    void setBookingDetails(const QString &eventName, const QString &eventDate, const QString &eventLocation);
    void confirmBooking();
    int performance = 0;

private slots:
    void on_confirmBookingButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::BookingConfirmation *ui;
};

#endif // BOOKINGCONFIRMATION_H
