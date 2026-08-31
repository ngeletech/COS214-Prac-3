#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"

class EventControl: public Subject
{

public:
    virtual void attach(Observer* o) override;
    virtual void detach(Observer* o) override;
    virtual void notify() override;
    virtual ~EventControl() = default;

};


#endif //EVENTCONTROL_H
