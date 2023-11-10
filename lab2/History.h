#pragma once
#include <vector>

class Session;

class History {
public:
    History();
    History(std::vector<Session> sessions);
    Session GetLastSession();

    std::vector<Session> GetSessionHistory();

    void AddSession(Session session);
private:
    std::vector<Session> sessionHistory;
};