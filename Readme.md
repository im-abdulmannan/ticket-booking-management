# Ticket Booking System (CLI-Based)

This project simulates a Command-Line Interface (CLI)-based ticket booking system, allowing users to book tickets for events while practicing core OOP principles in C++. The payment module is excluded, simplifying the implementation while still covering essential programming concepts like encapsulation, inheritance, polymorphism, abstraction, and generalization.

## Core Requirements

1. User Roles
    - Admin:
        - Manage events or trips:
        - Add new events.
        - Update existing events (e.g., change available seats, time, or date).
        - Delete outdated or canceled events.
        - View all customer bookings.
        - Generate reports (e.g., most booked events, total revenue).
    - Customer:
        - Register and log in.
        - Search for events by name, date, or location.
        - Book tickets for a specific event.
        - View their booking history.

2. Booking Functionality
    - Customers can:
        - Select tickets for a specific event, specifying the quantity.
        - Receive a confirmation with a unique booking ID.
        - View their booking history via a command.
    - Admins can:
        - Limit the number of seats available for each event.
        - View details of all bookings for reporting purposes.

3. Event Management
    - Events should have:
        - Attributes such as EventID, EventName, Date, Time, Venue, and AvailableSeats.
        - Methods to allow Admins to add, update, and delete events.

4. Reporting
    - Admins can generate:
        - A summary of all events with their booking details.
        - The most popular events based on ticket sales.
        - Total tickets booked for each event.

5. Notifications
    - Console-based notifications:
        - Display a message when a booking is successfully made.
        - Notify Admins when an event is fully booked.

CLI Design

The system will have a menu-driven interface, allowing users to interact via text-based commands:

1. Main Menu
    - Options to log in or register.
2. Admin Menu:
    - Manage Events (Add, Update, Delete).
    - View Bookings.
    - Generate Reports.
    - Logout.
3. Menu:
    - Search Events.
    - Book Tickets.
    - View Booking History.
    - Logout.

## OOP Principles to Implement

1. Encapsulation
    - Keep sensitive data such as password, userDetails, and bookingHistory private.
    - Use public getter and setter methods for accessing/updating these details.

2. Inheritance
    - Create a base class User for common attributes like userID, name, and email, with methods like login() and logout().
    - Derive:
        - Admin: Includes methods for managing events and generating reports.
        - Customer: Includes methods for searching events and booking tickets.

3. Polymorphism
    - Implement method overriding:
        - For example, displayMenu() behaves differently for Admins and Customers.
    - Use function overloading:
        - For example, searchEvent() can accept criteria such as name, date, or venue.

4. Abstraction
    - Use abstract classes or pure virtual functions:
        - Create a base Booking class with common attributes and methods.
        - Derive specific implementations for AdminBooking and CustomerBooking.

5. Generalization
    - Design a generic Ticket class:
        - Attributes: ticketID, eventDetails, seatCount.
        - Methods: displayTicketDetails().
        - Extend this class to handle different types of bookings if needed.

6. Association and Aggregation
    - Associate Event and Ticket:
        - Each Event has multiple associated Tickets.
        - Aggregate BookingHistory in the Customer class to track a user’s bookings.

## Proposed Class Design

### Classes:

1. User (Base Class):
    - Attributes: userID, name, email, password.
    - Methods: login(), logout().
2. Admin (Derived Class):
    - Methods: addEvent(), updateEvent(), deleteEvent(), generateReport().
3. Customer (Derived Class):
    - Attributes: bookingHistory.
    - Methods: searchEvents(), bookTickets(), viewBookingHistory().
4. Event:
    - Attributes: eventID, eventName, date, time, venue, availableSeats.
    - Methods: updateSeats(), displayEventDetails().
5. Ticket:
    - Attributes: ticketID, eventID, seatCount.
    - Methods: displayTicketDetails().
6. Booking:
    - Attributes: bookingID, customerID, eventID, seatCount.
    - Methods: confirmBooking().

### Features to Explore in C++

1. File Handling:
    - Store:
        - User data for registration and login validation.
        - Event details for persistence across sessions.
        - Booking history for both Admins and Customers.
        - Use file I/O (ifstream and ofstream) to save and retrieve data.
2. Dynamic Memory Management:
    - Use pointers for dynamically allocated objects (e.g., Event or Booking instances).
3. Standard Template Library (STL):
    - Use containers like vector or map for:
        - Storing collections of events, users, and bookings.
        - Use algorithms for sorting and searching.
4. Exception Handling:
    - Handle:
        - Invalid inputs (e.g., negative ticket quantity).
        - Booking failures (e.g., no available seats).
        - File errors (e.g., missing data file).

### Expected Workflow

1. Start Program:
    - Display the main menu for user interaction.
2. Admin Actions:
    - Add, update, or delete events.
    - Generate reports and view booking details.
3. Customer Actions:
    - Search for events by criteria.
    - Book tickets and view their history.
4. End Program:
    - Save all data (events and bookings) to files for future sessions.
