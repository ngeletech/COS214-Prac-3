#ifndef SERVICEGROUP_H
#define SERVICEGROUP_H

#include <iostream>
#include "EventGroup.h"
#include "Subject.h"
#include"Observer.h"

class ServiceGroup : public EventGroup, public Subject, public Observer
{
    
public:

    void add(EventComponent* e) override;
    void remove(EventComponent* e) override;
    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;

    ~ServiceGroup()  override;
};



#endif //SERVICEGROUP_H