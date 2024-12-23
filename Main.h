#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Main.h"
#include "Admin.h"
#include "Customer.h"
#include "Event.h"
#include "User.h"
#include "Booking.h"

class Main {
        static vector<Event> events;
    public:
        // Data Sets
        vector<User> users;
        vector<Booking> bookings;

        static vector<Event> getAllEvents();

        // Main Function
        void init();
        void adminMenu(Admin* admin);
        void customerMenu(Customer* customer);

        // File Handling Functions
        void loadUsers();
        void loadEvents();
        void loadBookings();

        // Login and Register Functions
        User* loginUser();

        void generateMostBookedEventsReport();
};