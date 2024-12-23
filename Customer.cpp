#include "Customer.h"

void Customer::addBooking(const string& bookingID) {
    bookingHistory.push_back(bookingID);
}

void Customer::viewBookingHistory() const {
    cout << "Booking History for " << name << ":\n";
    for (const auto& booking : bookingHistory) {
        cout << "- " << booking << endl;
    }
}

void Customer::viewAllEvents(vector<Event>& events)
{
    cout << "Total Events: " << events.size() << endl;
    cout << setw(15) << "EventID"
              << setw(40) << "Event Name"
              << setw(25) << "Date"
              << setw(18) << "Time"
              << setw(25) << "Venue"
              << setw(25) << "Available Seats"
              << endl;

    for (auto& event : events) {
        event.displayEventDetails();
    }
}

void Customer::bookSeat(vector<Event> &events) {
    int eventId;
    cout << "Enter Event ID: ";
    cin >> eventId;

    for(auto& event : events) {
        if(event.getEventID() == eventId) {
            event.updateSeats(event.getAvailableSeats() - 1);
        }
    }
}
