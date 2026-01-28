#include "Rider.h"
#include <iostream>
using namespace std;

Rider::Rider() {
    id = 0;
}

Rider::Rider(int i, const char* n) {
    id = i;

    int j = 0;
    while (n[j] != '\0') {
        name[j] = n[j];
        j++;
    }
    name[j] = '\0';
}
