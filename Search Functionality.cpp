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

void searchEventsByKeyword(const string& keyword) {
    cout << "Search results for keyword: " << keyword << endl;

    
    for (const auto& pair : events) {
        if (pair.second.title.find(keyword) != string::npos) {
            cout << "- Event ID: " << pair.first << ", Title: " << pair.second.title << endl;
        }
    }
}

void sortEventsByDate() {
    vector<pair<int, Event>> eventList;
    for (const auto& pair : events) {
        eventList.push_back(pair);
    }

    for (size_t i = 0; i < eventList.size(); ++i) {
        for (size_t j = 0; j < eventList.size() - i - 1; ++j) {
            if (eventList[j].second.date > eventList[j + 1].second.date) {
                swap(eventList[j], eventList[j + 1]);
            }
        }
    }

    cout << "Events sorted by date:" << endl;
    for (const auto& pair : eventList) {
        cout << "- " << pair.second.title << " on " << pair.second.date << endl;
    }
}


