#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <string>
#include "PricingEngine.h"
using namespace std;

// Represents one parking space in the lot.
// A spot tracks whether it is open, who is using it, which car is parked there,
// and how many hours the reservation lasts.
class ParkingSpot {
private:
    int spotNumber;
    bool isAvailable;
    string assignedTo;
    string carModel;
    int reservedHours;
    PricingEngine pricing;

public:
    // Creates a spot with a number and default empty values.
    ParkingSpot(int number);

    int getSpotNumber() const;
    bool getIsAvailable() const;
    string getAssignedTo() const;
    string getCarModel() const;
    int getReservedHours() const;

    // Stores reservation details inside this spot.
    void reserveSpot(const string& userName, const string& userCarModel, int takenSpots, int hours);

    // Clears the reservation and marks the spot as available again.
    void releaseSpot();

    // Prints a readable status message to the console.
    void checkSpot() const;

    // Returns a text version of the spot status for simple status output.
    string getStatusInfo() const;
};

#endif // PARKINGSPOT_H
