#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
    string carModel;

public:
    // Constructor
    User(const string& userName, const string& userCarModel) {
        name = userName;
        carModel = userCarModel;
    }

    // Getters
    string getName() const {
        return name;
    }

    string getCarModel() const {
        return carModel;
    }

    // Methods
    void registerUser() {
        cout << "User registered successfully!" << endl;
        cout << "Name: " << name << endl;
        cout << "Car Model: " << carModel << endl;
    }

    void getUserInfo() const {
        cout << "Name: " << name << endl;
        cout << "Car Model: " << carModel << endl;
    }
};