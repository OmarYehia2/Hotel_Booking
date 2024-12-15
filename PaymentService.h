#pragma once


#include <iostream>
#include "Service.h"
using namespace std;

class PaymentService : public Service {
public:
    void processPayment(double amount) {
        cout << "Payment of $" << amount << " processed successfully.\n";
    }

    void execute() override {
        cout << "Payment Service Executed\n";
    }
};
