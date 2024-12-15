#include <iostream>
#include "UserInterface.h"

using namespace std;

int main() {
    UserInterface ui;
    ui.initialize();

    string username, password;
    bool isLoggedIn = false , isAdmin = false;

    cout << "Welcome to the Hotel Booking System\n";
    while (!isLoggedIn) {
        cout << "\nPlease choose an option:\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            isLoggedIn = ui.loginUser(username, password);
            if (isLoggedIn && username == "admin") {
                isAdmin = true;
            }
        }
        else if (choice == 2) {
            cout << "Enter a new username: ";
            cin >> username;
            cout << "Enter a new password: ";
            cin >> password;

            ui.registerUser(username, password);
            cout << "You can now log in with your new credentials.\n";
        }
        else {
            cout << "Invalid choice. Please choose 1 to Login or 2 to Register.\n";
        }
    }

    if (isAdmin) {
        int choice;
        while (true) {
            cout << "\nAdmin Menu\n";
            cout << "1. Add Room\n";
            cout << "2. Show Available Rooms\n";
            cout << "3. Delete Room\n";
            cout << "4. Modify Room Price\n";
            cout << "5. Modify Room Availability\n";
            cout << "6. Search Rooms\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                string roomName;
                double price;
                cout << "Enter the room name: ";
                cin.ignore();
                getline(cin, roomName);
                cout << "Enter the room price: ";
                cin >> price;

                ui.addRoom(roomName, price);
            }
            else if (choice == 2) {
                ui.showAvailableRooms();
            }
            else if (choice == 3) {
                ui.showAvailableRooms();
                cout << endl;
                string roomName;
                cout << "Enter the room name to delete: ";
                cin.ignore();
                getline(cin, roomName);
                ui.deleteRoom(roomName);
            }
            else if (choice == 4) {
                ui.showAvailableRooms();
                cout << endl;
                string roomName;
                double Nprice;
                cout << "Enter the room name to modify: ";
                cin.ignore();
                getline(cin, roomName);
                cout << "Enter the new price: ";
                cin >> Nprice;
                ui.modifyRoomPrice(roomName, Nprice);
            }
            else if (choice == 5) {
                ui.showAvailableRooms();
                cout << endl;
                string roomName;
                int availabilityChoice;
                cout << "Enter the room name to modify: ";
                cin.ignore();
                getline(cin, roomName);
                cout << "Set availability: 1 for Available, 0 for Booked: ";
                cin >> availabilityChoice;

                ui.modifyRoomAvailability(roomName, availabilityChoice == 1);
            }
            else if (choice == 6) {
                int searchChoice;
                cout << "\nSearch Options:\n";
                cout << "1. Search by Price Range\n";
                cout << "2. Search by Availability\n";
                cout << "Enter your choice: ";
                cin >> searchChoice;

                if (searchChoice == 1) {
                    double minPrice, maxPrice;
                    cout << "Enter minimum price: ";
                    cin >> minPrice;
                    cout << "Enter maximum price: ";
                    cin >> maxPrice;
                    ui.searchByPrice(minPrice, maxPrice);
                }
                else if (searchChoice == 2) {
                    int availabilityChoice;
                    cout << "Enter 1 for Available, 0 for Booked: ";
                    cin >> availabilityChoice;
                    ui.searchByAvailability(availabilityChoice == 1);
                }
                else {
                    cout << "Invalid choice. Returning to Admin Menu.\n";
                }
            }
            else if (choice == 7) {
                cout << "Exiting Admin Menu. Goodbye!\n";
                return 0;
            }
            else {
                cout << "Invalid choice. Try again.\n";
            }
        }
    }


    int choice;
    string roomName, s;

    while (true) {
        cout << "\nHotel Booking System\n";
        cout << "1. Show Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Make Payment\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            ui.showAvailableRooms();
        }
        else if (choice == 2) {
            cout << "Enter room name to book: ";
            cin.ignore();
            getline(cin, roomName);
            ui.bookRoom(roomName);
        }
        else if (choice == 3) {
            ui.makePayment();
        }
        else if (choice == 4) {
            cout << "Exiting the system. Goodbye!\n";
            return 0;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
