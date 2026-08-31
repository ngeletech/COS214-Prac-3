#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"
#include <iostream>

class EventUnit : public EventComponent
{

public:
    
    virtual ~EventUnit() = default;
};

class WaterRide : public EventUnit 
{
public:
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

};

class FirstAidStation : public EventUnit 
{

private:
    std::string name;
    int staffOnDuty;
    bool isOperational;
public:
    FirstAidStation(const std::string& stationName, int staff);
    ~FirstAidStation() override;


    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    std::string getName() const;
    int getStaffOnDuty() const;
    bool getIsOperational() const;

};

class TicketGate : public EventUnit 
{
private:
    bool isOpen;
    int capacity;
    int profit;

public:
    TicketGate();
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void orderTicket();
    int moneyMade();

};

class FoodKiosk : public EventUnit 
{
private:
    bool isOpen;
    int capacity;
    int profit;
public:
    FoodKiosk();
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void orderingCustomer();
    int moneyMade();

};

class KidsRide : public EventUnit 
{
public:
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

};


#endif //EVENTUNIT_H