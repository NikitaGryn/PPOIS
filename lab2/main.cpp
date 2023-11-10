#include <iostream>
#include "Theatre.h"

using namespace std;

int main() {
	Theatre theatre;
	std::string name = "Nick James";
	theatre.HireEmployee(name, 18);
	theatre.RemoveEmployee(name);
	std::vector<Employee> actual = theatre.GetEmployeeList();
	bool expected = true;
	cout << actual.empty() << endl;
}
