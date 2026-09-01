#ifndef WATERRIDE_H
#define WATERRIDE_H

#include <iostream>
#include <string>
#include "EventUnit.h"
#include "Observer.h"

class WaterRide : public EventUnit, public Observer {
private:
    int capacity;
    bool isOpen;

public:
    //--------Observer--------
    /**
     * @brief Responds to a notice received from a Subject.
     * @param notice The NoticeType describing the event that occurred.
     */
    void update(NoticeType notice) override;


    //--------Composite---------    
    WaterRide(const std::string& rideName, int rideCapacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
};

#endif