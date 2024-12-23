#include "Main.h"

vector<Event> Main::events;

vector<Event> Main::getAllEvents()
{
    return events;
}

void Main::init() {
    // Load data
    loadUsers();
    loadEvents();
    loadBookings();

    int choice;
    while (true) {
        cout << "\n1. Login\n"
        << "2. Register new Customer\n"
        << "3. Exit\n"
        << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            User* user = loginUser();
            if(user != nullptr) {
                if(user->getRole() == "Admin") {
                    Admin* admin = dynamic_cast<Admin*>(user);
                    if (admin) {
                        adminMenu(admin);
                    } else {
                        cout << "Error: Failed to cast to Admin." << endl;
                    }
                } else if(user->getRole() == "Customer") {
                    Customer* customer = dynamic_cast<Customer*>(user);
                    if (customer) {
                        customerMenu(customer);
                    } else {
                        cout << "Error: Failed to cast to Customer." << endl;
                    }
                }
            } else {
                cout << "\nInvalid credentials!!!\n";
            }
        } else if (choice == 2) {
            int userID;
            string name, email, password;
            cout << "Enter User Id: ";
            cin >> userID;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Email: ";
            getline(cin, email);

            for (auto& user : users) {
                if (user.getEmail() == email) {
                    cout << "User with this email is already exists.";
                    return;
                }
            }

            cout << "Enter Password: ";
            cin >> password;

            User user(userID, name, email, password, "Customer");
            users.push_back(user);

            user.saveUsers(users);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    // Save data
    // saveUsers();
    // saveEvents();
    // saveBookings();
}

void Main::adminMenu(Admin* admin) {
    int adminChoice;
    do {
        cout << "\nAdmin Menu:\n"
                << "1. Create Event\n"
                << "2. Update Available Seats\n"
                << "3. View All Users\n"
                << "4. Generate Report\n"
                << "5. Logout\n"
                << "Enter your choice: ";
        cin >> adminChoice;

        switch (adminChoice) {
            case 1:
                cout << "Create Event" << endl;
                admin->createEvent(events);
                break;
            case 2:
                cout << "Update Event" << endl;
                admin->updateSeats(events);
                break;
            case 3:
                cout << "All Users\n";
                admin->viewAllUsers(users);
                break;
            case 4:
                cout << "Generate Report\n";
                generateMostBookedEventsReport();
                break;
            case 5:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (adminChoice != 5);
}

void Main::customerMenu(Customer* customer) {
    int customerChoice;
    do {
        cout << "\nCustomer Menu:" << customer->getName() << "\n"
                << "1. View All Events\n"
                << "2. Book Seats\n"
                << "3. View Booking History\n"
                << "4. Logout\n"
                << "Enter your choice: ";
        cin >> customerChoice;

        Booking booking;
        switch (customerChoice) {
            case 1:
                customer->viewAllEvents(events);
                cout << "View All Events" << endl;
                break;
            case 2:
                // customer->bookSeat(events);
                int eventId;
                cout << "Enter Event ID: ";
                cin >> eventId;

                for(auto& event : events) {
                    if(event.getEventID() == eventId) {
                        event.incrementBooking();
                    }
                }

                bookings.push_back(Booking(booking.getBookingId(), customer->getId(), eventId));
                booking.saveBookings(bookings);

                Event::saveEvents(events);
                break;
            case 3:
                cout << "View Booking History\n";
                cout << setw(25) << "Booking ID" << setw(35) << "Event Name" << endl;
                for(auto& booking : bookings) {
                    if(booking.getCustomerId() == customer->getId()) {
                        booking.displayBooking();
                    }
                }
                break;
            case 4:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (customerChoice != 4);
}

// File Handling Functions
void Main::loadUsers() {
    cout << "Loading Users" << endl;
    ifstream inFile("users.txt");

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        User user;
        stringstream ss(line);
        if (user.loadUser(ss)) {
            users.emplace_back(user);
        } else {
            cerr << "Error loading user data: " << line << endl;
        }
    }

    inFile.close();
}

void Main::loadEvents() {
    cout << "Loading Events" << endl;
    ifstream inFile("events.txt");

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        Event event;
        stringstream ss(line);
        if (event.loadEvent(ss)) {
            events.emplace_back(event);
        } else {
            cerr << "Error loading event data: " << line << endl;
        }
    }

    inFile.close();
}


void Main::loadBookings() {
    cout << "Loading Bookings" << endl;
    ifstream inFile("bookings.txt");

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        Booking booking;
        stringstream ss(line);
        if (booking.loadBooking(ss)) {
            bookings.emplace_back(booking);
        } else {
            cerr << "Error loading event data: " << line << endl;
        }
    }

    inFile.close();
}

User* Main::loginUser() {
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    for (auto& user : users) {
        if (user.getEmail() == email && user.getPassword() == password) {
            if (user.getRole() == "Admin") {
                return new Admin(user.getId(), user.getName(), user.getEmail(), user.getPassword(), user.getRole());
            } else if (user.getRole() == "Customer") {
                return new Customer(user.getId(), user.getName(), user.getEmail(), user.getPassword(), user.getRole());
            } else {
                return new User(user.getId(), user.getName(), user.getEmail(), user.getPassword(), user.getRole());
            }
        }
    }

    cout << "Invalid email or password.\n";
    return nullptr;
}

void Main::generateMostBookedEventsReport() {
    if (events.empty()) {
        cout << "No events to report." << endl;
        return;
    }

    // Sort events by bookings count in descending order
    std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.getBookedSeats() > b.getBookedSeats();
    });

    cout << "\nMost Booked Events Report:\n";
    cout << setw(10) << "Event ID" << setw(25) << "Event Name" << setw(15) << "Bookings Count\n";
    cout << string(50, '-') << endl;

    for (const auto& event : events) {
        cout << setw(10) << event.getEventID()
             << setw(25) << event.getEventName()
             << setw(15) << event.getBookedSeats() << endl;
    }
}