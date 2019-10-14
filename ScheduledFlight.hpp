#ifndef SCHEDULEDFLIGHT_HPP
#define SCHEDULEDFLIGHT_HPP

#include "Flight.hpp"
#include "Date.hpp"

class ScheduledFlight{

private:
	Flight* scheduledFlight;
	Date* scheduledDate;
public:
	ScheduledFlight(Flight* flight, Date* time);
	Flight* getFlight();
	Date* getDate();
};

#endif
