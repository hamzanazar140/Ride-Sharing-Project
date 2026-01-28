#include <iostream>
#include "RideShareSystem.h"
using namespace std;

int main() {
    RideShareSystem system;
    int choice;

    do {
        cout << "\n--- Ride Share System ---\n";
        cout << "1. Add Driver\n";
        cout << "2. Add Rider\n";
        cout << "3. Book Ride\n";
        cout << "4. Complete Ride\n";
        cout << "5. Cancel Ride\n";
        cout << "6. View Ride History\n";
        cout << "7. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addDriver(); break;
            case 2: system.addRider(); break;
            case 3: system.bookRide(); break;
            case 4: system.completeRide(); break;
            case 5: system.cancelRide(); break;
            case 6: system.viewHistory(); break;
            case 7: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
