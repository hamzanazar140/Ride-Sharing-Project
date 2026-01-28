#ifndef DRIVER_H
#define DRIVER_H

class Driver {
public:
    int id;
    char name[20];
    bool available;

    Driver();
    Driver(int, const char*);
};

#endif
