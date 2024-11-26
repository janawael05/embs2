#include "AdminDashboard.h"
#include "ui_AdminDashboard.h"
#include "Event.h"
#include "loginforadmins.h"
#include "EventBrowsingandBooking.h"
vector<Event> events;

AdminDashboard::AdminDashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
    eventsTable = ui->eventsTable;
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}
void searchEventsByKeyword(const string& keyword, QTableWidget* eventsTable) {
    eventsTable->clear(); // Clear any previous content
    eventsTable->setColumnCount(6); // Columns for all Event fields
    eventsTable->setHorizontalHeaderLabels({"Title", "Description", "Date", "Location", "Ticket Price", "Available Seats"});

    int row = 0;

    for (const auto& event : events) {
        if (event.title.find(keyword) != std::string::npos || event.description.find(keyword) != std::string::npos) {
            eventsTable->insertRow(row); // Add a new row

            // Populate table with event details
            eventsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(event.title)));
            eventsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(event.description)));
            eventsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(event.date)));
            eventsTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(event.location)));
            eventsTable->setItem(row, 4, new QTableWidgetItem(QString::number(event.ticketPrice, 'f', 2)));
            eventsTable->setItem(row, 5, new QTableWidgetItem(QString::number(event.availableSeats)));

            ++row;
        }
    }
}

// void AdminDashboard::saveEventsToFile(const vector<Event>& events, const string& filename) {
//     ofstream file(filename);

//     if (!file.is_open()) {
//         cout << "Error: Could not open file events.csv" << " for writing.\n";
//         return;
//     }

//     //header row
//     file << "Title,Description,Date,Location,Ticket Price,Available Seats\n";

//     // Write each event's data
//     for (const auto& event : events) {
//         file << "\"" << event.title << "\","
//              << "\"" << event.description << "\","
//              << event.date << ","
//              << event.location << ","
//              << event.ticketPrice << ","
//              << event.availableSeats << "\n";
//     }

//     file.close();
//     QMessageBox::information(this, "Success", "Events saved successfully!");
// }
void AdminDashboard::saveEventsToFile(const std::vector<Event>& events, const std::string& filepath) {
    // Open the file in truncation mode to clear its contents
    std::ofstream outFile(filepath, std::ios::trunc);
    if (!outFile.is_open()) {
        QMessageBox::warning(this, "File Error", "Failed to open the file for saving.");
        return;
    }

    // Write each event from the vector into the file
    for (const auto& event : events) {
        outFile << event.title << ","
                << event.description << ","
                << event.date << ","
                << event.location << ","
                << event.ticketPrice << ","
                << event.availableSeats << "\n";
    }

    outFile.close(); // Ensure the file is properly closed
    QMessageBox::information(this, "Save Successful", "Events have been saved successfully.");
}






// void AdminDashboard::on_AddEventButton_clicked()
// {
//     int selectedRow = ui->eventsTable->currentRow();
//     QTableWidgetItem *titleItem = ui->eventsTable->item(selectedRow, 0);
//     QTableWidgetItem *descriptionItem = ui->eventsTable->item(selectedRow, 1);
//     QTableWidgetItem *dateItem = ui->eventsTable->item(selectedRow, 2);
//     QTableWidgetItem *locationItem = ui->eventsTable->item(selectedRow, 3);
//     QTableWidgetItem *ticketPriceItem = ui->eventsTable->item(selectedRow, 4);
//     QTableWidgetItem *availableSeatsItem = ui->eventsTable->item(selectedRow, 5);

//     if (!titleItem || !descriptionItem || !dateItem || !locationItem || !ticketPriceItem || !availableSeatsItem)
//     {
//         QMessageBox::warning(this, "Incomplete Data", "Please fill in all columns for the selected row.");
//         return;
//     }

//     // Extract data and create an Event object
//     std::string title = titleItem->text().toStdString();
//     std::string description = descriptionItem->text().toStdString();
//     std::string date = dateItem->text().toStdString();
//     std::string location = locationItem->text().toStdString();
//     double ticketPrice = ticketPriceItem->text().toDouble();
//     int availableSeats = availableSeatsItem->text().toInt();

