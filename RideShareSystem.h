#ifndef RIDESHARESYSTEM_H
#define RIDESHARESYSTEM_H

#include "Driver.h"
#include "Rider.h"
#include "Ride.h"

class RideShareSystem {
private:
    Driver drivers[10];
    Rider riders[10];
    Ride rides[20];

    int driverCount;
    int riderCount;
    int rideCount;

public:
    RideShareSystem();

    void addDriver();
    void addRider();
    void bookRide();
    void completeRide();
    void cancelRide();
    void viewHistory();
};

#endif
