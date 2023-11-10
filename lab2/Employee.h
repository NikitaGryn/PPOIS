#pragma once
#include <string>

class Employee {
public:
    Employee(std::string name, int number, int id) : name(name), number(number), id(id) {}
    int GetID() const;
    std::string GetName() const;
private:
    int id;
    int number;
    std::string name;
};