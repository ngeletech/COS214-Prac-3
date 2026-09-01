#ifndef FIRSTAIDSTATION_H
#define FIRSTAIDSTATION_H

#include <iostream>
#include <string>
#include "EventUnit.h"


/**
 * @brief Concrete Leaf representing a medical service point
 * 
 * Designed to stay open and operational during most event-wide elerts rather than closing.
 */
class FirstAidStation : public EventUnit, public Observer
{
private:
    int staffOnDuty; //number of staff on duty;
    bool isOperational; //whether the station is currently treating patients 

public:

    /**
     * @brief Responds to notice recieved from a subject.
     * @param notice The Noticetype describing the event occured
     */

     void update(NoticeType notice) override;
    /**
     * @brief Constructs a FirstAidStation
     * @param stationName Display name for this station
     * @param staff Number of staff on duty at construction
     */
     FirstAidStation(const std::string& stationName, int staff);

     /**
      * @brief virtual destructor
      */
    ~FirstAidStation() override;

    /**
     * @brief Brings the station online, ready to treat patients
     */
    void open() override;

    /**
     * @brief Stands the station down. Should not close mid-event in response to an ordinary notice.
     */
    void close() override;

    /**
     * @brief Reports this station's name, operational status and staffing level.
     */
    void reportStatus() const override;

    /**
     * @brief Returns the number of patients this station can treat concurrently
     * represents treatement capacity not attende count (differs from other leafs)
     */
    int getCapacity() const override;

    /**
     * @brief returns the number of staff currently on duty
     */
    int getStaffOnDuty() const;

    /**
     * @brief Returns whether the station is currently operational.
     */
    bool getIsOperational() const;
};

#endif