#ifndef RIDEGROUP_H
#define RIDEGROUP_H

#include <iostream>
#include "EventGroup.h"

class RideGroup : public EventGroup {
private:
    std::string name;
public:
    RideGroup(const std::string& groupName);
    void add(EventComponent* e) override;
    void remove(EventComponent* e) override;
    void open() override;
    void close() override;
    void reportStatus() const;
    int getCapacity() const;
    std::string getName() const;

    ~RideGroup()  override;
};



#endif 