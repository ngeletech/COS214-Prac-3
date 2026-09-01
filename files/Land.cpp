#include "Land.h"
#include <iostream>
#include <algorithm>

void Land::attach(Observer* o) {
    observers.push_back(o);

}

void Land::detach(Observer* o) {
    if (observers.empty()) {
        std::cout << "Land is empty" << std::endl;
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

void Land::notify(NoticeType notice) {
    for (Observer* observer : observers) {
        observer->update(notice);
    }
}


//Observer
void Land::update(NoticeType notice) {
    
    notify(notice);

}



/**
 * @brief Constructs a Land with the given name and outdoor status.
 * 
 * @param landName Display name for this land
 * @param outdoor True if the land is an outdoor area
 */
Land::Land(const std::string& landName, bool outdoor) : name(landName), isOutside(outdoor){}

/**
 * @brief Destructor.
 * Cleans up all owned childen. Since Land is a composite, it owns all EventComponents in its children vector.
 */
Land::~Land(){
    for (EventComponent* child : children) {
        delete child;
    }
}

/**
 * @brief Adds a child component to this land.
 * 
 * @param e Pointer to the EventComponent to add. 
 */

void Land::add(EventComponent* e){
    if (e != nullptr) {
        children.push_back(e);
    }
    
}

/**
 * @brief Removes a child component from this land.
 * 
 * @param e Pointer to the EventComponent to remove.
 */
void Land::remove(EventComponent* e){
    children.erase(std::remove(children.begin(), children.end(), e), children.end());
}

/**
 * @brief Opens this land and all its children recursively
 */
void Land::open(){
    for (EventComponent* child : children){
        child->open();
    }
    
}

/**
 * @brief Closes this land and all its children recursively.
 */
void Land::close(){
    for (EventComponent* child : children){
        child->close();
    }
    
}

/**
 * @brief Reports the status of this land and all its children.
 */
void Land::reportStatus() const {
    std::cout<< name<<" (" <<(isOutside ? "Outdoor" : "Indoor")<<"): ";
    for (EventComponent* child: children){
        child->reportStatus();
    }
    
}

/**
 * @brief Gets the aggregate capacity of this land and all childre. 
 * 
 * @return int Total capacity of all components in this land.
 */

int Land::getCapacity() const{
    int total = 0;
    for ( EventComponent* child: children) {
        total += child->getCapacity();
    }
    return total;
    
}

/**
 * @brief Gets the aggregate capacity of this land and all childre. 
 * 
 * @return int Total capacity of all components in this land.
 */
std::string Land::getName() const{
    return name;
}


/**
 * @brief Checks if this land is an outdoor area.
 * 
 * Used for weather-related decisions and notifications.
 * 
 * @return bool True if the land is outdoors, false if otherwise.
 */
bool Land::outDoorEvent() const {
    return isOutside;
}
