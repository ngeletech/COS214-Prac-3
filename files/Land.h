#ifndef LAND_H
#define LAND_H

#include "EventGroup.h"
#include "Subject.h"
#include "Observer.h"


#include <iostream>

using namespace std;

/**
 * @brief Defines the Land class as a Concrete Composite 
 * 
 * This file contains the land class which represents a themed area within the event.
 */

 class Land : public EventGroup,public Subject, public Observer{
    private:
        /**
         * @param landName Display name for this land
         * @param Whether this land is an outdoor area or not (for weather alerts/updates)
         */
        bool isOutside;
        std::string name;
    public:

        /**
         * @brief Attaches an observer to the service group.
         * @param o Pointer to the observer that should receive notifications.
         */
        void attach(Observer* o) override;    

        /**
         * @brief Detaches an observer from the service group.
         * @param o Pointer to the observer that should be removed.
         */
        void detach(Observer* o) override;

        /**
         * @brief Notifies all registered observers of a notice.
         * @param notice The type of notice that should be sent to the observers.
         */
        void notify(NoticeType notice) override;

        // --------Observer---------

        /**
         * @brief Receives a notice from a subject and responds to the notice.
         * @param notice The type of notice received.
         */  
        void update(NoticeType notice) override;

        /**
         * @brief Constructor- Constructs a Land with the given name and outdoor status.
         * @param landName Display name for this land
         * @param outdoor True id the land is an outdoor area; affects weather alerts
         */
        Land(const std::string& landName, bool outdoor);

        /**
         * @brief Destructor.
         * Cleans up all owned childen. Since Land is a composite, it owns all EventComponents in its children vector.
         */
        virtual ~Land();
        /**
         * @brief Adds a child component to this land.
         * 
         * @param e Pointer to the EventComponent to add. 
         */

        void add(EventComponent* e) override;
        
        /**
         * @brief Removes a child component from this land.
         * 
         * @param e Pointer to the EventComponent to remove.
         */
        void remove(EventComponent* e) override;

        /**
         * @brief Opens this land and all its children recursively
         */
        void open() override;

        /**
         * @brief Closes this land and all its children recursively.
         */
        void close() override;

        /**
         * @brief Reports the status of this land and all its children.
         */
        void reportStatus() const override;

        /**
         * @brief Gets the aggregate capacity of this land and all childre. 
         * 
         * @return int Total capacity of all components in this land.
         */
        int getCapacity() const override;

        /**
         * @brief Checks if this land is an outdoor area.
         * 
         * Used for weather-related decisions and notifications.
         * 
         * @return bool True if the land is outdoors, false if otherwise.
         */
        std::string getName() const;
        bool outDoorEvent() const;

};
 
 
#endif