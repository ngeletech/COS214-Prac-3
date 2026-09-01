#include "WaterRide.h"

//--------Observer--------
void WaterRide::update(NoticeType notice) {

    switch (notice)
    {
    case NoticeType::WeatherAlert:
        std::cout << getName() << ": closing due to lightning/electrical risk near water." << std::endl;
        close();
        break;
    case NoticeType::CapacityAlert:
        std::cout << getName() << ":Capacity alert acknowlegded." << std::endl;
        break;

    case NoticeType::OpenNotice:
        std::cout << "Opening water ride " << getName() << " for customers." << std::endl;
        open();
    break;

    case NoticeType::CloseNotice:
        std::cout << "Closing rollercoaster " << getName() << " for the day." << std::endl;
        close();
    break;

    case NoticeType::PauseNotice:
        std::cout << "Water ride " << getName() << " operations are pausing." << std::endl;
        close();
        break;

    case NoticeType::ResumeNotice:
        std::cout << "Water ride " << getName() << " operations are resuming." << std::endl;
        open();
        break;

    case NoticeType::EvacuationNotice:
        std::cout << "Evacuation notice received. Closing water ride " << getName() << " immediately." << std::endl;
        close();
        break;

    case NoticeType::RushHourNotice:
        std::cout << "Rush hour started. Water ride " << getName() << " should expect longer wait times." << std::endl;
        break;

    default:
        break;
    }
}

//--------Composite---------
WaterRide::WaterRide(const std::string& rideName, int rideCapacity) 
    : EventUnit(rideName), capacity(rideCapacity), isOpen(false){}

void WaterRide::open() {

    isOpen = true;
    std::cout << " Ride " << getName() << " is now open." << std::endl;
}
    
void WaterRide::close() {

    isOpen = false;
    std::cout << " Ride " << getName() << " is now closed." << std::endl;
}
    
void WaterRide::reportStatus() const {

    std::cout << getName() <<" status: " << (isOpen ? "open" : "closed")
              << ", capacity: " << capacity << std::endl;
}
    
int WaterRide::getCapacity() const {
    return capacity;
}