#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Event.h"
#include "User.h"

class Admin : public User {
public:
    Admin(int id, string name, string email, string password, string role)
        : User(id, name, email, password, role) {}

    void createEvent(vector<Event>& events);
    void updateSeats(vector<Event>& events);
    void viewAllUsers(vector<User>& users);
};