//     Event newEvent(title, description, date, location, ticketPrice, availableSeats);

//     // Add the event to the vector
//     events.push_back(newEvent);
//     saveEventsToFile(events, "events.csv");

// }
// void AdminDashboard::on_AddEventButton_clicked()
// {
//     int selectedRow = ui->eventsTable->currentRow();

//     // Ensure a valid row is selected
//     if (selectedRow == -1) {
//         QMessageBox::warning(this, "No Selection", "Please select a row to add an event.");
//         return;
//     }

//     // Check for existing data in the row
//     QTableWidgetItem *titleItem = ui->eventsTable->item(selectedRow, 0);
//     QTableWidgetItem *descriptionItem = ui->eventsTable->item(selectedRow, 1);
//     QTableWidgetItem *dateItem = ui->eventsTable->item(selectedRow, 2);
//     QTableWidgetItem *locationItem = ui->eventsTable->item(selectedRow, 3);
//     QTableWidgetItem *ticketPriceItem = ui->eventsTable->item(selectedRow, 4);
//     QTableWidgetItem *availableSeatsItem = ui->eventsTable->item(selectedRow, 5);


//     // Ensure no columns are left empty
//     if (!titleItem || !descriptionItem || !dateItem || !locationItem || !ticketPriceItem || !availableSeatsItem) {
//         QMessageBox::warning(this, "Incomplete Data", "Please fill in all columns for the selected row.");
//         return;
//     }

//     // Extract data and create an Event object
//     std::string title = titleItem->text().toStdString();
//     std::string description = descriptionItem->text().toStdString();
//     std::string date = dateItem->text().toStdString();
//     std::string location = locationItem->text().toStdString();
//     double ticketPrice = ticketPriceItem->text().toDouble();
//     int availableSeats = availableSeatsItem->text().toInt();

//     Event newEvent(title, description, date, location, ticketPrice, availableSeats);

//     // Add the event to the vector
//     events.push_back(newEvent);

//     saveEventsToFile(events, "C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt");

//     QMessageBox::information(this, "Event Added", "The event has been successfully added.");
// }
void AdminDashboard::on_AddorEditEventButton_clicked()
{
    int selectedRow = ui->eventsTable->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a row to edit.");
        return;
    }

    // Get the items from the selected row
    QTableWidgetItem *titleItem = ui->eventsTable->item(selectedRow, 0);
    QTableWidgetItem *descriptionItem = ui->eventsTable->item(selectedRow, 1);
    QTableWidgetItem *dateItem = ui->eventsTable->item(selectedRow, 2);
    QTableWidgetItem *locationItem = ui->eventsTable->item(selectedRow, 3);
    QTableWidgetItem *ticketPriceItem = ui->eventsTable->item(selectedRow, 4);
    QTableWidgetItem *availableSeatsItem = ui->eventsTable->item(selectedRow, 5);

    if (!titleItem || !descriptionItem || !dateItem || !locationItem || !ticketPriceItem || !availableSeatsItem) {
        QMessageBox::warning(this, "Incomplete Data", "Please fill in all columns for the selected row.");
        return;
    }

    // Extract data from the table
    std::string title = titleItem->text().toStdString();
    std::string description = descriptionItem->text().toStdString();
    std::string date = dateItem->text().toStdString();
    std::string location = locationItem->text().toStdString();
    double ticketPrice = ticketPriceItem->text().toDouble();
    int availableSeats = availableSeatsItem->text().toInt();

    // Create the new event object
    Event newEvent(title, description, date, location, ticketPrice, availableSeats);

    // Locate the event in the vector and replace it
    auto it = std::find_if(events.begin(), events.end(), [&](const Event& event) {
        return event.title == title; // Assuming the title is unique
    });

    if (it != events.end()) {
        *it = newEvent; // Replace the old event with the new event
    } else {
        QMessageBox::warning(this, "Error", "Failed to locate the event in the list.");
        return;
    }

    // Save the updated events to the file
    saveEventsToFile(events, "C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt");

    QMessageBox::information(this, "Edit Successful", "The event has been updated successfully.");
}





