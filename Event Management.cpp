#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Event {
    string title;
    string description;
    string date;
    string location;
    double ticketPrice;
    int availableSeats;
};


map<int, Event> events;


void addEvent(int eventId, const Event& newEvent) {
    events[eventId] = newEvent;
    cout << "Event added: " << newEvent.title << endl;
}


void displayEvents() {
    for (const auto& [id, event] : events) {
        cout << "Event ID: " << id
             << ", Title: " << event.title
             << ", Date: " << event.date
             << ", Location: " << event.location
             << ", Price: $" << event.ticketPrice
             << ", Available Seats: " << event.availableSeats << endl;
    }
}
