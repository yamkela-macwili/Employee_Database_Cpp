#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstring>

using namespace std;

class Employee
{
	public:
		Employee();
		int getAge();
		void setDOB(int d, int m, int y);
		void getDOB();
		
		void read_data();
		void show_data();
		void writeRecord();
		void readRecord();
		
		
		/* TODO (#1#): Add a method to search an employee from the database.*/
		/* TODO (#2#): Add a method to update the employee's details from the database.*/
		/* TODO (#3#): Add a method to Remove an employee from the database.*/
		
	private:
		char first_name[30], last_name[30], job_title[30], recordDate[30];
		Date dateOfBirth;
		float salary;
};

#endif
