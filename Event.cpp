#include "Event.h"

Event::Event() {}
Event::Event(int id, const string& name, const string& date, const string& time, const string& venue, int availableSeats, int bookedSeats)
        : eventID(id), eventName(name), date(date), time(time), venue(venue), totalSeats(availableSeats), bookedSeats(bookedSeats) {}

void Event::updateSeats(int seat) {
    totalSeats = seat;
}

void Event::displayEventDetails() const {
    cout << setw(15) << eventID
              << setw(40) << eventName
              << setw(25) << date
              << setw(18) << time
              << setw(25) << venue
              << setw(25) << totalSeats - bookedSeats
              << endl;
}

int Event::getEventID() const { return eventID; }
string Event::getEventName() const { return eventName; }
string Event::getDate() const { return date; }
string Event::getTime() const { return time; }
string Event::getVenue() const { return venue; }
int Event::getAvailableSeats() const { return totalSeats; }

void Event::incrementBooking() {
    bookedSeats++;
}

int Event::getBookedSeats() const
{
    return bookedSeats;
}

string Event::getEventNameById(int eventId)
{
    Main main;
    vector<Event> events = main.getAllEvents();
    for(auto& event : events) {
        if(event.getEventID() == eventId) {
            return event.getEventName();
        }
    }

    return "Event Not Found";
}

Event *Event::getEventById(int eventId) {
    Main main;
    vector<Event> events = main.getAllEvents();
    for(auto& event : events) {
        if(event.getEventID() == eventId) {
            return& event;
        }
    }

    return nullptr;
}

void Event::saveEvents(const vector<Event>& events) {
    ofstream outFile("events.txt", ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for saving events!" << endl;
        return;
    }

    for (const auto& event : events) {
        outFile << event.eventID << ","
                << event.eventName << ","
                << event.date << ","
                << event.time << ","
                << event.venue << ","
                << event.totalSeats << "," << event.getBookedSeats() << "\n";
    }

    outFile.close();
    cout << "Events saved successfully!" << endl;
}

bool Event::loadEvent(stringstream& ss) {
    string temp;

    if (!getline(ss, temp, ',')) return false;
    eventID = stoi(temp);

    if (!getline(ss, eventName, ',')) return false;
    if (!getline(ss, date, ',')) return false;
    if (!getline(ss, time, ',')) return false;
    if (!getline(ss, venue, ',')) return false;
    if (!getline(ss, temp, ',')) return false;
    totalSeats = stoi(temp);
    if (!getline(ss, temp, ',')) return false;
    bookedSeats = stoi(temp);

    return true;
}