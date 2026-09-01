#include <iostream>

#include "EventControl.h"
#include "Land.h"
#include "RideGroup.h"
#include "ServiceGroup.h"
#include "FoodKiosk.h"
#include "TicketGate.h"
#include "RollerCoasterRide.h"
#include "WaterRide.h"

int main()
{
    std::cout << "======================================" << std::endl;
    std::cout << "        WELCOME TO NEVERLAND PARK     " << std::endl;
    std::cout << "======================================" << std::endl;

    EventControl control;

    Land* waterLand = new Land("Water Land", true);
    ServiceGroup* waterServices = new ServiceGroup();
    FoodKiosk* foodKiosk = new FoodKiosk("Neverland Burger Kiosk");
    TicketGate* ticketGate = new TicketGate("Water Land Ticket Gate");

    waterLand->add(waterServices);
    waterServices->add(foodKiosk);
    waterServices->add(ticketGate);

    control.attach(waterLand);
    waterLand->attach(waterServices);
    waterServices->attach(foodKiosk);
    waterServices->attach(ticketGate);

    Land* thrillLand = new Land("Thrill Land", true);
    RideGroup* thrillRides = new RideGroup("Thrill Rides");
    RollerCoasterRide* coaster =
        new RollerCoasterRide("Neverland Storm Coaster", 40);
    WaterRide* splash =
        new WaterRide("Neverland Splash", 30);

    thrillLand->add(thrillRides);
    thrillRides->add(coaster);
    thrillRides->add(splash);

    control.attach(thrillLand);
    thrillLand->attach(thrillRides);
    thrillRides->attach(coaster);
    thrillRides->attach(splash);

    std::cout << "\n======================================" << std::endl;
    std::cout << "       OPENING NEVERLAND PARK         " << std::endl;
    std::cout << "======================================" << std::endl;

    waterLand->open();
    thrillLand->open();

    std::cout << "\n======================================" << std::endl;
    std::cout << "           PARK STATUS                " << std::endl;
    std::cout << "======================================" << std::endl;

    waterLand->reportStatus();
    thrillLand->reportStatus();

    std::cout << "\n======================================" << std::endl;
    std::cout << "           PARK CAPACITY              " << std::endl;
    std::cout << "======================================" << std::endl;

    int waterCapacity = waterLand->getCapacity();
    int thrillCapacity = thrillLand->getCapacity();

    std::cout << "Water Land capacity: "
              << waterCapacity << std::endl;

    std::cout << "Thrill Land capacity: "
              << thrillCapacity << std::endl;

    std::cout << "Neverland Park total capacity: "
              << waterCapacity + thrillCapacity
              << std::endl;

    std::cout << "\n======================================" << std::endl;
    std::cout << "          WEATHER ALERT               " << std::endl;
    std::cout << "======================================" << std::endl;

    control.notify(NoticeType::WeatherAlert);

    std::cout << "\n======================================" << std::endl;
    std::cout << "         EVACUATION NOTICE            " << std::endl;
    std::cout << "======================================" << std::endl;

    control.notify(NoticeType::EvacuationNotice);

    control.detach(waterLand);
    control.detach(thrillLand);

    delete waterLand;
    delete thrillLand;

    std::cout << "\n======================================" << std::endl;
    std::cout << "       NEVERLAND PARK CLOSED          " << std::endl;
    std::cout << "======================================" << std::endl;

    return 0;
}