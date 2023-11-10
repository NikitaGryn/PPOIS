#include "pch.h"
#include "CppUnitTest.h"
#include "Theatre.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TheatreTest
{
	TEST_CLASS(TheatreTest)
	{
	public:
		TEST_METHOD(AddCustomerTest)
		{
			Theatre theatre;
			std::string name = "Nick";
			theatre.AddCustomer(name, 10);
			std::vector<Customer> actual = theatre.GetCustomerList();
			std::string expected = name;
			Assert::AreEqual(expected, actual[0].GetName());
		}
		TEST_METHOD(TicketTest) {
			Theatre theatre;
			std::string name = "Nick";
			theatre.AddCustomer(name, 10);
			Play play("common play", "just a play");
			Session session = theatre.AddSession(play, "10.11.2023");
			Ticket ticket = theatre.CreateTicket(session, 20);
			std::string actual = ticket.ToString();
			std::string expected = "id 2 date: 10.11.2023 play: common play (just a play)\nstatus: valid";
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(BuyTicketTest) {
			Theatre theatre;
			std::string name = "Nick";
			theatre.AddCustomer(name, 10);
			Play play("common play", "just a play");
			Session session = theatre.AddSession(play, "10.11.2023");
			Ticket ticket = theatre.CreateTicket(session, 20);
			theatre.AddCustomerMoney("Nick", 100);
			theatre.BuyCustomerTicket("Nick", ticket);
			Ticket actual = theatre.GetCustomerTicket("Nick", 1);
			Ticket expected = ticket;
			Assert::AreEqual(expected.ToString(), actual.ToString());
		}
		TEST_METHOD(RatingTest) {
			Theatre theatre;
			std::string name = "Nick";
			theatre.AddCustomer(name, 10);
			Play play("common play", "just a play");
			play.AddRating(10.f);
			play.AddRating(8.f);
			Session session = theatre.AddSession(play, "10.11.2023");
			float actual = theatre.GetSessionRating(session);
			float expected = 9.f;
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(HireEmployeeTest) {
			Theatre theatre;
			std::string name = "Nick James";
			theatre.HireEmployee(name, 18);
			std::vector<Employee> actual = theatre.GetEmployeeList();
			std::string expected = name;
			Assert::AreEqual(expected, actual[0].GetName());
		}
		TEST_METHOD(UseTicketTest) {
			Theatre theatre;
			std::string name = "Nick";
			theatre.AddCustomer(name, 10);
			Play play("common play", "just a play");
			Session session = theatre.AddSession(play, "10.11.2023");
			Ticket ticket = theatre.CreateTicket(session, 20);
			theatre.AddCustomerMoney("Nick", 100);
			theatre.BuyCustomerTicket("Nick", ticket);
			theatre.UseCustomerTicket("Nick", ticket);
			std::vector<Session> sessions = theatre.GetSessionList();
			std::string actual = sessions[0].ToString();
			std::string expected = "id 2 date: 10.11.2023 play: common play (just a play)\nCustomers:\nname: Nick id: 1\n";
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(RemoveEmployee) {
			Theatre theatre;
			std::string name = "Nick James";
			theatre.HireEmployee(name, 18);
			theatre.RemoveEmployee(name);
			std::vector<Employee> actual = theatre.GetEmployeeList();
			bool expected = true;
			Assert::AreEqual(expected, actual.empty());
		}
	};
}
