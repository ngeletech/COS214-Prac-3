#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

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
public:
    void open() override;
    void close() override;
    void reportStatus() override;
    int getCapacity() override;

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