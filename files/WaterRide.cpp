#include "WaterRide.h"

WaterRide::WaterRide(const std::string& rideName, int rideCapacity) 
    : name(rideName), capacity(rideCapacity), isOpen(false){}

void WaterRide::open() {

    isOpen = true;
    std::cout << " Ride " << name << " is now open." << std::endl;
}
    
void WaterRide::close() {

    isOpen = true;
    std::cout << " Ride " << name << " is now closed." << std::endl;
}
    
void WaterRide::reportStatus() const {

    std::cout << name <<" status: " << (isOpen ? "open" : "closed")
              << ", capacity: " << capacity << std::endl;
}
    
int WaterRide::getCapacity() const {
    return capacity;
}