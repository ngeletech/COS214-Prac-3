#ifndef RIDEGROUP_H
#define RIDEGROUP_H

#include <iostream>
#include "EventGroup.h"
#include "Subject.h"
#include "Observer.h"

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
    RideGroup(const std::string& groupName);
    void add(EventComponent* e) override;
    void remove(EventComponent* e) override;
    void open() override;
    void close() override;
    void reportStatus() const;
    int getCapacity() const;
    std::string getName() const;
    ~RideGroup()  override;
};



#endif 