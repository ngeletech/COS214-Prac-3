#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject
{
protected:
    std::vector<Observer*> observers;
public:

    virtual void attach(Observer* o) = 0;
    virtual void detach(Observer* o) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};


#endif //SUBJECT_H