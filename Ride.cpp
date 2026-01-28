#include "Ride.h"
#include <iostream>
using namespace std;

Ride::Ride() {
    rideId = 0;
}

Ride::Ride(int rId, int rid, int did, const char* p, const char* d) {
    rideId = rId;
    riderId = rid;
    driverId = did;
    status = ASSIGNED;

    int i = 0;
    while (p[i] != '\0') {
        pickup[i] = p[i];
        i++;
    }
    pickup[i] = '\0';

    i = 0;
    while (d[i] != '\0') {
        drop[i] = d[i];
        i++;
    }
    drop[i] = '\0';
}
