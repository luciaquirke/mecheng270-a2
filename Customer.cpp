#include "Customer.hpp"

Customer::Customer(const std::string &name, const std::string &passportNumber) : Human(name) {
	customerPoints = 0;
	customerPassport = passportNumber;
}

void Customer::addLoyaltyPoints(int points) {
	customerPoints = customerPoints + points;
}

void Customer::decreaseLoyaltyPoints(int points) {
	customerPoints = customerPoints - points;

	if(customerPoints < 0){ //Stops loyalty points from entering the negatives
		customerPoints = 0;
	}
}

int Customer::getLoyaltyPoints() const {
    return customerPoints;
}

std::string Customer::getPassportNumber() const {
    return customerPassport;
}
