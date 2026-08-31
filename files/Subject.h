#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Subject
{
protected:
    std::vector<Observer*> observers;
public:

    virtual void attach(Observer* o);
    virtual void detach(Observer* o);
    virtual void notify(NoticeType notice);
    virtual ~Subject() = default;
};


#endif //SUBJECT_H