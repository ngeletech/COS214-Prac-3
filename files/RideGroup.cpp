#include "RideGroup.h"

RideGroup::RideGroup(const std::string& groupName) : name(groupName) {}

void RideGroup::add(EventComponent* e)
{
    if (e != nullptr)
    {
        children.push_back(e);
    }
}

void RideGroup::remove(EventComponent* e)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (children[i] == e)
        {
            children.erase(children.begin() + i);
            break;
        }
    }
}

void RideGroup::open()
{
    for (EventComponent* child : children)
    {
        child->open();
    }
}

void RideGroup::close()
{
    for (EventComponent* child : children)
    {
        child->close();
    }
}

void RideGroup::reportStatus() const
{
    std::cout << "[" << getName() << "] guest capacity: " << getCapacity()
              << ", " << children.size() << " unit(s)" << std::endl;

    for (const EventComponent* child : children)
    {
        child->reportStatus();
    }
}

int RideGroup::getCapacity() const
{
    int total = 0;
    for (const EventComponent* child : children)
    {
        total += child->getCapacity();
    }
    return total;
}

std::string RideGroup::getName() const
{
    return name;
}

RideGroup::~RideGroup()
{
    for (EventComponent* child : children)
    {
        delete child;
    }
    children.clear();
}