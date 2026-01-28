#include "Driver.h"
#include <iostream>
using namespace std;

Driver::Driver() {
    id = 0;
    available = true;
}

Driver::Driver(int i, const char* n) {
    id = i;
    available = true;

    int j = 0;
    while (n[j] != '\0') {
        name[j] = n[j];
        j++;
    }
    name[j] = '\0';
}