void AdminDashboard::on_deleteEventButton_clicked()
{
    int selectedRow = ui->eventsTable->currentRow(); // Get the selected row
    if (selectedRow == -1) {
        QMessageBox::warning(this, "No Selection", "Please select a row to delete.");
        return;
    }

    // Get the title of the event from the selected row (assuming title is in column 0)
    QTableWidgetItem* titleItem = ui->eventsTable->item(selectedRow, 0);
    if (!titleItem) {
        QMessageBox::warning(this, "Error", "Failed to get the event title for deletion.");
        return;
    }

    std::string eventTitle = titleItem->text().toStdString();

    // Find and erase the event from the vector
    auto it = std::find_if(events.begin(), events.end(), [&](const Event& event) {
        return event.title == eventTitle; // Match the event by its title
    });

    if (it != events.end()) {
        events.erase(it); // Remove the event from the vector
    } else {
        QMessageBox::warning(this, "Error", "Event not found in the list.");
        return;
    }

    // Remove the row from the table
    ui->eventsTable->removeRow(selectedRow);

    // Save the updated events list to the file
    saveEventsToFile(events, "C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt");

    QMessageBox::information(this, "Deleted", "The event has been deleted successfully.");
}




void AdminDashboard::on_viewAttendeesButton_clicked()
{

}


void AdminDashboard::on_generateReportButton_clicked()
{
    // if(performance > 5)
    //     cout << " it is active event"<<endl;
    // else
    //     cout << " it is not active"<<endl;
}


void AdminDashboard::on_searchEventsLineEdit_textChanged(const QString &arg1)
{
     //searchEventsByKeyword(arg1.toStdString(), eventsTable);
}

void AdminDashboard::loadEventsFromFile() {
    // Verify if the file exists
    QString filePath = "C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt";
    if (!QFile::exists(filePath)) {
        QMessageBox::warning(this, "File Error", "The file 'event.txt' does not exist in the expected location.");
        return;
    }

    std::ifstream inFile("C:\\Users\\hemac\\OneDrive\\Desktop\\event.txt");
    if (!inFile.is_open()) {
        QMessageBox::warning(this, "File Error", "Failed to open the file for loading events.");
        return;
    }

    // Only clear the table if you want to reload from file or refresh the table
    // If you want to preserve existing data, comment the next two lines
    // ui->eventsTable->setRowCount(0);  // Clears the rows (not the whole table)
    ui->eventsTable->setColumnCount(6);  // Ensure column count is correct
    ui->eventsTable->setHorizontalHeaderLabels({"Title", "Description", "Date", "Location", "Ticket Price", "Available Seats"});

    // Read and populate events
    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string title, description, date, location, ticketPriceStr, availableSeatsStr;

        if (std::getline(ss, title, ',') &&
            std::getline(ss, description, ',') &&
            std::getline(ss, date, ',') &&
            std::getline(ss, location, ',') &&
            std::getline(ss, ticketPriceStr, ',') &&
            std::getline(ss, availableSeatsStr)) {

            double ticketPrice = std::stod(ticketPriceStr);
            int availableSeats = std::stoi(availableSeatsStr);

            Event event(title, description, date, location, ticketPrice, availableSeats);
            events.push_back(event);

            // Add to the table
            int row = 0;
            ui->eventsTable->insertRow(row);
            ui->eventsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(title)));
            ui->eventsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(description)));
            ui->eventsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(date)));
            ui->eventsTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(location)));
            ui->eventsTable->setItem(row, 4, new QTableWidgetItem(QString::number(ticketPrice, 'f', 2)));
            ui->eventsTable->setItem(row, 5, new QTableWidgetItem(QString::number(availableSeats)));
            row++;
        }
    }

    inFile.close();
    QMessageBox::information(this, "Load Successful", "Events have been successfully loaded.");
}

void AdminDashboard::on_returnbackpushbutton_clicked()
{
    std::map<QString, QString> username_and_password;
    hide();
    loginforadmins * login = new class loginforadmins(username_and_password,this);
    login->show();
}




