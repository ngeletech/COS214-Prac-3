#ifndef TICKETGATE_H
#define TICKETGATE_H

#include "EventUnit.h"
#include "Observer.h"

class TicketGate : public EventUnit, public Observer
{
private:
    bool isOpen;
    int capacity;
    int profit;
    int ticketsSold;

public:

    //--------Observer--------
    void update(NoticeType notice) override;


    //--------Composite---------
    TicketGate(const std::string& gateName);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    void orderTicket();
    int moneyMade() const;
};

#endif