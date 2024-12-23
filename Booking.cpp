#include "Booking.h"

int Booking::bookingCounter = 0;

Booking::Booking() {
    bookingID = generateBookingId();
}

Booking::Booking(string bookingId, int customerId, int eventId) {
    this->bookingID = bookingId;
    this->customerID = customerId;
    this->eventID = eventId;

}

void Booking::confirmBooking() const {
    cout << "Booking Confirmed: " << bookingID << endl;
}

string Booking::generateBookingId() {
    stringstream ss;
    ss << "BKG" << ++bookingCounter;
    return ss.str();
}

string Booking::getBookingId() const { return bookingID; }

int Booking::getCustomerId() const { return customerID; }

int Booking::getEventId() const { return eventID; }

void Booking::saveBookings(const vector<Booking>& bookings) {
    ofstream outFile("bookings.txt", ios::trunc);
    if (!outFile) {
        cerr << "Error opening file for saving events!" << endl;
        return;
    }

    for (const auto& booking : bookings) {
        outFile << booking.bookingID << ","
                << booking.customerID << ","
                << booking.eventID << "\n";
    }

    outFile.close();
    cout << "Bookings saved successfully!" << endl;
}

bool Booking::loadBooking(stringstream &ss) {
    if (!getline(ss, bookingID, ',')) return false;
    string customerIDStr, eventIDStr;
    if (!getline(ss, customerIDStr, ',')) return false;
    if (!getline(ss, eventIDStr, ',')) return false;
    customerID = stoi(customerIDStr);
    eventID = stoi(eventIDStr);

    return true;
}

void Booking::displayBooking() {
    cout << setw(25) << bookingID << setw(35) << Event::getEventNameById(eventID) << endl;
}

void Booking::bookSeat(int eventId) {
    Event eventInstance;
    Event* event = eventInstance.getEventById(eventId);

    if (event) {
        event->incrementBooking(); // Increment bookings
        cout << "Booking successful for event: " << event->getEventName() << endl;
    } else {
        cout << "Invalid Event ID" << endl;
    }
}
