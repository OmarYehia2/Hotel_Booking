#pragma once

#include "AuthenticationService.h"
#include "BookingService.h"
#include "PaymentService.h"
#include "NotificationService.h"

class UserInterface {
private:
    AuthenticationService authService;
    BookingService bookingService;
    PaymentService paymentService;
    NotificationService notificationService;
    double totalPayment = 0.0;
    string pendingRoom;
public:
    void initialize() {
        authService.registerUser("admin", "123", false);
    }

    void registerUser(const string& username, const string& password) {
        authService.registerUser(username, password);
    }

    bool loginUser(const string& username, const string& password) {
        if (authService.login(username, password)) {
            cout << "Login Successful!\n";
            return true;
        }   
        else {
            cout << "Invalid Credentials.\n";
            return false;
        }
    }

    void showAvailableRooms() {
        bookingService.listAvailableRooms();
    }

    void bookRoom(const string& roomName) {
        if (bookingService.bookRoom(roomName)) {
            pendingRoom = roomName;
            totalPayment += bookingService.getRoomPrice(roomName);
            notificationService.sendNotification("Room " + roomName + " is now pending payment.");
        }
    }



    void makePayment() {
        if (totalPayment == 0.0 || pendingRoom.empty()) {
            cout << "No outstanding payment. Please book a room first.\n";
            return;
        }

        cout << "Total amount due: $" << totalPayment << "\n";
        cout << "Do you want to proceed with payment? (yes/no): ";
        string response;
        cin >> response;

        if (response == "yes" || response == "Yes") {
            paymentService.processPayment(totalPayment);
            if (bookingService.markRoomAsPaid(pendingRoom)) {
                pendingRoom.clear();
                totalPayment = 0.0;
            }
        }
        else {
            cout << "Payment cancelled. Amount due remains: $" << totalPayment << "\n";
        }
    }


    void addRoom(const string& roomName, double price) {
        bookingService.getRooms().emplace_back(roomName, price);
        cout << "Room " << roomName << " added successfully with a price of $" << price << ".\n";
    }

    void deleteRoom(const string& roomName) {
        if (!bookingService.deleteRoom(roomName)) {
            cout << "Failed to delete room. Check the room name and try again.\n";
        }
    }

    void modifyRoomPrice(const string& roomName, double newPrice) {
        if (!bookingService.modifyRoomPrice(roomName, newPrice)) {
            cout << "Failed to modify room price. Check the room name and try again.\n";
        }
    }

    void modifyRoomAvailability(const string& roomName, bool isAvailable) {
        if (!bookingService.modifyRoomAvailability(roomName, isAvailable)) {
            cout << "Failed to modify room availability. Check the room name and try again.\n";
        }
    }

    void searchByPrice(double minPrice, double maxPrice) {
        bookingService.searchRoomsByPrice(minPrice, maxPrice);
    }

    void searchByAvailability(bool isAvailable) {
        bookingService.searchRoomsByAvailability(isAvailable);
    }

};

