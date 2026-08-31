#include "RideGroup.h"
#include <vector>

RideGroup::RideGroup(const std::string& groupName) : name(groupName) {}

void RideGroup::add(EventComponent* e) {
    if (e != nullptr) {
        children.push_back(e);
    }   
}
    
void RideGroup::remove(EventComponent* e) {

    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == e) {
            children.erase(it);
            break;
        }
    }
}
    
void RideGroup::open() {

    for (EventComponent* child : children) {
        child->open();
    }
}
    
void RideGroup::close() {
    for (EventComponent* child : children) {
        child->close();
    }
}
    
void RideGroup::reportStatus() const {

    std::cout << "RideGroup status: " << std::endl;
    for (EventComponent* child : children) {
        child->reportStatus();
    }
}
    
int RideGroup::getCapacity() const {

    int total = 0;
    for (const EventComponent* child : children) {
        total += child->getCapacity();
    }
}

RideGroup::~RideGroup() {
    for (EventComponent* child : children) {
        delete child;
    }
    children.clear();
} 
