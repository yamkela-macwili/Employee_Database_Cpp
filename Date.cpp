#include "Date.h"
Date::Date(){
	day = 0;
	month = 0;
	year = 0;
}
		
void Date::setDay(int d){
	/* TODO (#1#): Validate the day.
	The day has to be between 1 and 31*/
	day = d;
}
		
void Date::setMonth(int m){
	/* TODO (#2#): Validate the month.
	Month has to be between 1 and 12*/
	month = m;
}
		
void Date::setYear(int y){
	/* TODO (#3#): Validate the year.
	The year can not be greater than than the current year,and
	Employee's years can not be less than 18 years.*/
	year = y;
}

int Date::getDay(){
	return day;
}
int Date::getMonth(){
	return month;
}		

int Date::getYear(){
	return year;
}

