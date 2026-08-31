#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include <vector>
#include "EventComponent.h"

class EventGroup : public EventComponent
{
protected:
    std::vector<EventComponent*> children;
    
public:
    EventGroup() = default;

    virtual void add(EventComponent* e) = 0;
    virtual void remove(EventComponent* e) = 0;
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;

    ~EventGroup()  override;
};



#endif //EVENTGROUP_H