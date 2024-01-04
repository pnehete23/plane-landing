#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Plane {
    std::string flight_number;
    int wait_time;

    Plane(std::string fn, int wt) : flight_number(fn), wait_time(wt) {}
};

std::vector<Plane> landing_queue;

// This function keeps the vector sorted on insertion
void addPlane(Plane plane) {
    landing_queue.push_back(plane);
    std::sort(landing_queue.begin(), landing_queue.end(),
        [](const Plane & a, const Plane & b) -> bool
    { 
        return a.wait_time < b.wait_time; 
    });
}

void listPlanes() {
    if (landing_queue.empty()) {
        std::cout << "No planes waiting to land.\n";
    } else {
        for (auto &plane : landing_queue) {
            std::cout << "Flight number: " << plane.flight_number << " - Wait time: " << plane.wait_time << " mins\n";
        }
    }
}

void landPlane() {
    if (landing_queue.empty()) {
        std::cout << "No planes waiting to land.\n";
    } else {
        Plane p = landing_queue.front();
        landing_queue.erase(landing_queue.begin());
        std::cout << "Plane " << p.flight_number << " landed.\n";
    }
}

int main() {
    while (true) {
        std::cout << "Enter your option:\n"
            << "1. Make Landing request\n"
            << "2. Land plane\n"
            << "3. List all landing requests\n"
            << "4. Exit\n";

        int option;
        std::cin >> option;

        if (option == 1) {
            std::string flight_number;
            int wait_time;
            std::cout << "Enter flight number and wait time:\n";
            std::cin >> flight_number >> wait_time;
            addPlane(Plane(flight_number, wait_time));
        } else if (option == 2) {
            landPlane();
        } else if (option == 3) {
            listPlanes();
        } else if (option == 4) {
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}
