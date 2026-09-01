#ifndef KIDSRIDE_H
#define KIDSRIDE_H

#include <iostream>
#include <string>
#include "EventUnit.h"
#include "Observer.h"

class KidsRide : public EventUnit, public Observer{
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
    KidsRide(const std::string& rideName, int rideCapacity);

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
};

#endif