#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include <string>
#include "PricingEngine.h"
using namespace std;

//class decleration
class ParkingSpot {
//Private data types
private:
    int spotNumber;
    bool isAvailable;
    string assignedTo;
    string carModel;
    PricingEngine pricing;
//Public data types
public:
    ParkingSpot(int number);
    int getSpotNumber() const;
    bool getIsAvailable() const;
    string getAssignedTo() const;
    string getCarModel() const;
    void reserveSpot(const string& userName, const string& userCarModel);
    void releaseSpot();
    void checkSpot() const;
    string getStatusInfo() const;
};

#endif 