
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Human.hpp"

class Employee : public Human {
protected:
	int employeeID;
public:
	Employee(const std::string &name, int ID);
	int getID() const;
};

#endif
