#include "FirstAidStation.h"
#include <iostream>

void FirstAidStation::update(NoticeType notice){
     switch (notice)
    {
    case NoticeType::WeatherAlert:
        std::cout << "Bad weather incoming, Staying open!" << std::endl;
            close();
        break;
    case NoticeType::CapacityAlert:
        std::cout << "Capacity alert: limiting new patients." << std::endl;
        break;

    case NoticeType::OpenNotice:
        std::cout << "Opening First Aid Station for customers." << std::endl;
        open();
    break;

    case NoticeType::CloseNotice:
        std::cout << "First Aid station remains open" << std::endl;
    break;

    case NoticeType::PauseNotice:
        std::cout << "First Aid Station and services continue" << std::endl;
        close();
        break;

    case NoticeType::ResumeNotice:
        std::cout << "First Aid Station continues." << std::endl;
        open();
        break;

    case NoticeType::EvacuationNotice:
        std::cout << "Evacuation notice received. Closing First Aid Station immediately." << std::endl;
        close();
        break;

    case NoticeType::RushHourNotice:
        std::cout << "Rush hour started. First Aid Station prepares for patients" << std::endl;
        break;

    default:
        break;
    }
}



FirstAidStation::FirstAidStation(const std::string& stationName, int staff) : EventUnit(stationName), staffOnDuty(staff), isOperational(true) {}

FirstAidStation::~FirstAidStation(){}


void FirstAidStation::open(){
    isOperational = true;
    std::cout << getName() << "is open." <<std::endl;
}

void FirstAidStation::close() {
    std::cout <<  getName() << " closes during Evacuations" << std::endl;
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