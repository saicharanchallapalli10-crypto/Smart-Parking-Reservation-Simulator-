#include "ParkingSpot.h"
#include <iostream>
using namespace std;

ParkingSpot::ParkingSpot(int number) {
    spotNumber = number;
    isAvailable = true;
    assignedTo = "Assigned to no one";
    carModel = "No car";
    reservedHours = 0;
}

int ParkingSpot::getSpotNumber() const {
    return spotNumber;
}

bool ParkingSpot::getIsAvailable() const {
    return isAvailable;
}

string ParkingSpot::getAssignedTo() const {
    return assignedTo;
}

string ParkingSpot::getCarModel() const {
    return carModel;
}

int ParkingSpot::getReservedHours() const {
    return reservedHours;
}

void ParkingSpot::reserveSpot(const string& userName, const string& userCarModel, int takenSpots, int hours) {
    if (isAvailable) {
        // The current app stores reservation data directly inside each spot object.
        isAvailable = false;
        assignedTo = userName;
        carModel = userCarModel;
        reservedHours = hours;

        cout << "Spot " << spotNumber << " successfully reserved for " << userName << endl;
        cout << "Car Model: " << carModel << endl;
        cout << "Reserved Hours: " << reservedHours << endl;
        cout << "Total Fee: $" << pricing.calculateFee(takenSpots, hours) << endl;
    } else {
        cout << "Spot " << spotNumber << " is already taken!" << endl;
    }
}

void ParkingSpot::releaseSpot() {
    // Reset the spot back to its default empty state.
    isAvailable = true;
    assignedTo = "Assigned to no one!";
    carModel = "No car!";
    reservedHours = 0;
    cout << "Spot " << spotNumber << " is now available." << endl;
}

void ParkingSpot::checkSpot() const {
    if (isAvailable) {
        cout << "Spot " << spotNumber << " is available." << endl;
    } else {
        cout << "Spot " << spotNumber << " is taken by " << assignedTo << " - " << carModel
             << " for " << reservedHours << " hours" << endl;
    }
}

// This older text format is still used by the simple /check route.
string ParkingSpot::getStatusInfo() const {
    if (isAvailable) {
        return "Spot " + to_string(spotNumber) + " ################ Assigned to no one! ###################No car!###############0 hours";
    } else {
        return "Spot " + to_string(spotNumber) + " --------------------- " + assignedTo + " --------------" + carModel
            + " -------------- " + to_string(reservedHours) + " hours";
    }
}
