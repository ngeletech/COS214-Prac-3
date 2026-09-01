#include <iostream>

#include "EventControl.h"
#include "Land.h"
#include "RideGroup.h"
#include "ServiceGroup.h"
#include "FoodKiosk.h"
#include "TicketGate.h"
#include "RollerCoasterRide.h"
#include "WaterRide.h"
#include "KidsRide.h"
#include "FirstAidStation.h"

int main()
{
    std::cout << "======================================" << std::endl;
    std::cout << "        WELCOME TO NEVERLAND PARK     " << std::endl;
    std::cout << "======================================" << std::endl;

    EventControl control;

    Land* waterLand = new Land("Water Land", true);
    ServiceGroup* waterServices = new ServiceGroup();
    FoodKiosk* foodKiosk =
        new FoodKiosk("Neverland Burger Kiosk");
    TicketGate* ticketGate =
        new TicketGate("Water Land Ticket Gate");

    waterLand->add(waterServices);
    waterServices->add(foodKiosk);
    waterServices->add(ticketGate);

    control.attach(waterLand);
    waterLand->attach(waterServices);
    waterServices->attach(foodKiosk);
    waterServices->attach(ticketGate);

    Land* thrillLand = new Land("Thrill Land", true);
    RideGroup* thrillRides =
        new RideGroup("Thrill Rides");

    RollerCoasterRide* coaster =
        new RollerCoasterRide(
            "Neverland Storm Coaster", 40);

    WaterRide* splash =
        new WaterRide(
            "Neverland Splash", 30);

    KidsRide* kidsRide =
        new KidsRide(
            "Neverland Flying Pirates", 20);

    thrillLand->add(thrillRides);

    thrillRides->add(coaster);
    thrillRides->add(splash);
    thrillRides->add(kidsRide);

    control.attach(thrillLand);
    thrillLand->attach(thrillRides);

    thrillRides->attach(coaster);
    thrillRides->attach(splash);
    thrillRides->attach(kidsRide);

    Land* adventureLand =
        new Land("Adventure Land", true);

    RideGroup* adventureRides =
        new RideGroup("Adventure Rides");

    ServiceGroup* guestServices =
        new ServiceGroup();

    RollerCoasterRide* adventureCoaster =
        new RollerCoasterRide(
            "Neverland Adventure Coaster", 35);

    TicketGate* gate1 =
        new TicketGate(
            "Adventure Land Ticket Gate");

    FoodKiosk* kiosk1 =
        new FoodKiosk(
            "Adventure Land Food Kiosk");

    FirstAidStation* firstAid =
        new FirstAidStation(
            "Neverland First Aid Station", 5);

    adventureLand->add(adventureRides);
    adventureLand->add(guestServices);

    adventureRides->add(adventureCoaster);

    guestServices->add(gate1);
    guestServices->add(kiosk1);
    guestServices->add(firstAid);

    control.attach(adventureLand);

    adventureLand->attach(adventureRides);
    adventureLand->attach(guestServices);

    adventureRides->attach(adventureCoaster);

    guestServices->attach(gate1);
    guestServices->attach(kiosk1);
    guestServices->attach(firstAid);

    std::cout << "\n======================================" << std::endl;
    std::cout << "       OPENING NEVERLAND PARK         " << std::endl;
    std::cout << "======================================" << std::endl;

    waterLand->open();
    thrillLand->open();
    adventureLand->open();

    std::cout << "\n======================================" << std::endl;
    std::cout << "           PARK STATUS                " << std::endl;
    std::cout << "======================================" << std::endl;

    waterLand->reportStatus();
    thrillLand->reportStatus();
    adventureLand->reportStatus();

    std::cout << "\n======================================" << std::endl;
    std::cout << "           PARK CAPACITY              " << std::endl;
    std::cout << "======================================" << std::endl;

    int waterCapacity =
        waterLand->getCapacity();

    int thrillCapacity =
        thrillLand->getCapacity();

    int adventureCapacity =
        adventureLand->getCapacity();

    int totalCapacity =
        waterCapacity +
        thrillCapacity +
        adventureCapacity;

    std::cout
        << "Water Land capacity: "
        << waterCapacity
        << std::endl;

    std::cout
        << "Thrill Land capacity: "
        << thrillCapacity
        << std::endl;

    std::cout
        << "Adventure Land capacity: "
        << adventureCapacity
        << std::endl;

    std::cout
        << "Neverland Park total capacity: "
        << totalCapacity
        << std::endl;

    std::cout << "\n======================================" << std::endl;
    std::cout << "          WEATHER ALERT               " << std::endl;
    std::cout << "======================================" << std::endl;

    control.notify(
        NoticeType::WeatherAlert);

    std::cout << "\n======================================" << std::endl;
    std::cout << "          CAPACITY CHECK              " << std::endl;
    std::cout << "======================================" << std::endl;

    int capacityThreshold = 80;

    int currentThrillCapacity =
        thrillLand->getCapacity();

    if (currentThrillCapacity >= capacityThreshold)
    {
        std::cout
            << "Thrill Land capacity threshold reached."
            << std::endl;

        control.notify(
            NoticeType::CapacityAlert);
    }
    else
    {
        std::cout
            << "Thrill Land capacity is below threshold."
            << std::endl;
    }

    std::cout << "\n======================================" << std::endl;
    std::cout << "         EVACUATION NOTICE            " << std::endl;
    std::cout << "======================================" << std::endl;

    control.notify(
        NoticeType::EvacuationNotice);

    std::cout << "\n======================================" << std::endl;
    std::cout << "           RESUME NOTICE              " << std::endl;
    std::cout << "======================================" << std::endl;

    control.notify(
        NoticeType::ResumeNotice);

    std::cout << "\n======================================" << std::endl;
    std::cout << "         FINAL PARK STATUS            " << std::endl;
    std::cout << "======================================" << std::endl;

    waterLand->reportStatus();
    thrillLand->reportStatus();
    adventureLand->reportStatus();

    control.detach(waterLand);
    control.detach(thrillLand);
    control.detach(adventureLand);

    delete waterLand;
    delete thrillLand;
    delete adventureLand;

    std::cout << "\n======================================" << std::endl;
    std::cout << "       NEVERLAND PARK CLOSED          " << std::endl;
    std::cout << "======================================" << std::endl;

    return 0;
}