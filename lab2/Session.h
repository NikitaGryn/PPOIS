#pragma once
#include <string>
#include <vector>   
#include "Play.h"
#include "Customer.h"

class Ticket;
class Customer;

class Session {
public:
    Session(std::string date, Play play, int id) : date(date), play(play), id(id) {}
    void AddCustomer(const Customer& customer, Ticket& ticket);
    std::string ToString() const;
    bool operator==(const Session& session) const;
    float GetPlayRating() const;
private:
    std::string date;
    std::vector<Customer> customers;
    Play play;
    int id;
};