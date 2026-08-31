#include "KidsRide.h"

KidsRide::KidsRide(const std::string& rideName, int rideCapacity) {}

void KidsRide::open() {

    isOpen = true;
    std::cout << " Ride " << name << " is now open." << std::endl;
}
    
void KidsRide::close() {

    isOpen = true;
    std::cout << " Ride " << name << " is now closed." << std::endl;
}
    
void KidsRide::reportStatus() const {

    std::cout << name <<" status: " << (isOpen ? "open" : "closed")
        << ", capacity: " << capacity << std::endl;
}
    
int KidsRide::getCapacity() const {
    return capacity;
}