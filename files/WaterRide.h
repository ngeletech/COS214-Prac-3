#ifndef WATERRIDE_H
#define WATERRIDE_H

#include <iostream>
#include <string>
#include "EventUnit.h"

class WaterRide : public EventUnit {
private:
    std::string name;
    int capacity;
    bool isOpen;

public:
    WaterRide(const std::string& rideName, int rideCapacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
};

#endif