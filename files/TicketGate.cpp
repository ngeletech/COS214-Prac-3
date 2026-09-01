#include <iostream>

#include "TicketGate.h"

//--------Observer--------

void TicketGate::update(NoticeType notice) {

    switch (notice)
    {
    case NoticeType::WeatherAlert:
        std::cout << "Bad weather incoming, Closing ticket gates down!" << std::endl;
            close();
        break;
    case NoticeType::CapacityAlert:
        std::cout << "Capacity alert: Park is full" << std::endl;
        close();
        break;

    case NoticeType::OpenNotice:
        std::cout << "Opening ticket gates for visitors." << std::endl;
        open();
    break;

    case NoticeType::CloseNotice:
        std::cout << "Closing ticket gates: Park closed." << std::endl;
        close();
    break;

    case NoticeType::PauseNotice:
        std::cout << "Ticket gates temporarily paused." << std::endl;
        close();
        break;

    case NoticeType::ResumeNotice:
        std::cout << "Ticket gates re-opened." << std::endl;
        open();
        break;

    case NoticeType::EvacuationNotice:
        std::cout << "Evacuation notice received. Visitors leave through ticket gates." << std::endl;
        open();
        break;

    case NoticeType::RushHourNotice:
        std::cout << "Rush hour started. Ticket Gate preparing for more customers." << std::endl;
        break;

    default:
        break;
    }
}


//--------Composite---------

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

int TicketGate::moneyMade() const {
    
    return profit;
}