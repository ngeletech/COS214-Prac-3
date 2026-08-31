#include "RollerCoasterRide.h"

RollerCoaster::RollerCoaster(const std::string& rideName, int rideCapacity) 
    : EventUnit(rideName), capacity(rideCapacity), isOpen(false), windSpeed(0) {}

void RollerCoaster::open() {

    if (windSpeed >= 60) {
        std::cout << " Ride " << getName() << " cannot open, wind speed too high." << std::endl;
        return;
    }
    isOpen = true;
    std::cout << " Ride " << getName() << " is now open." << std::endl;
}
    
void RollerCoaster::close() {

    isOpen = true;
    std::cout << " Ride " << getName() << " is now closed." << std::endl;
}
    
void RollerCoaster::reportStatus() const {

    std::cout << getName() <<" status: " << (isOpen ? "open" : "closed")
    << ", capacity: " << capacity << std::endl;
}
    
int RollerCoaster::getCapacity() const {
    return capacity;
}

void RollerCoaster::setWindSpeed(int speed) {
    
    windSpeed = speed;
    if (windSpeed >= 60 && isOpen) {
        std::cout << " Ride " << getName() << " is pausing due to high winds." << std::endl;
        isOpen = false;
    }
}