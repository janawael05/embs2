#include <map>

struct User {
    string name;
    string email;
    vector<int> bookings;
};

map<string, User> users;

void registerUser(const string& email, const string& name) {
    if (users.count(email)) {
        cout << "User already exists!" << endl;
        return;
    }
    users[email] = {name, email, {}};
    cout << "User registered: " << name << endl;
}

void bookEvent(const string& email, int eventId) {
    if (!users.count(email)) {
        cout << "User not found!" << endl;
        return;
    }
    if (!events.count(eventId)) {
        cout << "Event not found!" << endl;
        return;
    }
    if (events[eventId].availableSeats <= 0) {
        cout << "No seats available for this event!" << endl;
        return;
    }

    users[email].bookings.push_back(eventId);
    events[eventId].availableSeats--; 
    cout << "Event booked successfully for " << email << endl;
}

void viewBookings(const string& email) {
    if (!users.count(email)) {
        cout << "User not found!" << endl;
        return;
    }

    cout << "Bookings for " << users[email].name << ": " << endl;
    for (int eventId : users[email].bookings) {
        cout << "- " << events[eventId].title << " on " << events[eventId].date << endl;
    }
}
