#ifndef FLIGHTMANAGEMENTSYSTEM_HPP
#define FLIGHTMANAGEMENTSYSTEM_HPP

#include <vector>
#include <string>

#include "Flight.hpp"
#include "Customer.hpp"
#include "ScheduledFlight.hpp"

class FlightManagementSystem {

private:
	std::vector<Customer *> customerList;
	std::vector<ScheduledFlight *> scheduledFlightList;
	const std::string checkCustomer(const std::string &passportNumber) const;
	Customer* lookUpCustomer(const std::string &passportNumber) const;
	bool customerError;

public:
    FlightManagementSystem();

    static std::string author();
    bool bookTicket(Route* route, Date *time, const std::string &passportNumber, int quantity);
    bool addCustomer(Customer *customer);

    int getCapacity(const Route* route, const Date* time) const;
    void addFlight(Flight* flight, Date* time);
    int getCustomerPoints(const std::string &passportNumber) const;

    std::vector<Flight *> getFlights() const;
    std::vector<Customer *> getCustomers() const;

    ~FlightManagementSystem();
};

#endif
