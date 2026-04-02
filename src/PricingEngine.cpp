#include "PricingEngine.h"
#include <iostream>
using namespace std;

//creates the baseRate of the prices used for the parking spots
PricingEngine::PricingEngine() {
    baseRate = 5.00;
}

// returns current baseRate value
double PricingEngine::getBaseRate() const {
    return baseRate;
}

// returns the updated baserate that increases by 30 cents for every parking spot taken, multiplied by hours
double PricingEngine::calculateFee(int takenSpots, int hours) const {
    return (baseRate + (takenSpots * 0.30)) * hours;
}