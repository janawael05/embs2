#include "BookingConfirmation.h"
#include "ui_BookingConfirmation.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "EventBrowsingandBooking.h"

BookingConfirmation::BookingConfirmation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookingConfirmation)
{
    ui->setupUi(this);
}

BookingConfirmation::~BookingConfirmation()
{
    delete ui;
}

void BookingConfirmation::setBookingDetails(const QString &eventName, const QString &eventDate, const QString &eventLocation) {

    ui->EventNameLabel->setText(eventName);
    ui->DateLabel->setText(eventDate);
    ui->LocationLabel->setText(eventLocation);
}
void BookingConfirmation::confirmBooking() {

    QString eventName = ui->EventNameLabel->text();
    QString eventDate = ui->DateLabel->text();
    QString eventLocation = ui->LocationLabel->text();
    int numberOfSeats = ui->numberoftickets->text().toInt();

    // Open the booking records file and append the booking
    QFile file("C:\\Users\\hemac\\OneDrive\\Desktop\\booking.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to save booking record.");
        return;
    }

    QTextStream out(&file);
    out << eventName << "," << eventDate << "," << eventLocation << "," << numberOfSeats << "\n";
    file.close();

    QMessageBox::information(this, "Booking Confirmed", "Your booking has been saved!");

    this->close();
}
void BookingConfirmation::on_confirmBookingButton_clicked()
{

    confirmBooking();
    performance++;
}




