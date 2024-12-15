#pragma once

#include <iostream>
#include <string>
#include "Service.h"
using namespace std;

class NotificationService : public Service {
public:
    void sendNotification(const string& message) {
        cout << "Notification Sent: " << message << "\n";
    }

    void execute() override {
        cout << "Notification Service Executed\n";
    }
};

