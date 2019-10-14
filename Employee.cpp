#include "Employee.hpp"

Employee::Employee(const std::string &name, int ID) : Human (name){
	employeeID = ID;
}

int Employee::getID() const{
	return employeeID;
}

