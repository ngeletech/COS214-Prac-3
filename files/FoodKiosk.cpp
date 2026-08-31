#include <iostream>

#include "FoodKiosk.h"

void FoodKiosk::update(NoticeType notice) {

    switch (notice)
    {
    case NoticeType::WeatherAlert:
        std::cout << "Bad weather incoming, Closing stalls down!" << std::endl;
            close();
        break;
    case NoticeType::CapacityAlert:
        std::cout << "Capacity alert: limiting new customers." << std::endl;
        break;

    case NoticeType::OpenNotice:
        std::cout << "Opening food kiosk for customers." << std::endl;
        open();
    break;

    case NoticeType::CloseNotice:
        std::cout << "Closing food kiosk for the day." << std::endl;
        close();
    break;

    case NoticeType::PauseNotice:
        std::cout << "Food service temporarily paused." << std::endl;
        close();
        break;

    case NoticeType::ResumeNotice:
        std::cout << "Food service resumed." << std::endl;
        open();
        break;

    case NoticeType::EvacuationNotice:
        std::cout << "Evacuation notice received. Closing food kiosk immediately." << std::endl;
        close();
        break;

    case NoticeType::RushHourNotice:
        std::cout << "Rush hour started. Food kiosk preparing for more customers." << std::endl;
        break;

    default:
        break;
    }
}


FoodKiosk::FoodKiosk(const std::string& kioskName)
    : EventUnit(kioskName), isOpen(false), capacity(50), profit(0), ordersServed(0) {}

void FoodKiosk::open()
{

    isOpen = true;
    std::cout << "Food kiosk " << getName() << " is now OPEN!" << std::endl;
}

void FoodKiosk::close()
{

    isOpen = false;
    std::cout << "Food kiosk " << getName() << " is now CLOSED!" << std::endl;
}

void FoodKiosk::reportStatus() const
{

    std::cout << "Food kiosk " << getName() << " status: " << (isOpen ? "serving" : "closed")
    << ", capacity: " << capacity 
    << ", orders served: " << ordersServed
    << ", profit: " << profit << std::endl;
}

void FoodKiosk::orderingCustomer()
{
    if (!isOpen)
    {
        std::cout << "Cannot serve, kiosk is closed." << std::endl;
        return;
    }
    if (ordersServed >= capacity)
    {
        std::cout << "Cannot serve, at capacity." << std::endl;
        return;
    }
    ordersServed++;
    profit += 25;
    std::cout << "Order served." << std::endl;
}

int FoodKiosk::getCapacity() const
{
    return capacity;
}

int FoodKiosk::moneyMade() const
{
    return profit;
}
