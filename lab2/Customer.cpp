#include "Customer.h"
#include "Ticket.h"
#include <stdexcept>

Customer::Customer(std::string name, int age, int id) : name(name), age(age), id(id), money(0) {}

void Customer::AddMoney(int money) {
	this->money += money;
}

void Customer::UseTicket(const Ticket& ticket) {
	bool isFound = false;
	std::vector<Ticket*>::iterator save;
	for (auto it = tickets.begin(); it != tickets.end(); it++) {
		if (*(*it) == ticket) {
			save = it;
			isFound = true;
			break;
		}
	}
	if (!isFound) {
		return;
	}
	tickets.erase(save);
	history.AddSession(ticket.GetSession());
}

Ticket Customer::GetTicket(int position) {
	if (tickets.size() >= position)
		return *tickets[position - 1];
	throw std::invalid_argument("out of range");
}

void Customer::BuyTicket(const Ticket& ticket) {
	int ticketCost = ticket.GetCost();
	if (money >= ticketCost) {
		Ticket* newTicket = new Ticket(ticket);
		money -= ticketCost;
		tickets.push_back(newTicket);
	}
}

std::string Customer::GetName() const {
	return name;
}

int Customer::GetID() const {
	return id;
}

Customer::~Customer() {

}