#pragma once

#include <unordered_map>
#include <string>
#include <iostream>
#include "Service.h"
using namespace std;

class AuthenticationService : public Service {
private:
    unordered_map<string, string> users;

public:
    void registerUser(const string& username, const string& password, bool showMessage = true) {
        if (users.find(username) != users.end()) {
            if (showMessage) {
                cout << "User already exists.\n";
            }
        }
        else {
            users[username] = password;
            if (showMessage) {
                cout << "Registration successful for user: " << username << "\n";
            }
        }
    }


    bool login(const string& username, const string& password) {
        return users.find(username) != users.end() && users[username] == password;
    }

    void execute() override {
        cout << "Authentication Service Executed\n";
    }
};

