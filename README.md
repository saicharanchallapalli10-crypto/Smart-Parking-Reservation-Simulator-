**Very important note:**
**It is showing, I Sitarama Challapalli, added 40k new lines of code, this is NOT correct. httplib.h in the include folder, is a file that had to be installed on my machine through the vscode terminal. This file is 20k lines of code, thus when I pushed my commits multiple times, it says I have 40k lines added to this project. That is not correct, I did not write 20k lines of code, those are program files. httplib.h is required so that our program can run on a website. Please subtract 39,300 lines when looking at the commit history. I roughly only have around 400 lines of code committed, not including the AI generated one for the only the UI**

---

# Smart Parking Reservation Simulator

**Names:** Sitarama Challapalli, Adrian Zielinski, John Nevin

This project is supposed to create a smart parking reservation system so users are able to reserve parking spots and be charged a dynamic fee based on lot occupancy and duration.

---

## Main Functionalities

- Register new users with a name and car model
- Reserve available parking spots for a specific number of hours
- Unoccupy a parking spot when a user leaves
- Check availability of parking spots
- Calculate a parking fee based on occupancy and hours

---

## OOP Design Summary

**User:** Represents the person parking. The class stores the user's name and car model. This model also handles all registration and information display.

**ParkingSpot:** Represents an individual spot. Manages the "availability state" of parking, assignments of parking to the user, and reporting the current status of parking spots.

**PricingEngine:** Calculates all of the fee calculations. Computes cost based on a base rate, number of occupied spots, and the duration of hours parked.

---

## Tools and Technology Used

- **Language:** C++, very little html and Java Script
- **Compiler:** g++
- **IDE:** Visual Studio
- **Repository:** Github

---

## Folder Structure

```
Smart-Parking-Reservation-Simulator/
├── src/
│   ├── User.cpp
│   ├── User.h
│   ├── ParkingSpot.cpp
│   ├── ParkingSpot.h
│   ├── PricingEngine.cpp
│   └── PricingEngine.h
├── UI-aigencode-onlyforUI/
│   ├── main.cpp
│   ├── style.css
│   └── home.html
├── include/
│   └── httplib.h
└── README.md
```

---

## Project Goals

- Demonstrate understanding of OOP principles such as encapsulation and class composition
- Model a practical real world system using multiple classes
- Implement dynamic pricing logic that responds to various conditions
- Create efficient code as a team with comments and well defined classes

---

## GitHub Repository Purpose

The repository contains the full source code of our Smart Parking Reservation Simulator in C++. It allows us to collaborate and maintain control of various versions of the project.

---

## How to Run the Program

**Make sure to accses the folder in which the project is in, cd..., then do the following***

```bash
# 1. Compile
g++ UI-aigencode-onlyforUI/main.cpp src/User.cpp src/ParkingSpot.cpp src/PricingEngine.cpp -Iinclude -Isrc -std=c++17 -o parking_server

# 2. Run
./parking_server
```

---

## What Has Been Implemented So Far (Iteration 05 April 1)

- **User class:** constructors, getters, `registerUser()`, `getUserInfo()`
- **ParkingSpot class:** constructors, getters, `reserveSpot()`, `releaseSpot()`, `checkSpot()`, `getStatusInfo()`
- **PricingEngine class:** constructor, `getBaseRate()`, `calculateFee(takenSpots, hours)`
- **Dynamic fee calculation:** base rate of $5.00 + $0.40 per occupied spot, multiplied by the amount of hours
- **Spot status logging** via `getStatusInfo()`

We still need to implement main.cpp, multi-spot management such as a class or array with spots, and persistent data storage.

---

## What Has Been Implemented After Iteration 05 (Finished!)

- All the AI gen code for only the UI
- We had to use strategic prompting over and over to get the AI to produce the UI we wanted
- The program now runs
