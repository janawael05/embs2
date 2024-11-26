#include "BookingHistory.h"
#include "BookingConfirmation.h"
#include "ui_BookingHistory.h"
#include "BookingHistory.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHeaderView>
#include <iostream>
using namespace std;

BookingHistory::BookingHistory(QWidget *parent) : QWidget(parent), ui(new Ui::BookingHistory)
{
    // Set up the table widget
    historyTable = new QTableWidget(this);
    historyTable->setColumnCount(4); // Event Name, Date, Location
    historyTable->setHorizontalHeaderLabels({"Event Name", "Date", "Location", "Number of Tickets"});
    historyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Load booking history from file
    loadBookingHistory();

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(historyTable);
    setLayout(layout);

    setWindowTitle("Booking History");
    resize(600, 400);
}

BookingHistory::~BookingHistory() {}

void BookingHistory::loadBookingHistory() {
    QFile file("C:\\Users\\hemac\\OneDrive\\Desktop\\booking.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "Unable to load booking history.");
        return;
    }

    QTextStream in(&file);

    // Clear the existing table data first
    historyTable->setRowCount(0);  // Start with 0 rows

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() != 4) {
            qDebug() << "Skipping invalid line: " << line;
            continue;  // Skip lines that do not have exactly 4 fields
        }

        // Insert a new row
        int row = historyTable->rowCount();
        historyTable->insertRow(row);

        // Populate the table with the data from the current line
        for (int col = 0; col < fields.size(); ++col) {
            historyTable->setItem(row, col, new QTableWidgetItem(fields[col]));
        }
    }

    file.close();
}

