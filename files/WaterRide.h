#ifndef WATERRIDE_H
#define WATERRIDE_H

#include <iostream>
#include <string>
#include "EventUnit.h"
#include "Observer.h"

/**
 * @class WaterRide
 * @brief Represents a water-based ride related that closes entirely during weather reports.
 * 
 * WaterRide acts as a Leaf(an individual EventComponent object with no children) in the Composite Pattern
 * Observer(receiving notices from a higher-level subject) in the Observer Pattern
 */

class WaterRide : public EventUnit, public Observer {
private:
    int capacity;
    bool isOpen;
    int currentRiders;

public:
    //--------Observer--------

    /**
     * @brief Responds to a notice received from a Subject.
     * @param notice The NoticeType describing the event that occurred.
     */
    void update(NoticeType notice) override;


    //--------Composite---------   

    /**
     * @brief Constructs a water ride.
     * @param rideName Display name for this ride.
     * @param rideCapacity Maximum number of guests this ride can serve.
     */
    WaterRide(const std::string& rideName, int rideCapacity);

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

    /**
     * @brief Boards a number of guests onto the ride, up to capacity.
     * @param count Number of guests attempting to board.
     */
    void boardGuests(int count);

    /**
     * @brief Returns the current number of riders on this ride.
     * @return Current rider count.
     */
    int getCurrentRiders() const;
};

#endif