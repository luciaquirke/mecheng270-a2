#include "FlightAttendant.hpp"

FlightAttendant::FlightAttendant(const string &name, int ID) : Employee(name, ID){
}

void FlightAttendant::addLanguage(Country::Language language){

	bool alreadyPresent = false;

	for(unsigned int i = 0; i < spokenLanguages.size(); i++){ //Checks if language being entered has already been added
		if(spokenLanguages[i] == language){
			alreadyPresent = true;
		}
	}
	if(alreadyPresent == false){ //If language has not yet been added, it is added
		spokenLanguages.push_back(language);
	}
}

bool FlightAttendant::canSpeak(Country::Language language) const{

	for(unsigned int i = 0; i < spokenLanguages.size(); i++){ //Checks if any language in array matches the one given
		if( spokenLanguages[i] == language){
			return true;
		}
	}
	return false;
}
