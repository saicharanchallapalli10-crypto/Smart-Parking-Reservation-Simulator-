#include "ParkingSpot.h"
#include <iostream>
using namespace std;

ParkingSpot::ParkingSpot(int number) {
    spotNumber = number;
    isAvailable = true;
    assignedTo = "Assigned to no one";
    carModel = "No car";
}
//gets parking spot number for a user
int ParkingSpot::getSpotNumber() const {
    return spotNumber;
}
//checks if parking spot is taken
bool ParkingSpot::getIsAvailable() const {
    return isAvailable;
}
//Sees who the parking spot is asinged to 
string ParkingSpot::getAssignedTo() const {
    return assignedTo;
}
//gets car model associated with parking spot
string ParkingSpot::getCarModel() const {
    return carModel;
}
// THis was very diffuclt oto program as a function. So applgies if it is janky or done wrong! Assigns parking spot to a user object
void ParkingSpot::reserveSpot(const string& userName, const string& userCarModel) {
    if (isAvailable) {
        isAvailable = false;
        assignedTo = userName;
        carModel = userCarModel;
        cout << "Spot " << spotNumber << " successfully reserved for " << userName << endl;
        cout << "Car Model: " << carModel << endl;
        cout << "Total Fee: $" << pricing.calculateFee() << endl;
    } else {
        cout << "Spot " << spotNumber << " is already taken!" << endl;
    }
}
//Release parking spot for a user
void ParkingSpot::releaseSpot() {
    isAvailable = true;
    assignedTo = "Assigned to no one!";
    carModel = "No car!";
    cout << "Spot " << spotNumber << " is now available." << endl;
}
//checks to see if parking spot is avliable 
void ParkingSpot::checkSpot() const {
    if (isAvailable) {
        cout << "Spot " << spotNumber << " is available." << endl;
    } else {
        cout << "Spot " << spotNumber << " is taken by " << assignedTo << " - " << carModel << endl;
    }
}
//This allows a log to be printed on the website to see who has which parking spot 
string ParkingSpot::getStatusInfo() const {
    if (isAvailable) {
        return "Spot " + to_string(spotNumber) + " ################ Assigned to no one! ###################No car!";
    } else {
        return "Spot " + to_string(spotNumber) + " --------------------- " + assignedTo + " --------------" + carModel;
    }
}