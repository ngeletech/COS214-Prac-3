#ifndef TICKETGATE_H
#define TICKETGATE_H

#include "EventUnit.h"
#include "Observer.h"

/**
 * @class TicketGate
 * @brief Represents a ticket gate used to admit visitors into the theme park.
 */

class TicketGate : public EventUnit, public Observer
{
private:
    bool isOpen;
    int capacity;
    int profit;
    int ticketsSold;

public:

    //--------Observer--------
    /**
     * @brief Responds to a notice received from a Subject.
     * @param notice The NoticeType describing the event that occurred.
     */
    void update(NoticeType notice) override;


    //--------Composite---------
    /**
     * @brief Constructs a TicketGate with the given name.
     * @param gateName The name used to identify the ticket gate.
     */
    TicketGate(const std::string& gateName);

    /**
     * @brief Opens the ticket gate to allow visitors to enter.
     */
    void open() override;

    /**
     * @brief Closes the ticket gate and stops visitors.
     */
    void close() override;

     /**
     * @brief Reports the current status, capacity, tickets sold and profit.
     */
    void reportStatus() const override;

    /**
     * @brief Returns the capacity associated with the ticket gate.
     * @return The maximum visitor capacity of the gate.
     */
    int getCapacity() const override;

    /**
     * @brief Processes the purchase of one ticket.
     *
     * A ticket is only sold if the gate is open and the capacity
     * has not been reached.
     */
    void orderTicket();

     /**
     * @brief Returns the total profit earned from ticket sales.
     * @return The current profit from tickets sold.
     */
    int moneyMade() const;
};

#endif