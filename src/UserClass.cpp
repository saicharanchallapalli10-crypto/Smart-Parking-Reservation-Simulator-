#include "User.h"
#include <iostream>
using namespace std;

//This allows a user object to be made w
User::User(const string& userName, const string& userCarModel) {
    name = userName;
    carModel = userCarModel;
}
//returns users name 
string User::getName() const {
    return name;
}
//Gets car model of user
string User::getCarModel() const {
    return carModel;
}
//allows user to register
void User::registerUser() {
    cout << "User registered successfully" << endl;
    cout << "Name: " << name << endl;
    cout << "Car Model: " << carModel << endl;
}
//gets user info from previous data 
void User::getUserInfo() const {
    cout << "Name: " << name << endl;
    cout << "Car Model: " << carModel << endl;
}