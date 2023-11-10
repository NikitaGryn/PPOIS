#include "Schedule.h"
#include "Session.h"
#include "Ticket.h"

void Schedule::AddSession(Session session) {
    sessions.emplace_back(session);
}
void Schedule::RemoveSession(int position) {
    if (position < 1 || position > sessions.size())
    sessions.erase(sessions.begin() + position - 1);
}

void Schedule::AddCustomer(const Customer& customer, Ticket& ticket) {
    if (!ticket.IsValid())
        return;
    for (auto& it : sessions) {
        if (it == ticket.GetSession()) {
            it.AddCustomer(customer, ticket);
            return;
        }
    }
}

std::vector<Session> Schedule::GetSessions() const {
    return sessions;
}