#include "EventControl.h"

void EventControl::attach(Observer* o)
{
    if (o == nullptr)
        return;

    for (Observer* observer : observers)
    {
        if (observer == o)
            return;
    }

    observers.push_back(o);
}

void EventControl::detach(Observer* o)
{
    for (auto it = observers.begin(); it != observers.end(); ++it)
    {
        if (*it == o)
        {
            observers.erase(it);
            return;
        }
    }
}

void EventControl::notify(NoticeType notice)
{
    for (Observer* observer : observers)
    {
        observer->update(notice);
    }
}