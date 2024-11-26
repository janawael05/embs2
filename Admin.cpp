#include "admin.h"
#include <QDebug>  // Include for logging output

// Constructor to initialize Admin with username and password
Admin::Admin(QString username, QString password)
    : username(username), password(password) {

    // Adding some dummy users to the map
    users["bassel"] = "6789";  // Add Bassel user with password 6789
    users["nada"] = "7890";    // Add Nada user with password 7890
    users["ibrahim"] = "5678"; // Add Ibrahim (admin) user with password 5678
}

// Method to check if the entered password matches the stored admin password
bool Admin::checkPassword(const QString& inputPassword) const {
    return password == inputPassword;  // Return true if passwords match
}

// Method to create a new event with the given name and date
void Admin::createEvent(QString eventName, QString eventDate) {
    events[nextEventId] = eventName;  // Add event to map with event ID as key and event name as value
    qDebug() << "Created event: " << eventName << " on " << eventDate;  // Log the event creation
    nextEventId++;  // Increment event ID for the next event
}

// Method to update an existing event's name and date by event ID
void Admin::updateEvent(int eventId, QString newEventName, QString newEventDate) {
    auto it = events.find(eventId);  // Find the event by its ID
    if (it != events.end()) {  // If event exists
        it->second = newEventName;  // Update the event name
        qDebug() << "Event ID " << eventId << " updated to " << newEventName << " on " << newEventDate;
    } else {
        qDebug() << "Event ID " << eventId << " not found!";  // Log if event not found
    }
}

// Method to display all events managed by the admin
void Admin::viewAllEvents() const {
    qDebug() << "All events managed by admin " << username;  // Log admin username
    for (const auto& event : events) {  // Loop through the events map
        qDebug() << "Event ID: " << event.first << ", Name: " << event.second;  // Print event ID and name
    }
}

// Method to display the list of users registered on the platform (dummy data)
void Admin::viewUsers() const {
    qDebug() << "Users registered on the platform:";
    for (const auto& user : users) {  // Loop through the map of users
        qDebug() << "Username: " << user.first << ", Password: " << user.second;  // Print username and password
    }
}
