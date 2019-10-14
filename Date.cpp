#include "Date.hpp"

Date::Date(int day, int hour) {
	dateDay = 1;
	dateHour = 1;
	changeDateTo(day, hour);
}

int Date::getHour() const {
    return dateHour;
}

int Date::getDay() const {
	return dateDay;
}

void Date::changeDateTo(int day, int hour) {
	if( (day > 0) && (hour > -1) && (hour < 24) ) { //Checks if date range is valid - if hours are wrong successfully changing day is confusing
		dateDay = day;
		dateHour = hour;
	}
}

void Date::addTime(int count) {
	if(count > 0) {
		int cph = count + dateHour;
		if(cph > 24) {
			int plusDays = cph/24; //Determines number of 24s in the count and adds those to the days
			dateDay = dateDay + plusDays;
			cph = cph - plusDays*24; //cph is converted to hours
		}
		dateHour = cph;
	}
}

bool Date::isLessThan(const Date &other) const {
	if (this->dateDay < other.getDay()) {
		return true;
	}
	if(this->dateDay > other.getDay()){
		return false;
	}
	return (this->dateHour < other.getHour());
}







