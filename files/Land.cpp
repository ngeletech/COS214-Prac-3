#include "Land.h"
#include <iostream>
#include <algorithm>

Land::Land(const std::string& landName, bool outdoor)
    : isOutside(outdoor), name(landName) {}

    void Land::attach(Observer* o)
{
    if (o == nullptr)
        return;

    for (Observer* observer : observers)
    {
        if (observer == o)
            return;
    }

    observers.push_back(o);
}

void Land::detach(Observer* o)
{
    for (auto it = observers.begin(); it != observers.end(); ++it)
    {
        if (*it == o)
        {
            observers.erase(it);
            return;
        }
    }
}

void Land::notify(NoticeType notice)
{
    for (Observer* observer : observers)
    {
        observer->update(notice);
    }
}

void Land::update(NoticeType notice)
{
    notify(notice);
}

void Land::add(EventComponent* e){
    if (e != nullptr) {
        children.push_back(e);
    }
    
}

void Land::remove(EventComponent* e){
    children.erase(std::remove(children.begin(), children.end(), e), children.end());
}
void Land::open(){
    for (EventComponent* child : children){
        child->open();
    }
    
}

void Land::close(){
    for (EventComponent* child : children){
        child->close();
    }
    
}


void Land::reportStatus() const {
    std::cout<< name<<" (" <<(isOutside ? "Outdoor" : "Indoor")<<"): ";
    for (EventComponent* child: children){
        child->reportStatus();
    }
    
}


int Land::getCapacity() const{
    int total = 0;
    for ( EventComponent* child: children) {
        total += child->getCapacity();
    }
    return total;
    
}
std::string Land::getName() const{
    return name;
}

bool Land::outDoorEvent() const {
    return isOutside;
}

Land::~Land()
{
}