#include "FlightManagementSystem.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

FlightManagementSystem::FlightManagementSystem() {
	customerError = false;
}

std::string FlightManagementSystem::author() {
    return "lqui376";
}

bool FlightManagementSystem::addCustomer(Customer *customer){

	for(unsigned int i = 0; i < customerList.size(); i++){  //Checks to see if customer is already present in the system
		if(customerList[i]->getPassportNumber() == customer->getPassportNumber()){
			return false;
		}
	}
	customerList.push_back(customer);  //Adds customer if not already present
	return true;
}

bool FlightManagementSystem::bookTicket(Route* route, Date *time, const string &passportNumber, int quantity){

	if(checkCustomer(passportNumber) == "Error"){
		return false;
	}

	for(unsigned int i = 0; i < scheduledFlightList.size(); i++){ //Checks each flight to see if it meets the date, source, and destination requirements
		if( (scheduledFlightList[i]->getDate()->getHour() == time->getHour()) && (scheduledFlightList[i]->getDate()->getDay() == time->getDay()) &&
			(scheduledFlightList[i]->getFlight()->getRoute()->getSource() == route->getSource()) &&
			(scheduledFlightList[i]->getFlight()->getRoute()->getDestination() == route->getDestination()) && (getCapacity(route, time)	>= quantity) ){
			cout << "loop";
			scheduledFlightList[i]->getFlight()->bookTicket(quantity); //Books tickets
			lookUpCustomer(passportNumber)->addLoyaltyPoints( quantity*(route->getHours()) ); //Adds loyalty points
			return true;
		}
	}
	return false;
}

int FlightManagementSystem::getCapacity(const Route* route, const Date* time) const{
	for(unsigned int i = 0; i < scheduledFlightList.size(); i++){
		if(scheduledFlightList[i]->getDate()->getHour() == time->getHour() && scheduledFlightList[i]->getFlight()->getRoute() == route && (scheduledFlightList[i]->getDate()->getDay() == time->getDay()) ){
			return scheduledFlightList[i]->getFlight()->getAvailableSeats(); //Finds booked flight and returns available seats
		}
	}
	return -1;

}

void FlightManagementSystem::addFlight(Flight* flight, Date* time){
	scheduledFlightList.push_back(new ScheduledFlight(flight, time));
}

int FlightManagementSystem::getCustomerPoints(const std::string &passportNumber) const{
	for(unsigned int i = 0; i < customerList.size(); i++){
		if(customerList[i]->getPassportNumber() == passportNumber){
			return customerList[i]->getLoyaltyPoints();  //Finds customer with matching passport number in list and returns loyalty points
		}
	}
	return 0;
}

std::vector<Flight *> FlightManagementSystem::getFlights() const{
	std::vector<Flight*> flightCopy;

	for(unsigned int i = 0; i < scheduledFlightList.size(); i++){
		flightCopy.push_back(scheduledFlightList[i]->getFlight());  //Creates a copy of the current available flights list
	}
	return flightCopy;
}

std::vector<Customer *> FlightManagementSystem::getCustomers() const{
	return customerList;
}

const std::string FlightManagementSystem::checkCustomer(const std::string &passportNumber) const{
	for(unsigned int i = 0; i < customerList.size(); i++){
		if(customerList[i]->getPassportNumber() == passportNumber){
			return customerList[i]->getPassportNumber();
		}
	}
	return "Error";
}

Customer* FlightManagementSystem::lookUpCustomer(const std::string &passportNumber) const{
	for(unsigned int i = 0; i < customerList.size(); i++){
		if(customerList[i]->getPassportNumber() == passportNumber){
			return customerList[i];
		}
	}

	return customerList[0];
}

FlightManagementSystem::~FlightManagementSystem(){
	for(unsigned int i = 0; i < scheduledFlightList.size(); i++){
		delete scheduledFlightList[i];
	}
	scheduledFlightList.clear();
}



