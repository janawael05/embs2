// #include "EventBrowsingandBooking.h"
// #include "ui_EventBrowsingandBooking.h"
// #include "Event.h"


// EventBrowsingandBooking::EventBrowsingandBooking(QWidget *parent)
//     : QDialog(parent)
//     , ui(new Ui::EventBrowsingandBooking)
// {
//     ui->setupUi(this);
//     eventTable = ui->eventTable;

// }

// EventBrowsingandBooking::~EventBrowsingandBooking()
// {
//     delete ui;
// }

// void EventBrowsingandBooking::loadEventsFromFile() {
//     QFile file("event.txt");
//     // qDebug() << "Attempting to load events from file:" << QFontInfo(file).absoluteFilePath();

//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         QMessageBox::critical(this, "Error", "Unable to open file for loading.");
//         return;
//     }

//     QTextStream in(&file);
//     eventTable->setRowCount(0); // Clear existing rows

//     while (!in.atEnd()) {
//         QString line = in.readLine();
//         QStringList fields = line.split(',');

//         if (fields.size() != 7) {
//             qWarning() << "Skipped invalid line:" << line;
//             continue;
//         }

//         int row = eventTable->rowCount();
//         eventTable->insertRow(row);

//         for (int col = 0; col < fields.size(); ++col) {
//             eventTable->setItem(row, col, new QTableWidgetItem(fields[col]));
//         }
//     }

//     file.close();
//     qDebug() << "Finished loading events.";
// }


// void EventBrowsingandBooking::on_bookEventButton_clicked()
// {
//     int selectedRow = ui->eventTable->currentRow();
//     if (selectedRow < 0) {
//         QMessageBox::warning(this, "No Selection", "Please select an event to book.");
//         return;
//     }

//     QString eventName = ui->eventTable->item(selectedRow, 1)->text();
//     QString eventDate = ui->eventTable->item(selectedRow, 2)->text();
//     QString eventLocation = ui->eventTable->item(selectedRow, 3)->text();

//     if (!bookingConfirmation) {
//         bookingConfirmation = new BookingConfirmation(this);
//     }
//         bookingConfirmation->setBookingDetails(eventName, eventDate, eventLocation);

//     bookingConfirmation->show();
// }


// void EventBrowsingandBooking::on_bookingHistoryButton_clicked()
// {
//     if (!bookingHistoryWindow) {
//         bookingHistoryWindow = new BookingHistory(this);
//     }
//     bookingHistoryWindow->show();
// }
#include "EventBrowsingandBooking.h"
#include "ui_EventBrowsingandBooking.h"
#include "Event.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "AdminDashboard.h"
#include <map>
#include "search.h"

EventBrowsingandBooking::EventBrowsingandBooking(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EventBrowsingandBooking)
{
    ui->setupUi(this);
    eventTable = ui->eventTable;
}

EventBrowsingandBooking::~EventBrowsingandBooking()
{
    delete ui;
}

void EventBrowsingandBooking::loadEventsFromFile() {
    QFile file("C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt"); // Ensure the file path is correct
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the events file.");
        return;
    }

    QTextStream in(&file);
    eventTable->setRowCount(0); // Clear existing rows

    while (!in.atEnd()) {
        QString line = in.readLine(); // Read one line at a time
        QStringList fields = line.split(','); // Split by comma

        if (fields.size() != 6) { // Expecting 6 fields: title, description, date, location, ticketPrice, availableSeats
            qWarning() << "Invalid line format, skipping:" << line;
            continue;
        }

        // Parse and validate fields
         title = fields[0].trimmed();
         description = fields[1].trimmed();
         date = fields[2].trimmed();
         location = fields[3].trimmed();
         ticketPrice = fields[4].trimmed().toDouble();
         availableSeats = fields[5].trimmed().toInt();

        // Add a new row to the table at the end
        int row = eventTable->rowCount(); // Get current row count
        eventTable->insertRow(row);

        // Set each cell in the table
        eventTable->setItem(row, 0, new QTableWidgetItem(title));
        eventTable->setItem(row, 1, new QTableWidgetItem(description));
        eventTable->setItem(row, 2, new QTableWidgetItem(date));
        eventTable->setItem(row, 3, new QTableWidgetItem(location));
        eventTable->setItem(row, 4, new QTableWidgetItem(QString::number(ticketPrice, 'f', 2)));
        eventTable->setItem(row, 5, new QTableWidgetItem(QString::number(availableSeats)));
    }

    file.close();
    qDebug() << "Finished loading events into the table.";
}


void EventBrowsingandBooking::on_bookEventButton_clicked() {
    int selectedRow = ui->eventTable->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select an event to book.");
        return;
    }

    QString eventName = ui->eventTable->item(selectedRow, 0)->text(); // Updated column index
    QString eventDate = ui->eventTable->item(selectedRow, 2)->text();
    QString eventLocation = ui->eventTable->item(selectedRow, 3)->text();


    bookingConfirmation = new BookingConfirmation(this);
    bookingConfirmation->setBookingDetails(eventName, eventDate, eventLocation);

    bookingConfirmation->show();
}

