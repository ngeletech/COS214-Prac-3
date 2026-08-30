#ifndef SERVICEGROUP_H
#define SERVICEGROUP_H

#include "EventGroup.h"

class ServiceGroup : public EventGroup
{
    
public:

    void add(EventComponent* e) override;
    void remove(EventComponent* e) override;
    void open() override;
    void close() override;
    void reportStatus() override;
    int getCapacity() override;

    ~ServiceGroup()  override;
};



#endif //SERVICEGROUP_H