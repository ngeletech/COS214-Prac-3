#include "EventUnit.h"

// TicketGate
TicketGate::TicketGate()
{
    isOpen = false;
    capacity = 100;
    profit = 0;
}

void TicketGate::open()
{

    isOpen = true;
    std::cout << "Ticket Gate is OPEN!" << std::endl;
}

void TicketGate::close()
{

    isOpen = false;
    std::cout << "Ticket Gate is CLOSED!" << std::endl;
}

void TicketGate::reportStatus() const
{

    if (isOpen)
    {
        std::cout << "Ticket Gate status: OPEN!" << std::endl;
    }
    else
    {
        std::cout << "Ticket Gate status: CLOSED!" << std::endl;
    }
}

void TicketGate::orderTicket()
{

    profit += 50;
    capacity++;
}

int TicketGate::getCapacity() const
{
    return capacity;
}

int TicketGate::moneyMade() {
    return profit;

}





// FoodKiosk
FoodKiosk::FoodKiosk()
{
    isOpen = false;
    capacity = 50;
    profit = 0;

}

void FoodKiosk::open()
{

    isOpen = true;
    std::cout << "Ticket Gate is OPEN!" << std::endl;
}

void FoodKiosk::close()
{

    isOpen = false;
    std::cout << "Ticket Gate is CLOSED!" << std::endl;
}

void FoodKiosk::reportStatus() const
{

    if (isOpen)
    {
        std::cout << "Ticket Gate status: OPEN!" << std::endl;
    }
    else
    {
        std::cout << "Ticket Gate status: CLOSED!" << std::endl;
    }
}

void FoodKiosk::orderingCustomer()
{
    profit += 25;
    capacity++;
}

int FoodKiosk::getCapacity() const
{
    return capacity;
}

int FoodKiosk::moneyMade() {
    return profit;

}
