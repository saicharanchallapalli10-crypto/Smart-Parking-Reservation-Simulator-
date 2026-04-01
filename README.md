Smart Parking Reservation Simulator
Sitarama Challapalli Adrian Zielinski John Nevin
This project is supposed to create a smart parking reservation system so users are able to reserve parking spots and be charged a dynamic fee based on lot occupancy and duration.

The main functionalities of the program are to:
-Register new users with a name and car model
-Reserve available parking spots for a specific number of hours
-Unoccupy a parking spot when a user leaves
-Check availability of parking spots
-Calculate a parking fee based on occupancy and hours

The OOP Design Summary:

User: Represents the person parking. The class stores the user's name and car model. This model also handles all registration and information display.

ParkingSpot: Represents an individual spot. Manages the "availability state" of parking, assignments of parking to the user, and reporting the current status of parking spots.

PricingEngine: Calculates all of the fee calculations. Computes cost based on a base rate, number of occupied spots, and the duration of hours parked.

Tools and Technology Used:

Language: C++
Compiler: g++
IDE: Visual Studio
Repository: Github

Folder Structure:

Smart-Parking-Reservation-Simulator-
    ParkingSpot.cpp
    ParkingSpot.h
    ParkingEngine.cpp
    ParkingEngine.h
    User.cpp
    User.h
    README.md

Project Goals:

-Demonstrate understanding of OOP principles such as encapsulation and class composition
-Model a practical real world system using multiple classes
-Implement dynamic pricing logic that responds to various conditions
-Create efficient code as a team with comments and well defind classes