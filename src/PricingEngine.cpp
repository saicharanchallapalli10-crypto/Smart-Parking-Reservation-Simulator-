#include "PricingEngine.h"
#include <iostream>
using namespace std;

PricingEngine::PricingEngine() {
    baseRate = 5.00;
}

double PricingEngine::getBaseRate() const {
    return baseRate;
}

// The fee grows as the lot fills up, then that hourly price is multiplied by the stay length.
double PricingEngine::calculateFee(int takenSpots, int hours) const {
    return (baseRate + (takenSpots * 0.30)) * hours;
}
