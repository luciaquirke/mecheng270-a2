#include "Flight.hpp"
#include <iostream>

Flight::Flight(Route *route, Airplane* airplane)
{
	pilotsNeed = 0;
	attendantsNeed = 0;

	flightAirplane = airplane;
	flightRoute = route;

	attendantsFilled = false;
	pilotsFilled = false;

	if( route->getHours() > 7 ){
		availableSeats = (airplane->getCapacity()) - 8;  //Sets up a detailed list of crew requirements for the flight size; used to keep track of crew bookings
		pilotsNeed = 4;                                  //in setFlightAttendants and setPilots
		attendantsNeed = 6;
		englishNeed = 2;
		sourceNeed = 2;
		destinationNeed = 2;
		copilotsNeed = 2;
		captainsNeed = 2;
	}
	else{
		availableSeats = (airplane->getCapacity() - 3);
		pilotsNeed = 2;
		attendantsNeed = 3;
		englishNeed = 1;
		sourceNeed = 1;
		destinationNeed = 1;
		copilotsNeed = 1;
		captainsNeed = 1;
	}

}

bool Flight::setFlightAttendants(vector<FlightAttendant*> flightAttendants){

	unsigned int englishFound;
	unsigned int sourceFound;
	unsigned int destinationFound;

	bool availableLanguages[3][flightAttendants.size()];                  // Sets up an array containing bools indicating whether flight attendants speak
	                                                                      // English, source, and destination languages. Bools are converted to ints and added to
                                                                          // determine number of languages spoken by an attendant. Speakers of 1 language are
	for(unsigned int i = 0; i < flightAttendants.size(); i++){            // added first, and speakers of all 3 are added last to fill any gaps.
		availableLanguages[0][i] = flightAttendants[i]->canSpeak(Country::ENGLISH);
		availableLanguages[1][i] = flightAttendants[i]->canSpeak(flightRoute->getDestination()->getLanguage());
		availableLanguages[2][i] = flightAttendants[i]->canSpeak(flightRoute->getSource()->getLanguage());
	}

	if(flightAttendants.size() < attendantsNeed){
		return false;
	}

	for(unsigned int i = 0; i < flightAttendants.size(); i++){
		if(int(availableLanguages[0][i]) + int(availableLanguages[1][i]) + int(availableLanguages[2][i]) == 1){ //If a particular attendant speaks 1 language
			for(int j = 0; j < 3; j++){                       //Find the location of the single language
				if(int(availableLanguages[j][i]) == 1){       //Find the location of the single language
					if(j == 0 && englishNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);  //If the single language is needed, add to team and update team requirements.
						englishFound++;                                   //Team member can only be added for one language.
						englishNeed--;
						//cout << "Print 1";
					}
					else if(j == 1 && destinationNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						destinationFound++;
						destinationNeed--;
						//cout << "Print 2";
					}
					else if(j ==2 && sourceNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						sourceFound++;
						sourceNeed--;
						//cout << "Print 3";
					}
				}
			}
		}
	}
	for(unsigned int i = 0; i < flightAttendants.size(); i++){
		if(int(availableLanguages[0][i]) + int(availableLanguages[1][i]) + int(availableLanguages[2][i]) == 2){ //If an attendant speaks 2 languages
			for(int j = 0; j < 3; j++){
				if(int(availableLanguages[j][i]) == 1){
					if(j == 0 && englishNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						englishFound++;
						englishNeed--;
						availableLanguages[1][i] = false;  //Ugly method of preventing an attendant being added for multiple languages
						availableLanguages[2][i] = false;  //Sets still-to-be-checked language proficiencies to false
					}
					else if(j == 1 && destinationNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						destinationFound++;
						destinationNeed--;
						availableLanguages[2][i] = false;
					}
					else if(j == 2 && sourceNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						sourceFound++;
						sourceNeed--;
					}
				}
			}
		}
	}
	for(unsigned int i = 0; i < flightAttendants.size(); i++){
		if(int(availableLanguages[0][i]) + int(availableLanguages[1][i]) + int(availableLanguages[2][i]) == 3){ //If an attendant speaks 3 languages
			for(int j = 0; j < 2; j++){
				if(int(availableLanguages[j][i]) == 1){
					if(j == 0 && englishNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						englishFound++;
						englishNeed--;
						availableLanguages[1][i] = false;
						availableLanguages[2][i] = false;
					}
					else if(j == 1 && destinationNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						destinationFound++;
						destinationNeed--;
						availableLanguages[2][i] = false;
					}
					else if(j == 2 && sourceNeed > 0){
						filledAttendants.push_back(flightAttendants[i]);
						sourceFound++;
						sourceNeed--;
					}
				}
			}
		}
	}

	if(englishNeed == 0 && sourceNeed == 0 && destinationNeed == 0 && attendantsFilled == false){
		attendantsFilled = true;
		completedAttendants = filledAttendants;
		return true;
	}
	else{
		return false;
	}
}

bool Flight::setPilots(vector<Pilot*> pilots){

	unsigned int copilotsFound = 0;
	unsigned int captainsFound = 0;

	if(pilots.size() < pilotsNeed){  //Checks if the number of available pilots is too low to be viable
		return false;
	}

	for(unsigned int i = 0; i < pilots.size(); i++){

		if(pilots[i]->getLevel() == Pilot::CO_PILOT){     //Adds pilots depending on level and if they are needed; updates counts to reflect this

			if(copilotsNeed != 0){
				copilotsNeed--;
				copilotsFound++;
				filledPilots.push_back(pilots[i]);
			}
		}
		else if(pilots[i]->getLevel() == Pilot::CAPTAIN){

			if(captainsNeed != 0){
				captainsNeed--;
				captainsFound++;
				filledPilots.push_back(pilots[i]);
					}
		}
	}

	if(captainsNeed == 0 && copilotsNeed == 0 && pilotsFilled == false){ //If all roles have been successfully filled and flight has not been filled prior,
		pilotsFilled = true;                                             //the status is changed to pilotsFilled and method is successful
		completedPilots = filledPilots;                                  //The return vector is filled with the working vector
		return 1;
	}
	else{
		return 0;
	}
}

bool Flight::bookTicket(int quantity){

	if(availableSeats >= quantity){  //Checks if seats are available
		availableSeats = availableSeats - quantity;
		return true;
	}
	else{
		return false;
	}
}

int Flight::getAvailableSeats() const{
	return availableSeats;
}

Route* Flight::getRoute() const{
	return flightRoute;
}

Airplane* Flight::getAirplane() const{
	return flightAirplane;
}

vector<Pilot *> Flight::getPilots() const{
	return completedPilots;
}

vector<FlightAttendant *> Flight::getFlightAttendants() const{
	return completedAttendants;
}

Flight::~Flight(){
	flightRoute = 0;
	flightAirplane = 0;
}
