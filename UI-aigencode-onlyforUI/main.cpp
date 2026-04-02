#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "httplib.h"
#include "User.h"
#include "ParkingSpot.h"
using namespace std;

string readFile(const string& path) {
    ifstream file(path);
    if (!file) {
        return "";
    }

    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

string escapeJson(const string& value) {
    string escaped;
    for (char c : value) {
        switch (c) {
            case '\\': escaped += "\\\\"; break;
            case '"': escaped += "\\\""; break;
            case '\n': escaped += "\\n"; break;
            case '\r': escaped += "\\r"; break;
            case '\t': escaped += "\\t"; break;
            default: escaped += c; break;
        }
    }
    return escaped;
}

string escapeHtml(const string& value) {
    string escaped;
    for (char c : value) {
        switch (c) {
            case '&': escaped += "&amp;"; break;
            case '<': escaped += "&lt;"; break;
            case '>': escaped += "&gt;"; break;
            case '"': escaped += "&quot;"; break;
            case '\'': escaped += "&#39;"; break;
            default: escaped += c; break;
        }
    }
    return escaped;
}

string formatCurrency(double amount) {
    ostringstream stream;
    stream << fixed << setprecision(2) << amount;
    return stream.str();
}

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

int countTakenSpots() {
    int takenSpots = 0;
    for (const ParkingSpot& spot : spots) {
        if (!spot.getIsAvailable()) {
            takenSpots++;
        }
    }
    return takenSpots;
}

string buildJsonResponse(bool success, const string& message, const string& fee = "") {
    const int takenSpots = countTakenSpots();
    const int availableSpots = 100 - takenSpots;

    ostringstream json;
    json << "{"
         << "\"success\":" << (success ? "true" : "false") << ","
         << "\"message\":\"" << escapeJson(message) << "\","
         << "\"fee\":\"" << escapeJson(fee) << "\","
         << "\"takenSpots\":" << takenSpots << ","
         << "\"availableSpots\":" << availableSpots
         << "}";
    return json.str();
}

string buildStatusPage() {
    const int takenSpots = countTakenSpots();
    const int availableSpots = 100 - takenSpots;

    ostringstream html;
    html << "<!DOCTYPE html>"
         << "<html lang=\"en\">"
         << "<head>"
         << "<meta charset=\"UTF-8\">"
         << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
         << "<title>Parking Status</title>"
         << "<style>"
         << "body{margin:0;font-family:Arial,sans-serif;background:#f5f7fa;color:#1f2937;}"
         << ".page{max-width:1100px;margin:0 auto;padding:32px 16px 48px;}"
         << ".top{display:flex;justify-content:space-between;align-items:center;gap:16px;flex-wrap:wrap;margin-bottom:24px;}"
         << "h1{margin:0 0 6px;font-size:32px;}"
         << "p{margin:0;color:#5b6472;}"
         << ".link{display:inline-block;padding:12px 16px;border-radius:999px;background:#111827;color:#fff;text-decoration:none;font-weight:600;}"
         << ".summary{display:grid;grid-template-columns:repeat(auto-fit,minmax(180px,1fr));gap:12px;margin-bottom:20px;}"
         << ".card{background:#fff;border:1px solid #e5e7eb;border-radius:16px;padding:16px;box-shadow:0 10px 24px rgba(15,23,42,0.06);}"
         << ".card strong{display:block;font-size:24px;margin-bottom:4px;}"
         << "table{width:100%;border-collapse:collapse;background:#fff;border:1px solid #e5e7eb;border-radius:16px;overflow:hidden;box-shadow:0 10px 24px rgba(15,23,42,0.06);}"
         << "th,td{padding:14px 16px;border-bottom:1px solid #e5e7eb;text-align:left;}"
         << "th{background:#f9fafb;font-size:14px;text-transform:uppercase;letter-spacing:0.04em;color:#6b7280;}"
         << "tr:last-child td{border-bottom:none;}"
         << ".status-open{color:#0f766e;font-weight:700;}"
         << ".status-taken{color:#b45309;font-weight:700;}"
         << "</style>"
         << "</head>"
         << "<body>"
         << "<div class=\"page\">"
         << "<div class=\"top\">"
         << "<div><h1>Parking Status</h1><p>All 100 spots and their current occupants.</p></div>"
         << "<a class=\"link\" href=\"/\">Back to Home</a>"
         << "</div>"
         << "<div class=\"summary\">"
         << "<div class=\"card\"><strong>" << takenSpots << "</strong><span>Occupied spots</span></div>"
         << "<div class=\"card\"><strong>" << availableSpots << "</strong><span>Available spots</span></div>"
         << "</div>"
         << "<table>"
         << "<thead><tr><th>Spot</th><th>Status</th><th>Occupant</th><th>Car Model</th><th>Hours</th></tr></thead>"
         << "<tbody>";

    for (const ParkingSpot& spot : spots) {
        const bool isAvailable = spot.getIsAvailable();
        html << "<tr>"
             << "<td>" << spot.getSpotNumber() << "</td>"
             << "<td class=\"" << (isAvailable ? "status-open" : "status-taken") << "\">"
             << (isAvailable ? "Available" : "Taken")
             << "</td>"
             << "<td>" << escapeHtml(spot.getAssignedTo()) << "</td>"
             << "<td>" << escapeHtml(spot.getCarModel()) << "</td>"
             << "<td>" << (isAvailable ? "-" : to_string(spot.getReservedHours())) << "</td>"
             << "</tr>";
    }

    html << "</tbody></table></div></body></html>";
    return html.str();
}

int main() {
    httplib::Server server;
    const string homePage = readFile("UI-aigencode-onlyforUI/home.html");
    const string styleSheet = readFile("UI-aigencode-onlyforUI/style.css");

    server.Get("/", [homePage](const httplib::Request&, httplib::Response& res) {
        if (homePage.empty()) {
            res.status = 500;
            res.set_content("Could not load home.html", "text/plain");
            return;
        }

        res.set_content(homePage, "text/html");
    });

    server.Get("/style.css", [styleSheet](const httplib::Request&, httplib::Response& res) {
        if (styleSheet.empty()) {
            res.status = 500;
            res.set_content("Could not load style.css", "text/plain");
            return;
        }

        res.set_content(styleSheet, "text/css");
    });

    server.Get("/summary", [](const httplib::Request&, httplib::Response& res) {
        const int takenSpots = countTakenSpots();
        const int availableSpots = 100 - takenSpots;

        ostringstream json;
        json << "{"
             << "\"takenSpots\":" << takenSpots << ","
             << "\"availableSpots\":" << availableSpots << ","
             << "\"baseRate\":5.00,"
             << "\"spotRate\":0.30"
             << "}";

        res.set_content(json.str(), "application/json");
    });

    server.Post("/reserve", [](const httplib::Request& req, httplib::Response& res) {
        try {
            string name = req.get_param_value("name");
            string carModel = req.get_param_value("carModel");
            int choice = stoi(req.get_param_value("spotNumber"));
            int hours = stoi(req.get_param_value("hours"));

            if (name.empty() || carModel.empty()) {
                res.status = 400;
                res.set_content(buildJsonResponse(false, "Please enter a name and car model."), "application/json");
                return;
            }

            if (choice < 1 || choice > 100) {
                res.status = 400;
                res.set_content(buildJsonResponse(false, "Spot number must be between 1 and 100."), "application/json");
                return;
            }

            if (hours < 1) {
                res.status = 400;
                res.set_content(buildJsonResponse(false, "Hours must be at least 1."), "application/json");
                return;
            }

            if (!spots[choice - 1].getIsAvailable()) {
                res.status = 409;
                res.set_content(buildJsonResponse(false, "Spot " + to_string(choice) + " is taken. Please choose another spot."), "application/json");
                return;
            }

            const int takenSpots = countTakenSpots();
            PricingEngine pricing;
            const double totalFee = pricing.calculateFee(takenSpots, hours);

            User user(name, carModel);
            spots[choice - 1].reserveSpot(user.getName(), user.getCarModel(), takenSpots, hours);

            const string formattedFee = "$" + formatCurrency(totalFee);
            const string message = "Reservation confirmed for spot " + to_string(choice) + ".";
            res.set_content(buildJsonResponse(true, message, formattedFee), "application/json");
        } catch (const exception&) {
            res.status = 400;
            res.set_content(buildJsonResponse(false, "Please enter valid reservation details."), "application/json");
        }
    });

    server.Post("/release", [](const httplib::Request& req, httplib::Response& res) {
        try {
            int choice = stoi(req.get_param_value("spotNumber"));

            if (choice < 1 || choice > 100) {
                res.status = 400;
                res.set_content(buildJsonResponse(false, "Spot number must be between 1 and 100."), "application/json");
                return;
            }

            if (spots[choice - 1].getIsAvailable()) {
                res.status = 409;
                res.set_content(buildJsonResponse(false, "Spot " + to_string(choice) + " is already available."), "application/json");
                return;
            }

            const string departingName = spots[choice - 1].getAssignedTo();
            spots[choice - 1].releaseSpot();
            res.set_content(buildJsonResponse(true, "Goodbye, " + departingName + "! Spot " + to_string(choice) + " is now available."), "application/json");
        } catch (const exception&) {
            res.status = 400;
            res.set_content(buildJsonResponse(false, "Please enter a valid spot number."), "application/json");
        }
    });

    server.Get("/check", [](const httplib::Request& req, httplib::Response& res) {
        try {
            int choice = stoi(req.get_param_value("spotNumber"));

            if (choice < 1 || choice > 100) {
                res.set_content("Invalid spot number. Please choose between 1 and 100.", "text/plain");
                return;
            }

            spots[choice - 1].checkSpot();
            res.set_content(spots[choice - 1].getStatusInfo(), "text/plain");
        } catch (const exception&) {
            res.status = 400;
            res.set_content("Please enter a valid spot number.", "text/plain");
        }
    });

    server.Get("/status", [](const httplib::Request&, httplib::Response& res) {
        res.set_content(buildStatusPage(), "text/html");
    });

    cout << "Server running on http://localhost:8080" << endl;
    server.listen("localhost", 8080);
    return 0;
}


