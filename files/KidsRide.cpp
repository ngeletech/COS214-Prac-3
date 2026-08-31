#include "KidsRide.h"

KidsRide::KidsRide(const std::string& rideName, int rideCapacity) 
    : EventUnit(rideName), capacity(rideCapacity), isOpen(false){}

void KidsRide::open() {

    isOpen = true;
    std::cout << " Ride " << getName() << " is now open." << std::endl;
}
    
void KidsRide::close() {

    isOpen = true;
    std::cout << " Ride " << getName() << " is now closed." << std::endl;
}
    
void KidsRide::reportStatus() const {

    std::cout << getName() <<" status: " << (isOpen ? "open" : "closed")
    << ", capacity: " << capacity << std::endl;
}
    
int KidsRide::getCapacity() const {
    return capacity;
}