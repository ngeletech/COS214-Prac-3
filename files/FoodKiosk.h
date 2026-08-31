#ifndef FOODKIOSK_H
#define FOODKIOSK_H

#include "EventUnit.h"
#include "Observer.h"

class FoodKiosk : public EventUnit, public Observer
{
private:
    bool isOpen;
    int capacity;
    int profit;
    int ordersServed;

public:

    //--------Observer--------
    void update(NoticeType notice) override;


    //--------Composite---------
    FoodKiosk(const std::string& kioskName);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    void orderingCustomer();
    int moneyMade() const;
};

#endif