#pragma once
#include <string>
#include <vector>
#include "History.h"

class Ticket;

class Customer {
public:
    Customer(std::string name, int age, int id);
    void UseTicket(const Ticket& ticket);
    void AddMoney(int money);
    Ticket GetTicket(int position);
    void BuyTicket(const Ticket& ticket);
    std::string GetName() const;
    int GetID() const;
    ~Customer();
private:
    int id;
    int age;
    int money;
    std::string name;
    History history;
    std::vector<Ticket*> tickets;
};