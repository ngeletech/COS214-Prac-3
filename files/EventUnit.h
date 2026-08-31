#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include <string>
#include "EventComponent.h"

class EventUnit : public EventComponent
{
protected:
    std::string name;

public:
    explicit EventUnit(const std::string& unitName);
    virtual ~EventUnit() = default;

    std::string getName() const;
};

#endif //EVENTUNIT_H