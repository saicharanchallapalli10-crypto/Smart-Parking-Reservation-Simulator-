#ifndef PRICINGENGINE_H
#define PRICINGENGINE_H

//creates PricingEngine class
class PricingEngine {
private:
    double baseRate;

public:
    PricingEngine();

    double getBaseRate() const;
    double calculateFee(int takenSpots) const;
};

#endif