#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "User.h"
#include "Event.h"

class Customer : public User {
private:
    vector<string> bookingHistory;

public:
    Customer(int id, string name, string email, string password, string role)
        : User(id, name, email, password, role) {}

    void addBooking(const string& bookingID);
    void viewBookingHistory() const;
    void viewAllEvents(vector<Event>& events);
    void bookSeat(vector<Event>& events);
};