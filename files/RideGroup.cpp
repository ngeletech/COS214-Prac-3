#include "RideGroup.h"

//Subject
void RideGroup::attach(Observer* o) {
    observers.push_back(o);

}

void RideGroup::detach(Observer* o) {
    if (observers.empty()) {
        std::cout << "ServiceGroup is empty" << std::endl;
        return;
    }

    // goes through each position in observers to find and remove e
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            return;
        }
    }

}

void RideGroup::notify(NoticeType notice) {
    for (Observer* observer : observers) {
        observer->update(notice);
    }
}


//Observer
void RideGroup::update(NoticeType notice) {
    
    notify(notice);
}

//Composite
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

//4.2 Transfer
void transferUnit(EventComponent* unit, RideGroup& from, RideGroup& to)
{
    from.remove(unit);
    to.add(unit);

    Observer* obs = dynamic_cast<Observer*>(unit);
    if (obs != nullptr)
    {
        from.detach(obs);
        to.attach(obs);
    }

    std::cout << "Unit transferred between ride groups." << std::endl;
}