#ifndef KIDSRIDE_H
#define KIDSRIDE_H

#include <iostream>
#include <string>
#include "EventUnit.h"

class KidsRide : public EventUnit {
private:
    std::string name;
    int capacity;
    bool isOpen;

public:
    KidsRide(const std::string& rideName, int rideCapacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
};

#endif