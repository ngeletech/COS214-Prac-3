#include "FoodKiosk.h"

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

int FoodKiosk::moneyMade()
{
    return profit;
}
