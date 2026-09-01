#ifndef FOODKIOSK_H
#define FOODKIOSK_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @class FoodKiosk
 * @brief Represents food kiosk operating in park.
 * 
 * FoodKiosk is a concrete EventUnit and Observer. It receives event
 * notices and responds by changing its operational state when necessary.
 * It also keeps track of customers served and profit earned.
 */
class FoodKiosk : public EventUnit, public Observer
{
private:
    bool isOpen;
    int capacity;
    int profit;
    int ordersServed;

public:

    //--------Observer--------
    /**
     * @brief Responds to notice recieved from a subject.
     * @param notice The Noticetype describing the event occured
     */
    void update(NoticeType notice) override;


    //--------Composite---------

    /**
     * @brief Constructs a FoodKiosk with the given name.
     * @param kioskName The name used to identify the food kiosk.
     */
    FoodKiosk(const std::string& kioskName);

    /**
     * @brief Opens the food kiosk.
     */
    void open() override;

    /**
     * @brief Closes the food kiosk.
     */

    void close() override;

    /**
     *  @brief Reports the current status, capacity, orders served and profit.
     */
    void reportStatus() const override;

    /**
     * @brief Returns the capacity of the food kiosk.
     * @return The maximum capacity of the kiosk.
     */
    int getCapacity() const override;

    /**
     * @brief Processes an order from a customer.
     *
     * The order is only accepted if the kiosk is open and has not reached its capacity.
     */
    void orderingCustomer();

    /**
     * @brief Returns the total profit earned by the food kiosk.
     * @return The current profit of the kiosk.
     */
    int moneyMade() const;
};

#endif