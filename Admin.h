#ifndef ADMIN_H
#define ADMIN_H

#include <QString>
#include <QList>
#include <map>  // Include map for storing users (username, password)

class Admin {
public:
    // Constructor to initialize Admin with username and password
    Admin(QString username, QString password);

    // Method to check if the entered password matches the stored admin password
    bool checkPassword(const QString& inputPassword) const;

    // Method to create a new event with name and date
    void createEvent(QString eventName, QString eventDate);

    // Method to update an existing event's details (ID, name, and date)
    void updateEvent(int eventId, QString newEventName, QString newEventDate);

    // Method to display all events managed by the admin
    void viewAllEvents() const;

    // Method to display the list of users registered on the platform (dummy data)
    void viewUsers() const;

private:
    QString username;  // Admin's username
    QString password;  // Admin's password
    std::map<int, QString> events;  // Map of events (ID as key, event name as value)
    int nextEventId = 1;  // Event ID counter (incremented with each new event)

    // Using std::map to store dummy users (username as key, password as value)
    std::map<QString, QString> users;  // Map of users with their usernames and passwords
};

#endif // ADMIN_H
