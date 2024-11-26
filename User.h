#ifndef USER_H
#define USER_H

#include <QString>
#include <QMap>
#include <QVector>

class User {
public:
    User(QString name, QString email, QString password);
    QString getName() const;
    QString getEmail() const;
    bool checkPassword(const QString& password) const;
    void bookEvent(int eventId);
    void viewBookings() const;


    static QMap<QString, QString>& getUserDatabase();
    static bool validateCredentials(const QString& username, const QString& password);

private:
    QString name;
    QString email;
    QString password;
    QVector<int> bookedEvents;
};

#endif // USER_H
