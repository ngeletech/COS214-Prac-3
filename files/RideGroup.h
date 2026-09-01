#ifndef RIDEGROUP_H
#define RIDEGROUP_H

#include <iostream>
#include "EventGroup.h"

#include "Subject.h"
#include "Observer.h"

/**
 * @class RideGroup
 * @brief Represents a group of ride related event units in the theme park.
 * 
 * RideGroup acts as a Composite(containing EventComponent objects) in the Composite Pattern
 * Subject(forwarding notices to its registered observers) in the Observer Pattern
 * Observer(receiving notices from a higher-level subject) in the Observer Pattern
 */

class RideGroup : public EventGroup, public Subject, public Observer{
private:
    std::string name;
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

    // --------Composite------

     /**
     * @brief Constructs a named ride group.
     * @param groupName Display name used in status reports.
     */
    RideGroup(const std::string& groupName);

    /**
     * @brief Adds a child component to this group.
     * @param e Component to add. Must not be nullptr.
     */
    void add(EventComponent* e) override;

    /**
     * @brief Removes a child component without deleting it.
     * @param e Component to remove.
     */
    void remove(EventComponent* e) override;

    /**
     * @brief Opens every child component in this group.
     */
    void open() override;

    /**
     * @brief Closes every child component in this group.
     */
    void close() override;

    /**
     * @brief Reports this group's total guest capacity, then
     * recurses into each child's status report.
     */
    void reportStatus() const override;

    /**
     * @brief Returns this group's total guest capacity, summed
     * recursively over all children.
     * @return Total guest capacity across all children.
     */
    int getCapacity() const override;

    /**
     * @brief Returns this group's display name.
     * @return The group's name.
     */
    std::string getName() const;

    /**
     * @brief Destroys this group and deletes every remaining owned child.
     */
    ~RideGroup()  override;
};

/**
 * @brief Transfers a unit from one ride group to another, updating
 * both Composite ownership and Observer registration together.
 *
 * @param unit The component being transferred. Must implement Observer.
 * @param from Current owning group.
 * @param to Destination group.
 */
void transferUnit(EventComponent* unit, RideGroup& from, RideGroup& to);


class RideGroup : public EventGroup {
private:
    std::string name;
public:
    RideGroup(const std::string& groupName);
    void add(EventComponent* e) override;
    void remove(EventComponent* e) override;
    void open() override;
    void close() override;
    void reportStatus() const;
    int getCapacity() const;

    ~RideGroup()  override;
};




#endif 
