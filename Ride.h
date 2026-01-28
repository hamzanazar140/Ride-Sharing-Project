#ifndef RIDE_H
#define RIDE_H

enum RideStatus {
    ASSIGNED,
    COMPLETED,
    CANCELLED
};

class Ride {
public:
    int rideId;
    int riderId;
    int driverId;
    char pickup[20];
    char drop[20];
    RideStatus status;

    Ride();
    Ride(int, int, int, const char*, const char*);
};

#endif
