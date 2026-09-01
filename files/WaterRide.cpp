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
        if (currentRiders >= capacity) {
            std::cout << getName() << " water ride at capacity, pausing boarding." << std::endl;
            close();
        } else {
            std::cout << getName() << " water ride has room, remaining open. (" << currentRiders << "/" << capacity << ")" << std::endl;
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
    : EventUnit(rideName), capacity(rideCapacity), isOpen(false), currentRiders(0){}

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

void WaterRide::boardGuests(int count)
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

int WaterRide::getCurrentRiders() const
{
    return currentRiders;
}

void WaterRide::setMaintenanceMode(bool active)
{
    underMaintenance = active;
    if (active && isOpen) close();
    std::cout << getName() << (active ? " entering maintenance." : " maintenance complete.") << std::endl;
}

void WaterRide::recordRide(int guestCount)
{
    timesRidden += guestCount;
    std::cout << getName() << " has now carried " << timesRidden << " guest(s) total." << std::endl;
}

int WaterRide::getPopularity() const
{
    return timesRidden;
}