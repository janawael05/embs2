#include "Event.h"
#include <fstream>
#include <iostream>

Event::Event(const string& t, const string& d, const string& dt, const string& loc, double tp, int as)
    : title(t), description(d), date(dt), location(loc), ticketPrice(tp), availableSeats(as) {}

