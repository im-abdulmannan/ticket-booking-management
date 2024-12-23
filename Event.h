#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Main.h"

class Event {
private:
    int eventID;
    string eventName, date, time, venue;
    int totalSeats;
    int bookedSeats;

public:
    Event();
    Event(int id, const string& name, const string& date, const string& time, const string& venue, int totalSeats, int bookedSeats);

    int getEventID() const;
    string getEventName() const;
    string getDate() const;
    string getTime() const;
    string getVenue() const;
    int getAvailableSeats() const;

    void incrementBooking();
    int getBookedSeats() const;

    static string getEventNameById(int eventId);
    Event* getEventById(int eventId);

    void updateSeats(int seat);

    void displayEventDetails() const;

    static void saveEvents(const vector<Event>& events);

    bool loadEvent(stringstream& ss);
};