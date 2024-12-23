#include "Admin.h"

void Admin::createEvent(vector<Event>& events) {
    int id;
    string name, date, time, venue;
    int availableSeats;
    cout << "Enter Event ID: ";
    cin >> id;
    cout << "Enter Event Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter Time (HH:MM): ";
    cin >> time;
    cout << "Enter Venue: ";
    cin.ignore();
    getline(cin, venue);
    cout << "Enter Available Seats: ";
    cin >> availableSeats;

    Event event(id, name, date, time, venue, availableSeats, 0);
    events.push_back(event);
    Event::saveEvents(events);
    cout << "Event created successfully!\n";
}

void Admin::updateSeats(vector<Event>& events) {
    int eventID;
    cout << "Enter Event ID to update seats: ";
    cin >> eventID;

    auto it = find_if(events.begin(), events.end(),
                      [&](const Event& e) { return e.getEventID() == eventID; });

    if (it != events.end()) {
        cout << "Enter new available seats: ";
        int seats;
        cin >> seats;
        it->updateSeats(seats);
        Event::saveEvents(events);
        cout << "Seats updated successfully!\n";
    } else {
        cout << "Event not found.\n";
    }
}

void Admin::viewAllUsers(vector<User> &users) {
    cout << setw(10) << "UserId"
              << setw(20) << "Name"
              << setw(30) << "Email"
              << setw(15) << "Role"
              << endl;

    for (auto& user : users) {
        cout << setw(10) << user.getId()
              << setw(20) << user.getName()
              << setw(30) << user.getEmail()
              << setw(15) << user.getRole()
              << endl;
    }
}
