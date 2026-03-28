#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
//Making the class
class User {
private:
    string name;
    string carModel;

public:
    User(const string& userName, const string& userCarModel);

    string getName() const;
    string getCarModel() const;

    void registerUser();
    void getUserInfo() const;
};

#endif 