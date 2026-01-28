#include "RideShareSystem.h"
#include <iostream>
using namespace std;

RideShareSystem::RideShareSystem() {
    driverCount = 0;
    riderCount = 0;
    rideCount = 0;
}

void RideShareSystem::addDriver() {
    char name[20];
    cout << "Enter driver name: ";
    cin >> name;

    drivers[driverCount] = Driver(driverCount + 1, name);
    driverCount++;

    cout << "Driver added.\n";
}

void RideShareSystem::addRider() {
    char name[20];
    cout << "Enter rider name: ";
    cin >> name;

    riders[riderCount] = Rider(riderCount + 1, name);
    riderCount++;

    cout << "Rider added.\n";
}

void RideShareSystem::bookRide() {
    if (driverCount == 0 || riderCount == 0) {
        cout << "Add drivers and riders first.\n";
        return;
    }

    int riderId;
    cout << "Enter rider ID: ";
    cin >> riderId;

    int driverIndex = -1;
    for (int i = 0; i < driverCount; i++) {
        if (drivers[i].available) {
            driverIndex = i;
            break;
        }
    }

    if (driverIndex == -1) {
        cout << "No available drivers.\n";
        return;
    }

    char pickup[20], drop[20];
    cout << "Pickup location: ";
    cin >> pickup;
    cout << "Drop location: ";
    cin >> drop;

    drivers[driverIndex].available = false;
    rides[rideCount] = Ride(rideCount + 1, riderId, drivers[driverIndex].id, pickup, drop);
    rideCount++;

    cout << "Ride booked. Driver ID: " << drivers[driverIndex].id << endl;
}

void RideShareSystem::completeRide() {
    int id;
    cout << "Enter ride ID: ";
    cin >> id;

    for (int i = 0; i < rideCount; i++) {
        if (rides[i].rideId == id && rides[i].status == ASSIGNED) {
            rides[i].status = COMPLETED;

            for (int j = 0; j < driverCount; j++) {
                if (drivers[j].id == rides[i].driverId) {
                    drivers[j].available = true;
                }
            }
            cout << "Ride completed.\n";
            return;
        }
    }
    cout << "Invalid ride ID.\n";
}

void RideShareSystem::cancelRide() {
    int id;
    cout << "Enter ride ID: ";
    cin >> id;

    for (int i = 0; i < rideCount; i++) {
        if (rides[i].rideId == id && rides[i].status == ASSIGNED) {
            rides[i].status = CANCELLED;

            for (int j = 0; j < driverCount; j++) {
                if (drivers[j].id == rides[i].driverId) {
                    drivers[j].available = true;
                }
            }
            cout << "Ride cancelled.\n";
            return;
        }
    }
    cout << "Invalid ride ID.\n";
}

void RideShareSystem::viewHistory() {
    for (int i = 0; i < rideCount; i++) {
        cout << "Ride " << rides[i].rideId << " | Driver "
             << rides[i].driverId << " | Status ";

        if (rides[i].status == ASSIGNED) cout << "ASSIGNED";
        else if (rides[i].status == COMPLETED) cout << "COMPLETED";
        else cout << "CANCELLED";

        cout << endl;
    }
}
