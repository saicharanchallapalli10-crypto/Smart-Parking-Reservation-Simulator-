#include <iostream>
#include <string>
#include "httplib.h"
#include "User.h"
#include "ParkingSpot.h"
using namespace std;

// Global array of 100 parking spots
ParkingSpot spots[100] = {
    ParkingSpot(1),   ParkingSpot(2),   ParkingSpot(3),   ParkingSpot(4),   ParkingSpot(5),
    ParkingSpot(6),   ParkingSpot(7),   ParkingSpot(8),   ParkingSpot(9),   ParkingSpot(10),
    ParkingSpot(11),  ParkingSpot(12),  ParkingSpot(13),  ParkingSpot(14),  ParkingSpot(15),
    ParkingSpot(16),  ParkingSpot(17),  ParkingSpot(18),  ParkingSpot(19),  ParkingSpot(20),
    ParkingSpot(21),  ParkingSpot(22),  ParkingSpot(23),  ParkingSpot(24),  ParkingSpot(25),
    ParkingSpot(26),  ParkingSpot(27),  ParkingSpot(28),  ParkingSpot(29),  ParkingSpot(30),
    ParkingSpot(31),  ParkingSpot(32),  ParkingSpot(33),  ParkingSpot(34),  ParkingSpot(35),
    ParkingSpot(36),  ParkingSpot(37),  ParkingSpot(38),  ParkingSpot(39),  ParkingSpot(40),
    ParkingSpot(41),  ParkingSpot(42),  ParkingSpot(43),  ParkingSpot(44),  ParkingSpot(45),
    ParkingSpot(46),  ParkingSpot(47),  ParkingSpot(48),  ParkingSpot(49),  ParkingSpot(50),
    ParkingSpot(51),  ParkingSpot(52),  ParkingSpot(53),  ParkingSpot(54),  ParkingSpot(55),
    ParkingSpot(56),  ParkingSpot(57),  ParkingSpot(58),  ParkingSpot(59),  ParkingSpot(60),
    ParkingSpot(61),  ParkingSpot(62),  ParkingSpot(63),  ParkingSpot(64),  ParkingSpot(65),
    ParkingSpot(66),  ParkingSpot(67),  ParkingSpot(68),  ParkingSpot(69),  ParkingSpot(70),
    ParkingSpot(71),  ParkingSpot(72),  ParkingSpot(73),  ParkingSpot(74),  ParkingSpot(75),
    ParkingSpot(76),  ParkingSpot(77),  ParkingSpot(78),  ParkingSpot(79),  ParkingSpot(80),
    ParkingSpot(81),  ParkingSpot(82),  ParkingSpot(83),  ParkingSpot(84),  ParkingSpot(85),
    ParkingSpot(86),  ParkingSpot(87),  ParkingSpot(88),  ParkingSpot(89),  ParkingSpot(90),
    ParkingSpot(91),  ParkingSpot(92),  ParkingSpot(93),  ParkingSpot(94),  ParkingSpot(95),
    ParkingSpot(96),  ParkingSpot(97),  ParkingSpot(98),  ParkingSpot(99),  ParkingSpot(100)
};

int main() {
    httplib::Server server;

    // Reserve a spot
    server.Post("/reserve", [](const httplib::Request& req, httplib::Response& res) {
        string name       = req.get_param_value("name");
        string carModel   = req.get_param_value("carModel");
        int choice        = stoi(req.get_param_value("spotNumber"));
        int hours         = stoi(req.get_param_value("hours"));

        // Validate spot number
        if (choice < 1 || choice > 100) {
            res.set_content("Invalid spot number. Please choose between 1 and 100.", "text/plain");
            return;
        }

        // Count taken spots for pricing
        int takenSpots = 0;
        for (int i = 0; i < 100; i++) {
            if (!spots[i].getIsAvailable()) takenSpots++;
        }

        User user(name, carModel);
        spots[choice - 1].reserveSpot(user.getName(), user.getCarModel(), takenSpots, hours);
        res.set_content("Spot " + to_string(choice) + " reserved for " + name, "text/plain");
    });

    // Release a spot
    server.Post("/release", [](const httplib::Request& req, httplib::Response& res) {
        int choice = stoi(req.get_param_value("spotNumber"));

        if (choice < 1 || choice > 100) {
            res.set_content("Invalid spot number. Please choose between 1 and 100.", "text/plain");
            return;
        }

        spots[choice - 1].releaseSpot();
        res.set_content("Spot " + to_string(choice) + " has been released.", "text/plain");
    });

    // Check a single spot
    server.Get("/check", [](const httplib::Request& req, httplib::Response& res) {
        int choice = stoi(req.get_param_value("spotNumber"));

        if (choice < 1 || choice > 100) {
            res.set_content("Invalid spot number. Please choose between 1 and 100.", "text/plain");
            return;
        }

        spots[choice - 1].checkSpot();
        res.set_content(spots[choice - 1].getStatusInfo(), "text/plain");
    });

    // View all spots - used for the status page
    server.Get("/status", [](const httplib::Request& req, httplib::Response& res) {
        string result = "";
        for (int i = 0; i < 100; i++) {
            result += spots[i].getStatusInfo() + "\n";
        }
        res.set_content(result, "text/plain");
    });

    cout << "Server running on http://localhost:8080" << endl;
    server.listen("localhost", 8080);
    return 0;
}
