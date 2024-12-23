#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class User {
protected:
    int userID;
    string name, email, password, role;

public:
    User();
    User(int id, string name, string email, string password, string role);
    virtual ~User() {}

    string getEmail() const;
    string getPassword() const;
    string getName() const;
    string getRole() const;
    int getId() const;
    void saveUsers(vector<User>& users) const;
    bool loadUser(stringstream& ss);
};
