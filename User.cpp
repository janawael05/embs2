#include "User.h"
#include <QDebug>

User::User(QString name, QString email, QString password)
    : name(name), email(email), password(password) {}

QString User::getName() const { return name; }

QString User::getEmail() const { return email; }

bool User::checkPassword(const QString& inputPassword) const {
    return inputPassword == password;
}

void User::bookEvent(int eventId) {
    bookedEvents.append(eventId);
}

void User::viewBookings() const {
    for (int event : bookedEvents) {
        qDebug() << "Booked Event ID:" << event;
    }
}

QMap<QString, QString>& User::getUserDatabase() {
    static QMap<QString, QString> userDatabase;
    if (userDatabase.isEmpty()) {
        userDatabase["Ahmed"] = "1234";
        userDatabase["Jana"] = "2345";
        userDatabase["Noor"] = "3456";
    }
    return userDatabase;
}

bool User::validateCredentials(const QString& username, const QString& password) {
    QMap<QString, QString>& userDatabase = getUserDatabase();
    return userDatabase.contains(username) && userDatabase[username] == password;
}
