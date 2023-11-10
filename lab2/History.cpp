#include "History.h"
#include "Session.h"


History::History() {}

History::History(std::vector<Session> sessions) : sessionHistory(sessions) {}

Session History::GetLastSession() {
    return sessionHistory.back();
}

std::vector<Session> History::GetSessionHistory() {
    return sessionHistory;
}

void History::AddSession(Session session) {
    sessionHistory.push_back(session);
}
