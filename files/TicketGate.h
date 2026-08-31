#ifndef TICKETGATE_H
#define TICKETGATE_H

#include <iostream>
#include "EventUnit.h"

class TicketGate : public EventUnit
{
private:
    bool isOpen;
    int capacity;
    int profit;
    int ticketsSold;

public:
    TicketGate(const std::string& gateName);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    void orderTicket();
    int moneyMade();
};

#endif