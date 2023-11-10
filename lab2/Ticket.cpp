#include "Ticket.h"

void Ticket::MakeInvalid() {
	isValid = false;
}

std::string Ticket::ToString()
{
	std::string status = isValid ? "valid" : "not valid";
	return session.ToString() + "\nstatus: " + status;
}

Session Ticket::GetSession() {
	return session;
}

int Ticket::GetCost() const {
	return pricing.GetDefaultPricing();
}

bool Ticket::operator==(const Ticket& ticket) const {
	return (this->session == ticket.session);
}

bool Ticket::IsValid() const {
	return isValid;
}

Session Ticket::GetSession() const {
	return session;
}