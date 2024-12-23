#include "User.h"

using namespace std;

User::User() {}
User::User(int id, string name, string email, string password, string role)
        : userID(id), name(name), email(email), password(password), role(role) {}

string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
string User::getName() const { return name; }
string User::getRole() const { return role; }
int User::getId() const { return userID; }

void User::saveUsers(vector<User>& users) const {
    ofstream outFile("users.txt");
    if (!outFile) {
        cerr << "Error opening file users.txt for writing!" << endl;
        return;
    }

    for (const auto& user : users) {
        outFile << user.getId() << ","
                << user.getName() << ","
                << user.getEmail() << ","
                << user.getPassword() << "," << user.getRole() << endl;
    }

    outFile.close();
    cout << "Users saved successfully!" << endl;
}

bool User::loadUser(stringstream& ss) {
    string temp;
    
    if (!getline(ss, temp, ',')) return false;
    userID = stoi(temp);

    if (!getline(ss, name, ',')) return false;
    if (!getline(ss, email, ',')) return false;
    if (!getline(ss, password, ',')) return false;
    if (!getline(ss, role, ',')) return false;

    return true;
}
