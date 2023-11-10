#pragma once
#include "Session.h"
#include "Pricing.h"

class Session;


class Ticket {
public:
    Ticket(const Session& session, int cost) : session(session), isValid(true), pricing(cost) {}
    void MakeInvalid();
    std::string ToString();
    Session GetSession();
    int GetCost() const;
    Session GetSession() const;
    bool operator==(const Ticket& ticket) const;
    bool IsValid() const;
private:
    Session session;
    Pricing pricing;
    bool isValid;
};