#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Event.h"

class Booking {
private:
    static int bookingCounter;
    string bookingID;
    int customerID, eventID;

public:
    Booking();
    Booking(string bookingId, int customerId, int eventId);

    void confirmBooking() const;
    string generateBookingId();
    string getBookingId() const;
    int getCustomerId() const;
    int getEventId() const;

    void saveBookings(const vector<Booking>& bookings);

    bool loadBooking(stringstream& ss);
    void displayBooking();

    void bookSeat(int eventId);
};