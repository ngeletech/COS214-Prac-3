#ifndef SERVICEGROUP_H
#define SERVICEGROUP_H

#include "EventGroup.h"
#include "Subject.h"
#include "Observer.h"

/**
 * @class ServiceGroup
 * @brief Represents a group of service related event units in the theme park.
 * 
 * ServiceGroup acts as a Composite(containing EventComponent objects)
 * Subject(forwarding notices to its registered observers)
 * Observer(receiving notices from a higher-level subject)
 */

class ServiceGroup : public EventGroup, public Subject, public Observer
{
    
public:

    // -------Subject-------

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


    // --------Composite---------

    /**
     * @brief Adds an event component to the service group.
     * @param e Pointer to the event component to add.
     */
    void add(EventComponent* e) override;

    /**
     * @brief Removes an event component from the service group.
     * @param e Pointer to the event component to remove.
     */
    void remove(EventComponent* e) override;

    /**
     * @brief Opens all event components contained in the service group.
     */
    void open() override;

     /**
     * @brief Closes all event components contained in the service group.
     */
    void close() override;

    /**
     * @brief Reports the status of all event components in the service group.
     */
    void reportStatus() const override;

    /**
     * @brief Calculates the total capacity of the service group.
     * @return The combined capacity of all event components in the group.
     */
    int getCapacity() const override;

    /**
     * @brief Destroys the service group.
     */
    ~ServiceGroup()  override;
};



#endif //SERVICEGROUP_H