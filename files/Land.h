#ifndef LAND_H
#define LAND_H

#include "EventGroup.h"
#include <iostream>

using namespace std;

/**
 * @brief Concrete Composite 
 */

 class Land : public EventGroup{
    private:
        bool isOutside;
        std::string name;
    public:
        /**
         * @param landName Display name for this land
         * @param Whether this land is an outdoor area or not (for weather alerts/updates)
         */
        Land(const std::string& landName, bool outdoor);
        virtual ~Land();

        void add(EventComponent* e) override;
        void remove(EventComponent* e) override;
        void open() override;
        void close() override;
        void reportStatus() override;
        int getCapacity() override;


        std::string getName() const;
        bool outDoorEvent() const;

};
 
 
#endif;