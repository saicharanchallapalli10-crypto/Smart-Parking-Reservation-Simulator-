#include "User.h"
#include <iostream>
using namespace std;

User::User(const string& userName, const string& userCarModel) {
    name = userName;
    carModel = userCarModel;
}

string User::getName() const {
    return name;
}

string User::getCarModel() const {
    return carModel;
}

// These console helpers are simple, but they are still useful when testing the class by itself.
void User::registerUser() {
    cout << "User registered successfully" << endl;
    cout << "Name: " << name << endl;
    cout << "Car Model: " << carModel << endl;
}

void User::getUserInfo() const {
    cout << "Name: " << name << endl;
    cout << "Car Model: " << carModel << endl;
}
