#ifndef TIME_HPP
#define TIME_HPP

class Date{
	int dateDay;
	int dateHour;
public:
    Date(int day, int hour);
    int getDay() const;
    int getHour() const;
    void addTime(int hours);
    bool isLessThan(const Date &other) const;
    void changeDateTo(int day, int hour);
};

#endif /* end of include guard: TIME_HPP */
