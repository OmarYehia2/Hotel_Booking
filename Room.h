#pragma once

#include <string>
using namespace std;

enum class RoomStatus {
    Available,
    Pending,
    Booked
};

class Room {
public:
    string name;
    double price;
    RoomStatus status;

    Room(const string& roomName, double roomPrice, RoomStatus roomStatus = RoomStatus::Available)
        : name(roomName), price(roomPrice), status(roomStatus) {}
};


