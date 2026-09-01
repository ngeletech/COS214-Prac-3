#include "KidsRide.h"

//--------Observer--------
void KidsRide::update(NoticeType notice) {

    switch (notice)
    {
    case NoticeType::WeatherAlert:
        std::cout << getName() << ": mild weather, remain open." << std::endl;
        break;
    case NoticeType::CapacityAlert:
        std::cout << getName() << ":Capacity alert acknowlegded, pasuing to control queues." << std::endl;
        close();
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
        std::cout << "Kids ride " << getName() << " operations are pausing." << std::endl;
        close();
        break;

    case NoticeType::ResumeNotice:
        std::cout << "Kids ride " << getName() << " operations are resuming." << std::endl;
        open();
        break;

    case NoticeType::EvacuationNotice:
        std::cout << "Evacuation notice received. Closing kids ride " << getName() << " immediately." << std::endl;
        close();
        break;

    case NoticeType::RushHourNotice:
        std::cout << "Rush hour started. Kids ride " << getName() << " should expect longer wait times." << std::endl;
        break;

    default:
        break;
    }
}

//--------Composite---------
KidsRide::KidsRide(const std::string& rideName, int rideCapacity) 
    : EventUnit(rideName), capacity(rideCapacity), isOpen(false){}

void KidsRide::open() {

    isOpen = true;
    std::cout << " Ride " << getName() << " is now open." << std::endl;
}
    
void KidsRide::close() {

    isOpen = false;
    std::cout << " Ride " << getName() << " is now closed." << std::endl;
}
    
void KidsRide::reportStatus() const {

    std::cout << getName() <<" status: " << (isOpen ? "open" : "closed")
    << ", capacity: " << capacity << std::endl;
}
    
int KidsRide::getCapacity() const {
    return capacity;
}