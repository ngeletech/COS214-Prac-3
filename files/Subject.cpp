#include "Subject.h"
#include <iostream>
#include <vector>

void Subject::attach(Observer* o){
    if (o == nullptr){
        return;
    }

   for (Observer* existing : observers){
        if (existing == o){
            return;
        }
   }
    observers.push_back(o);
}

void Subject::detach(Observer* o) {
    for (auto it = observers.begin(); it != observers.end(); ++it){
        if(*it == o){
            observers.erase(it);
        }
    }
}
    
void Subject::notify(NoticeType notice){
    for (Observer* o : observers){
        o->update(notice);
    }
    
}