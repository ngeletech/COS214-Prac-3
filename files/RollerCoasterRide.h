#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include <iostream>
#include <string>
#include "EventUnit.h"

class RollerCoaster : public EventUnit {
private:
    int capacity;
    bool isOpen;
    int windSpeed;

public:
    RollerCoaster(const std::string& rideName, int rideCapacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    void setWindSpeed(int speed);
};

#endif