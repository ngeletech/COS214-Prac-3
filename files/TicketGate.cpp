#include "TicketGate.h"

TicketGate::TicketGate(const std::string& gateName)
    : EventUnit(gateName), isOpen(false), capacity(100), profit(0), ticketsSold(0) {}

void TicketGate::open()
{

    isOpen = true;
    std::cout << "Ticket Gate " << getName() << " is OPEN!" << std::endl;
}

void TicketGate::close()
{

    isOpen = false;
    std::cout << "Ticket Gate " << getName() << " is CLOSED!" << std::endl;
}

void TicketGate::reportStatus() const
{

    std::cout << "Ticket gate " << getName() << " status: " << (isOpen ? "admitting guests" : "closed")
    << ", capacity: " << capacity 
    << ", tickets sold: " << ticketsSold
    << ", profit: " << profit << std::endl;
}

void TicketGate::orderTicket()
{
    if (!isOpen)
    {
        std::cout << "Cannot sell ticket, gate is closed." << std::endl;
        return;
    }

    if (ticketsSold >= capacity)
    {
        std::cout << "Cannot sell ticket, at capacity." << std::endl;
        return;
    }
    ticketsSold++;
    profit += 50;
    std::cout << "Ticket sold." << std::endl;
}

int TicketGate::getCapacity() const
{
    return capacity;
}

int TicketGate::moneyMade() {
    
    return profit;
}