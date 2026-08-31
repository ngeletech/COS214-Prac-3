#include "ServiceGroup.h"

void ServiceGroup::add(EventComponent* e) {
    children.push_back(e);

}

void ServiceGroup::remove(EventComponent* e) {

    if (children.empty()) {
        std::cout << "ServiceGroup is empty" << std::endl;
        return;
    }

    // goes through each position in children to find and remove e
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == e) {
            children.erase(it);
            return;
        }
    }
    
}

void ServiceGroup::open() {
    
    for (EventComponent* child : children) {
        child->open();
    }

    std::cout << "Park services now OPEN!!" << std::endl;
    

}

void ServiceGroup::close() {

    for (EventComponent* child : children) {
        child->close();
    }

    std::cout << "Park services now CLOSED!!" << std::endl;


}

void ServiceGroup::reportStatus() const {

    std::cout << "Service Group Status:" << std::endl;

    for (EventComponent* child : children) {
        child->reportStatus();
    }
    
}

int ServiceGroup::getCapacity() const {

    int total = 0;

    for (EventComponent* child : children) {
        total += child->getCapacity();
    }

    std::cout << "Park service group capacity = " << total << std::endl;

    return total;
 
}


ServiceGroup::~ServiceGroup() {

    for (EventComponent* child : children) {
        delete child;
    }
}
