#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

using namespace std;

class Event {
public:
    string title;
    string description;
    string date;
    string location;
    double ticketPrice;
    int availableSeats;

    Event(const string& t, const string& d, const string& dt, const string& loc, double tp, int as);
    vector<Event>events;
};

#endif // EVENT_H
