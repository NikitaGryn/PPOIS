#pragma once
#include "Customer.h"
#include "Employee.h"
#include "Schedule.h"
#include "Session.h"
#include "Ticket.h"

class Theatre {
public:
    void UseCustomerTicket(std::string name, Ticket& ticket);
    Session AddSession(Play play, std::string date);
    void BuyCustomerTicket(const std::string& name, const Ticket& ticket);
    void HireEmployee(std::string name, int number);
    std::vector<Session> GetSessionList() const;
    void AddCustomer(std::string name, int age);
    void RemoveEmployee(std::string name);
    void RemoveCustomer(std::string name);
    std::vector<Customer> GetCustomerList() const;
    void AddCustomerMoney(std::string name, int money);
    Ticket GetCustomerTicket(std::string name, int position);
    std::vector<Employee> GetEmployeeList() const;
    Ticket CreateTicket(Session session, int cost);
    float GetSessionRating(Session session) const;
private:
    Customer& GetCustomer(std::string name);

    Customer& GetCustomer(int id);

    Employee& GetEmployee(std::string name);

    Employee& GetEmployee(int id);
    int id = 1;
    std::vector<Customer> customerList;
    std::vector<Employee> employeeList;
    Schedule schedule;
};