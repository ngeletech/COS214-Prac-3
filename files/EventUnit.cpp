#include "EventUnit.h"

EventUnit::EventUnit(const std::string& unitName) : name(unitName) {}

std::string EventUnit::getName() const
{
    return name;
}