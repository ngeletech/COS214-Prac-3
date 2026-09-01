#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include <iostream>
#include <string>
#include "EventUnit.h"
#include "Observer.h"

/**
 * @class RollerCoasterRide
 * @brief Represents a ride related that pauses under high wind.
 * 
 * RollerCoasterRide acts as a Leaf(an individual EventComponent object with no children) in the Composite Pattern
 * Observer(receiving notices from a higher-level subject) in the Observer Pattern
 */

class RollerCoasterRide : public EventUnit , public Observer {
private:
    int capacity;
    bool isOpen;
    int windSpeed;
    int currentRiders;
    bool underMaintenance;
    int timesRidden;

public:
    //--------Observer--------

    /**
     * @brief Responds to a notice received from a Subject.
     * @param notice The NoticeType describing the event that occurred.
     */
    void update(NoticeType notice) override;


    //--------Composite--------- 
    
    /**
     * @brief Constructs a roller coaster ride.
     * @param rideName Display name for this ride.
     * @param rideCapacity Maximum number of guests this ride can serve.
     */
    RollerCoasterRide(const std::string& rideName, int rideCapacity);

    /**
     * @brief Opens the ride, unless current wind speed is unsafe.
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
     * @brief Updates the current wind speed reading and pauses the ride
     * automatically if it becomes unsafe while open.
     * @param speed Current wind speed.
     */
    void setWindSpeed(int speed);

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

    /**
     * @brief Puts the ride into or out of maintenance mode.
     *
     * A ride under maintenance cannot be opened via open() or via an
     * OpenNotice, regardless of other conditions, until maintenance
     * mode is deactivated.
     * @param active True means begin maintenance, false means maintenance completed.
     */
    void setMaintenanceMode(bool active);

    /**
     * @brief Records that a group of guests has completed a ride cycle,
     * incrementing this ride's popularity total.
     * @param guestCount Number of guests who completed the ride.
     */
    void recordRide(int guestCount);

    /**
     * @brief Returns the total number of guests this ride has served.
     * @return Guest count across all completed cycles.
     */
    int getPopularity() const;
};

#endif