#include "ScheduledFlight.hpp"

ScheduledFlight::ScheduledFlight(Flight* flight, Date* time){
	scheduledFlight = flight;
	scheduledDate = time;
}

Flight* ScheduledFlight::getFlight(){
	return scheduledFlight;
}

Date* ScheduledFlight::getDate(){
	return scheduledDate;
}

