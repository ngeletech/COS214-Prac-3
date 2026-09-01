#include "KidsRide.h"

//--------Observer--------
void KidsRide::update(NoticeType notice) {

    switch (notice)
    {
    case NoticeType::WeatherAlert:
        std::cout << getName() << ": mild weather, remain open." << std::endl;
        break;
    case NoticeType::CapacityAlert:
        if (currentRiders >= capacity) {
            std::cout << getName() << " kids ride at capacity, pausing boarding." << std::endl;
            close();
        } else {
            std::cout << getName() << " kids ride has room, remaining open. (" << currentRiders << "/" << capacity << ")" << std::endl;
        }
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
    : EventUnit(rideName), capacity(rideCapacity), isOpen(false), currentRiders(0) {}

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

void KidsRide::boardGuests(int count)
{
    if (!isOpen)
    {
        std::cout << "Cannot board, ride is closed." << std::endl;
        return;
    }
    if (currentRiders + count > capacity)
    {
        std::cout << "Cannot board, would exceed capacity." << std::endl;
        return;
    }
    currentRiders += count;
    std::cout << count << " guest(s) boarded " << getName() << "." << std::endl;
}

int KidsRide::getCurrentRiders() const
{
    return currentRiders;
}

void KidsRide::setMaintenanceMode(bool active)
{
    underMaintenance = active;
    if (active && isOpen) close();
    std::cout << getName() << (active ? " entering maintenance." : " maintenance complete.") << std::endl;
}

void KidsRide::recordRide(int guestCount)
{
    timesRidden += guestCount;
    std::cout << getName() << " has now carried " << timesRidden << " guest(s) total." << std::endl;
}

int KidsRide::getPopularity() const
{
    return timesRidden;
}