#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

// Stores the basic details entered by a driver.
// In the web flow, a User is created briefly and its values are copied into a ParkingSpot.
class User {
private:
    string name;
    string carModel;

public:
    // Creates a user with a name and car model.
    User(const string& userName, const string& userCarModel);

    // Returns the driver's name.
    string getName() const;

    // Returns the driver's car model.
    string getCarModel() const;

    // Prints a short confirmation to the console.
    void registerUser();

    // Prints the saved user details to the console.
    void getUserInfo() const;
};

#endif
