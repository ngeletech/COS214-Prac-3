#ifndef FOODKIOSK_H
#define FOODKIOSK_H

#include <iostream>
#include "EventUnit.h"

class FoodKiosk : public EventUnit
{
private:
    bool isOpen;
    int capacity;
    int profit;
    int ordersServed;

public:
    FoodKiosk(const std::string& kioskName);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    void orderingCustomer();
    int moneyMade();
};

#endif