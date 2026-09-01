#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

/**
 * @brief Abstract subject class for the Observer pattern
 */
class Subject
{
protected:
/**
 * @brief Collection of registered observers 
 */
    std::vector<Observer*> observers;
public:

/** 
 * @brief Registers an observer for future event notifications
 * If the observer is already registered, calling attach() in it again does nothing.
 * 
 * @param o Observer to register.
*/
    virtual void attach(Observer* o);
    
/** 
 * @brief Deregisters an observer so it no longer recieves notices.
 * If the observer is not currently registerd detach does nothing when called on it.
 * 
 * @param o Observer to deregister
 * */    
    virtual void detach(Observer* o);
    
/**
* @brief Notifies all currently registered observers of a notice
* 
* calls update(notice) on every observer in the registration list, in the registration order. 
* this implements push style: Observer: the notice data travels withthe cal rather than observers querying the subject afterward.

* @param notice The type of notice being broadcast
*/    
    virtual void notify(NoticeType notice);
    
/**@brief Virtual destructor 
 * Does not delete the registered observers since SUbject does not own them.
 * */    
    virtual ~Subject() = default;
};


#endif //SUBJECT_H