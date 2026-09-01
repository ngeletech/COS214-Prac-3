#include "RollerCoasterRide.h"

//--------Observer--------
void RollerCoasterRide::update(NoticeType notice) {

    switch (notice)
    {
    case NoticeType::WeatherAlert:
        setWindSpeed(70);
            close();
        break;
    case NoticeType::CapacityAlert:
        if (currentRiders >= capacity) {
            std::cout << getName() << " rollercoaster at capacity, pausing boarding." << std::endl;
            close();
        } else {
            std::cout << getName() << " rollercoaster has room, remaining open. (" << currentRiders << "/" << capacity << ")" << std::endl;
        }
        break;

    case NoticeType::OpenNotice:
        std::cout << "Opening rollercoaster " << getName() << " for customers." << std::endl;
        open();
    break;

    case NoticeType::CloseNotice:
        std::cout << "Closing rollercoaster " << getName() << " for the day." << std::endl;
        close();
    break;

    case NoticeType::PauseNotice:
        std::cout << "Rollercoaster ride " << getName() << " operations are pausing." << std::endl;
        close();
        break;

    case NoticeType::ResumeNotice:
        if (windSpeed < 60) {
            std::cout << "Rollercoaster " << getName() << " operations are resuming." << std::endl;
            open();
        }
        break;

    case NoticeType::EvacuationNotice:
        std::cout << "Evacuation notice received. Closing rollercoaster " << getName() << " immediately." << std::endl;
        close();
        break;

    case NoticeType::RushHourNotice:
        std::cout << "Rush hour started. Rollercoaster " << getName() << " should expect longer wait times." << std::endl;
        break;

    default:
        break;
    }
}

//--------Composite---------
RollerCoasterRide::RollerCoasterRide(const std::string& rideName, int rideCapacity) 
    : EventUnit(rideName), capacity(rideCapacity), isOpen(false), windSpeed(0), currentRiders(0) {}

void RollerCoasterRide::open() {

    if (windSpeed >= 60) {
        std::cout << " Ride " << getName() << " cannot open, wind speed too high." << std::endl;
        return;
    }
    isOpen = true;
    std::cout << " Ride " << getName() << " is now open." << std::endl;
}
    
void RollerCoasterRide::close() {

    isOpen = false;
    std::cout << " Ride " << getName() << " is now closed." << std::endl;
}
    
void RollerCoasterRide::reportStatus() const {

    std::cout << getName() <<" status: " << (isOpen ? "open" : "closed")
    << ", capacity: " << capacity 
    << ", current riders: " << currentRiders << std::endl;
}
    
int RollerCoasterRide::getCapacity() const {
    return capacity;
}

void RollerCoasterRide::setWindSpeed(int speed) {
    
    windSpeed = speed;
    if (windSpeed >= 60 && isOpen) {
        std::cout << " Ride " << getName() << " is pausing due to high winds." << std::endl;
        isOpen = false;
    }
}

void RollerCoasterRide::boardGuests(int count)
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

int RollerCoasterRide::getCurrentRiders() const
{
    return currentRiders;
}