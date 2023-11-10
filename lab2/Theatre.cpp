#include "Theatre.h"

void Theatre::UseCustomerTicket(std::string name, Ticket& ticket) {
    Customer& customer = GetCustomer(name);
    schedule.AddCustomer(customer, ticket);
    customer.UseTicket(ticket);
}

std::vector<Session> Theatre::GetSessionList() const {
    return schedule.GetSessions();
}

Session Theatre::AddSession(Play play, std::string date) {
    Session session(date, play, id++);
    schedule.AddSession(session);
    return session;
}

Ticket Theatre::CreateTicket(Session session, int cost) {
    Ticket ticket(session, cost);
    return ticket;
}

void Theatre::AddCustomerMoney(std::string name, int money) {
    Customer& customer = this->GetCustomer(name);
    customer.AddMoney(money);
}

void Theatre::BuyCustomerTicket(const std::string& name, const Ticket& ticket) {
    Customer& customer = GetCustomer(name);
    customer.BuyTicket(ticket);
}

Ticket Theatre::GetCustomerTicket(std::string name, int position) {
    Customer& customer = GetCustomer(name);
    return customer.GetTicket(position);
}

void Theatre::HireEmployee(std::string name, int number) {
    employeeList.emplace_back(name, number, id++);
}

void Theatre::AddCustomer(std::string name, int age) {
    customerList.emplace_back(name, age, id++);
}

void Theatre::RemoveEmployee(std::string name) {
    std::vector<Employee>::iterator it;
    for (it = employeeList.begin(); it != employeeList.end(); it++) {
        if (it->GetName() == name) {
            employeeList.erase(it);
            return;
        }
    }
}

void Theatre::RemoveCustomer(std::string name) {
    std::vector<Customer>::iterator it;
    for (it = customerList.begin(); it != customerList.end(); it++) {
        if (it->GetName() == name)
            customerList.erase(it);
    }
}

std::vector<Customer> Theatre::GetCustomerList() const {
    return customerList;
}

std::vector<Employee> Theatre::GetEmployeeList() const {
    return employeeList;
}

Customer& Theatre::GetCustomer(std::string name) {
    for (auto& it : customerList) {
        if (it.GetName() == name)
            return it;
    }
}

float Theatre::GetSessionRating(Session session) const {
    return session.GetPlayRating();
}

Customer& Theatre::GetCustomer(int id) {
    for (auto& it : customerList) {
        if (it.GetID() == id)
            return it;
    }
}

Employee& Theatre::GetEmployee(std::string name) {
    for (auto& it : employeeList) {
        if (it.GetName() == name)
            return it;
    }
}

Employee& Theatre::GetEmployee(int id) {
    for (auto& it : employeeList) {
        if (it.GetID() == id)
            return it;
    }
}
