#ifndef OBSERVER_H
#define OBSERVER_H

enum class NoticeType {

    WeatherAlert,
    CapacityAlert,
    OpenNotice,
    CloseNotice,
    PauseNotice,
    ResumeNotice,
    EvacuationNotice,
    RushHourNotice

};

class Observer
{

public:
    virtual void update(NoticeType notice) = 0;
    virtual ~Observer() = default;
};


#endif //OBSERVER_H