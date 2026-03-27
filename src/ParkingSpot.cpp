#include <iostream>
#include <string>
#include "PricingEngine.cpp"
using namespace std;

class ParkingSpot {
private:
    int spotNumber;
    bool isAvailable;
    string assignedTo;
    string carModel;
    PricingEngine pricing;

public:
    // Constructor
    ParkingSpot(int number) {
        spotNumber = number;
        isAvailable = true;
        assignedTo = "Assigned to no one";
        carModel = "No car";
    }

    // Getters
    int getSpotNumber() const {
    return spotNumber;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    string getAssignedTo() const {
    return assignedTo;
    }

    string getCarModel() const {
        return carModel;
    }

    // THis was very diffuclt oto program as a function. So applgies if it is janky or done wrong!
    void reserveSpot(const string& userName, const string& userCarModel) {
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
    void releaseSpot() {
      isAvailable = true;
        assignedTo = "Assigned to no one!";
    carModel = "No car!";
        cout << "Spot " << spotNumber << " is now available." << endl;
    }

    void checkSpot() const {
        if (isAvailable) {
            cout << "Spot " << spotNumber << " is available." << endl;
        } else {
            cout << "Spot " << spotNumber << " is taken by " << assignedTo << " - " << carModel << endl;
        }
    }

    // Returns spot info as a string for the status page
    string getStatusInfo() const {
        if (isAvailable) {
     return "Spot " + to_string(spotNumber) + " ################ Assigned to no one! ###################No car!";
        } else {
            return "Spot " + to_string(spotNumber) + " --------------------- " + assignedTo + " --------------" + carModel;
        }
    }
};