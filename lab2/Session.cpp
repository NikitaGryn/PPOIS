#include "Session.h"
#include "Ticket.h"
#include "Customer.h"

void Session::AddCustomer(const Customer& customer, Ticket& ticket) {
	customers.push_back(customer);
	ticket.MakeInvalid();
}

std::string Session::ToString() const {
	std::string customerStr = "";
	if (!customers.empty()) {
		customerStr = "\nCustomers:\n";
		for (int i = 0; i < customers.size(); i++) {
			customerStr += "name: " + customers[i].GetName() + " id: " + std::to_string(customers[i].GetID()) + "\n";
		}
	}
	return "id " + std::to_string(id) + " date: " + date + " play: " + play.ToString() + customerStr;
}

bool Session::operator==(const Session& session) const {
	return (this->id == session.id) && (this->date == session.date) && (this->play.ToString() == session.play.ToString());
}

float Session::GetPlayRating() const {
	return play.GetRating();
}