#include "FirstAidStation.h"
#include <iostream>

FirstAidStation::FirstAidStation(const std::string& stationName, int staff) : EventUnit(stationName), staffOnDuty(staff), isOperational(true) {}

FirstAidStation::~FirstAidStation(){}


void FirstAidStation::open(){
    isOperational = true;
    std::cout << getName() << "is open." <<std::endl;
}

void FirstAidStation::close() {
    std::cout <<  getName() << " remains open during closure request." << std::endl;
}

void FirstAidStation::reportStatus() const{
    std::cout << getName() << " (First Aid): " << (isOperational? "operational" : "stood down") <<", "<< staffOnDuty << " staff on duty\n";
}

int FirstAidStation::getCapacity() const{
    //how many patients it can treat

    return staffOnDuty * 2;
}

int FirstAidStation::getStaffOnDuty() const{
    return staffOnDuty;
}

bool FirstAidStation::getIsOperational() const {
    return isOperational;
}