// void EventBrowsingandBooking::on_selectCategory_activated(int index)
// {
//     // Vector to hold all events
//     std::vector<Event> a;

//     // Open the file and load all events into vector 'a'
//     QFile file("C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt");
//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         QMessageBox::critical(this, "Error", "Unable to open the events file.");
//         return;
//     }

//     QTextStream in(&file);
//     while (!in.atEnd()) {
//         QString line = in.readLine();
//         QStringList fields = line.split(',');

//         // Skip lines with less than 7 fields (assuming 7 fields per line)
//         if (fields.size() < 7) {
//             qWarning() << "Invalid line, skipping:" << line;
//             continue;
//         }

//         // Create an Event object and add it to vector 'a'
//         Event event(
//             fields[0].trimmed().toStdString(), // Title
//             fields[1].trimmed().toStdString(), // Description
//             fields[2].trimmed().toStdString(), // Date
//             fields[3].trimmed().toStdString(), // Location
//             fields[4].trimmed().toDouble(),    // Ticket Price
//             fields[5].trimmed().toInt()        // Available Seats
//             );
//         event.description = fields[6].trimmed().toStdString(); // Category
//         a.push_back(event);
//     }


//     // Vector to hold filtered events
//     std::vector<Event> b;

//     // Get the selected category from the UI
//     QString selectedCategory = ui->selectCategory->itemText(index);
//     std::string selectedCategoryStr = selectedCategory.toStdString();

//     // Filter the events by the selected category
//     for (const auto& event : a) {
//         if (event.description == selectedCategoryStr) {
//             b.push_back(event);
//         }
//     }

//     // Update the table with filtered events
//     // ui->eventTable->setRowCount(b.size());

//     int row = 0;
//     for (const auto& event : b) {
//         ui->eventTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(event.title)));
//         ui->eventTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(event.description)));
//         ui->eventTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(event.date)));
//         ui->eventTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(event.location)));
//         ui->eventTable->setItem(row, 4, new QTableWidgetItem(QString::number(event.ticketPrice, 'f', 2)));
//         ui->eventTable->setItem(row, 5, new QTableWidgetItem(QString::number(event.availableSeats)));
//         row++;
//     }
//     saveToFile(b,"C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt" );
//     file.close(); // Explicitly close the file after reading
// }
// void EventBrowsingandBooking::saveToFile(const std::vector<Event>& events, const QString& filePath)
// {
//     // Open the file in write mode, truncating any existing content
//     QFile file(filePath);
//     if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
//         QMessageBox::critical(this, "Error", "Unable to open the events file for writing.");
//         return;
//     }

//     QTextStream out(&file);

//     // Write each event's data to the file
//     for (const auto& event : events) {
//         out << QString::fromStdString(event.title) << ","
//             << QString::fromStdString(event.description) << ","
//             << QString::fromStdString(event.date) << ","
//             << QString::fromStdString(event.location) << ","
//             << QString::number(event.ticketPrice, 'f', 2) << ","
//             << QString::number(event.availableSeats) << ","
//             << QString::fromStdString(event.description) << "\n";
//     }

//     file.close(); // Don't forget to close the file after writing
// }
#include "EventBrowsingandBooking.h"
#include <QString>

// Update the table to display only events matching the keyword
void EventBrowsingandBooking::searchEventsByKeyword(const QString& keyword) {
    // Clear the table to prepare for new results
    vector<Event>events;

    // Iterate through the events in the class-level data structure
    for (const auto& pair : events) {  // Assuming 'events' is a class member

        // Check if the keyword matches the event title or description
        if (QString::fromStdString(pair.title).contains(keyword, Qt::CaseInsensitive) ||
            QString::fromStdString(pair.description).contains(keyword, Qt::CaseInsensitive)) {
            ui->eventTable->setRowCount(0);


            // Add a new row for the matching event
            int row = ui->eventTable->rowCount();
            ui->eventTable->insertRow(row);

            ui->eventTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pair.title)));
            ui->eventTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(pair.description)));
            ui->eventTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(pair.date)));
            ui->eventTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(pair.location)));
            ui->eventTable->setItem(row, 4, new QTableWidgetItem(QString::number(pair.ticketPrice, 'f', 2)));
            ui->eventTable->setItem(row, 5, new QTableWidgetItem(QString::number(pair.availableSeats)));
        }
    }

    // If no matching events are found, show a message box
    if (ui->eventTable->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No events matched your search criteria.");
    }
}


void EventBrowsingandBooking::on_bookingHistoryButton_clicked()
{
    bookingHistoryWindow = new BookingHistory(this);
    bookingHistoryWindow->show();
}




// void EventBrowsingandBooking::on_searchEvents_textEdited(const QString &arg1)
// {
//     searchEventsByKeyword(arg1);
// }


void EventBrowsingandBooking::on_searchEvents_returnPressed()
{
    searchEventsByKeyword(ui->searchEvents->text());
}

