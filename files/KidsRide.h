#ifndef KIDSRIDE_H
#define KIDSRIDE_H

#include <iostream>
#include <string>
#include "EventUnit.h"
#include "Observer.h"

/**
 * @class KidsRide
 * @brief Represents a low-intensity ride for children that pasues on capacity alerts to manage queues.
 * 
 * WaterRide acts as a Leaf(an individual EventComponent object with no children) in the Composite Pattern
 * Observer(receiving notices from a higher-level subject) in the Observer Pattern
 */

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

    /**
     * @brief Constructs a kids' ride.
     * @param rideName Display name for this ride.
     * @param rideCapacity Maximum number of guests this ride can serve.
     */
    KidsRide(const std::string& rideName, int rideCapacity);

    /**
     * @brief Opens the ride.
     */
    void open() override;

    /**
     * @brief Closes the ride.
     */
    void close() override;

    /**
     * @brief Prints this ride's name, open/closed state and capacity.
     */
    void reportStatus() const override;

    /**
     * @brief Returns the maximum guest capacity of this ride.
     * @return Guest capacity.
     */
    int getCapacity() const override;
};

#endif