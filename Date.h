#ifndef DATE_H
#define DATE_H

class Date
{
	public:
		Date();
		//Setters 
		void setDay(int d);
		void setMonth(int m);
		void setYear(int y);
		
		//Getters
		int getDay();
		int getMonth();
		int getYear();
	private:
		int day, month, year;
};

#endif
