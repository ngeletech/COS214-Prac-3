#include "EventUnit.h"
#include <iostream>

FirstAidStation::FirstAidStation(const std::string& stationName, int staff) : name(stationName), staffOnDuty(staff), isOperational(true) {}

FirstAidStation::~FirstAidStation(){}


void FirstAidStation::open(){
    isOperational = true;
}

void FirstAidStation::reportStatus() const{
    std::cout << name << " (First Aid): " << (isOperational? "operational" : "stood down") <<", "<< staffOnDuty << " staff on duty\n";
}

int FirstAidStation::getCapacity() const{
    //how many patients it can treat

    return staffOnDuty * 2;
}

std::string FirstAidStation::getName() const {
    return name;
}

int FirstAidStation::getStaffOnDuty() const{
    return staffOnDuty;
}

bool FirstAidStation::getIsOperational() const {
    return isOperational;
}