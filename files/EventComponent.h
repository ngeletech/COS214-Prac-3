#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

class EventComponent
{

public:

    virtual void open() = 0;
    virtual void close() = 0;
    virtual void reportStatus() const = 0;
    virtual int getCapacity() const = 0;

    // now don't need an EventComponent.cpp just to define an empty constructor/destructor
    virtual ~EventComponent() = default;
};



#endif //EVENTCOMPONENT_H