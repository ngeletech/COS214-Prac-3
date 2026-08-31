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
    void reportStatus() override;
    int getCapacity() override;

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
    void reportStatus() override;
    int getCapacity() override;

    std::string getName() const;
    int getStaffOnDuty() const;
    bool getIsOperational() const;

};

class TicketGate : public EventUnit 
{
public:
    void open() override;
    void close() override;
    void reportStatus() override;
    int getCapacity() override;

};

class FoodKiosk : public EventUnit 
{
public:
    void open() override;
    void close() override;
    void reportStatus() override;
    int getCapacity() override;

};

class KidsRide : public EventUnit 
{
public:
    void open() override;
    void close() override;
    void reportStatus() override;
    int getCapacity() override;

};


#endif //EVENTUNIT_H