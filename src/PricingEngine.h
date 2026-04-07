#ifndef PRICINGENGINE_H
#define PRICINGENGINE_H

// Handles the parking fee calculation.
class PricingEngine {
private:
    double baseRate;

public:
    // Starts the pricing engine with a fixed base rate.
    PricingEngine();

    // Returns the base rate before any occupancy increase is added.
    double getBaseRate() const;

    // Calculates the full parking fee using occupied spots and reserved hours.
    double calculateFee(int takenSpots, int hours) const;
};

#endif
