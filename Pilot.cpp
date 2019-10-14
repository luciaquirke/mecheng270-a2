#include "Pilot.hpp"

Pilot::Pilot(const std::string &name, int ID) : Employee (name, ID){
	level = CO_PILOT;
}

Pilot::Level Pilot::getLevel() const{
	return level;
}

bool Pilot::promote(){

	if(level == CAPTAIN){  //If pilot already holds this level nothing happens
		return false;
	}
	else{
		level = CAPTAIN; //Changes level
		return true;
	}
}

bool Pilot::demote(){
	if(level == CO_PILOT){;  //If pilot already holds this level nothing happens
		return false;
	}
	else{
		level = CO_PILOT; //Changes level
		return true;
	}
}
