#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Room.h"
#include "Service.h"
using namespace std;

class BookingService : public Service {
private:
    vector<Room> rooms;

public:
    BookingService() {
        rooms.emplace_back("Room 101", 150.00);
        rooms.emplace_back("Room 102", 200.00);
        rooms.emplace_back("Room 103", 100.00);
    }

    void listAvailableRooms() const {
        cout << "\nAvailable Rooms:\n";
        cout << setw(10) << "Room" << setw(15) << "Price" << setw(15) << "Status\n";

        for (auto& room : rooms) {
            string status = (room.status == RoomStatus::Available) ? "Available" : (room.status == RoomStatus::Pending) ? "Pending" : "Booked";

            cout << setw(10) << room.name
                << setw(15) << room.price
                << setw(15) << status << "\n";
        }
    }


    bool bookRoom(const string& roomName) {
        for (auto& room : rooms) {
            if (room.name == roomName) {
                if (room.status == RoomStatus::Available) {
                    room.status = RoomStatus::Pending;
                    cout << "Room " << room.name << " is now pending payment.\n";
                    return true;
                }
                else if (room.status == RoomStatus::Pending) {
                    cout << "Room " << room.name << " is already pending payment.\n";
                    return false;
                }
                else if (room.status == RoomStatus::Booked) {
                    cout << "Room " << room.name << " is already booked.\n";
                    return false;
                }
            }
        }
        cout << "Room " << roomName << " does not exist.\n";
        return false;
    }

    bool markRoomAsPaid(const string& roomName) {
        for (auto& room : rooms) {
            if (room.name == roomName) {
                if (room.status == RoomStatus::Pending) {
                    room.status = RoomStatus::Booked;
                    cout << "Room " << room.name << " has been successfully booked.\n";
                    return true;
                }
                else {
                    cout << "Room " << room.name << " is not pending payment.\n";
                    return false;
                }
            }
        }
        cout << "Room " << roomName << " does not exist.\n";
        return false;
    }

    bool deleteRoom(const string& roomName) {
        auto it = find_if(rooms.begin(), rooms.end(), [&](const Room& room) {
            return room.name == roomName;
            });

        if (it != rooms.end()) {
            rooms.erase(it);
            cout << "Room " << roomName << " deleted successfully.\n";
            return true;
        }
        else {
            cout << "Room " << roomName << " does not exist.\n";
            return false;
        }
    }

    bool modifyRoomPrice(const string& roomName, double newPrice) {
        for (auto& room : rooms) {
            if (room.name == roomName) {
                room.price = newPrice;
                cout << "Room " << roomName << " price updated to $" << newPrice << ".\n";
                return true;
            }
        }
        cout << "Room " << roomName << " does not exist.\n";
        return false;
    }

    bool modifyRoomAvailability(const string& roomName, bool isAvailable) {
        for (auto& room : rooms) {
            if (room.name == roomName) {
                room.status = isAvailable ? RoomStatus::Available : RoomStatus::Booked;
                cout << "Room " << roomName << " availability updated to "
                    << (isAvailable ? "Available" : "Booked") << ".\n";
                return true;
            }
        }
        cout << "Room " << roomName << " does not exist.\n";
        return false;
    }


    void searchRoomsByPrice(double minPrice, double maxPrice) const {

        if (minPrice > maxPrice) {
            cout << "\nInvalid Range\n";
            return;
        }

        cout << "\nRooms in Price Range $" << minPrice << " - $" << maxPrice << ":\n";
        cout << setw(10) << "Room" << setw(15) << "Price" << setw(15) << "Status\n";

        bool found = false;
        for (const auto& room : rooms) {
            if (room.price >= minPrice && room.price <= maxPrice) {
                found = true;
                string status = (room.status == RoomStatus::Available) ? "Available"
                    : (room.status == RoomStatus::Pending) ? "Pending"
                    : "Booked";

                cout << setw(10) << room.name
                    << setw(15) << room.price
                    << setw(15) << status << "\n";
            }
        }

        if (!found) {
            cout << "No rooms found in this price range.\n";
        }
    }

    
    void searchRoomsByAvailability(bool isAvailable) const {
        cout << "\n" << (isAvailable ? "Available" : "Booked") << " Rooms:\n";
        cout << setw(10) << "Room" << setw(15) << "Price" << setw(15) << "Status\n";

        bool found = false;
        for (const auto& room : rooms) {
            if ((isAvailable && room.status == RoomStatus::Available) ||
                (!isAvailable && room.status == RoomStatus::Booked)) {
                found = true;
                string status = (room.status == RoomStatus::Available) ? "Available"
                    : (room.status == RoomStatus::Pending) ? "Pending"
                    : "Booked";

                cout << setw(10) << room.name
                    << setw(15) << room.price
                    << setw(15) << status << "\n";
            }
        }

        if (!found) {
            cout << "No " << (isAvailable ? "available" : "booked") << " rooms found.\n";
        }
    }


    double getRoomPrice(const string& roomName) const {
        for (const auto& room : rooms) {
            if (room.name == roomName) {
                return room.price;
            }
        }
        cout << "Room " << roomName << " not found.\n";
        return 0.0;
    }


    vector<Room>& getRooms() {
        return rooms;
    }

    void execute() override {
        cout << "Booking Service Executed\n";
    }
};

