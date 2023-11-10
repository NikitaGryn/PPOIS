#pragma once
#include "Session.h"

class Schedule {
public:
    void AddSession(Session session);
    void AddCustomer(const Customer& customer, Ticket& ticket);
    void RemoveSession(int position);
    std::vector<Session> GetSessions() const;
private:
    std::vector<Session> sessions;
};