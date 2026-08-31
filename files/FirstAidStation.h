#ifndef FIRSTAIDSTATION_H
#define FIRSTAIDSTATION_H

#include <iostream>
#include <string>
#include "EventUnit.h"

class FirstAidStation : public EventUnit
{
private:
    int staffOnDuty;
    bool isOperational;

public:
     FirstAidStation(const std::string& stationName, int staff);
    ~FirstAidStation() override;

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    int getStaffOnDuty() const;
    bool getIsOperational() const;
};

#endif