#include "Employee.h"

Employee::Employee(){
	first_name[30] = ' ' ;
	last_name[30] = ' ';
	job_title[30] = ' ';
	salary = 0;
	recordDate[30] = ' ';
}

//Get the date of birth
void Employee::setDOB(int d, int m, int y){
	dateOfBirth.setDay(d);
	dateOfBirth.setMonth(m);
	dateOfBirth.setYear(y);
}

//Print the date of birth.
void Employee::getDOB(){
	cout << dateOfBirth.getDay() << "-" << dateOfBirth.getMonth() << "-" << dateOfBirth.getYear();
}

//Computes the employee's age 
int Employee::getAge(){
	time_t now = time(0);							//Get the local time 
	tm *localTime  = localtime(&now);				//
	int currentYear = (1900+localTime->tm_year);	//
	int yearBorn = dateOfBirth.getYear();			//From user 
	
	return currentYear - yearBorn;					//Age is the difference 
}

//Reads in user inputs.
//Call getAge to compute the age from the given date of birth.
//Get the current date.
void Employee::read_data(){
	
	int day, month, year;
	Date date;
	cout<<"First Name: ";
	cin>> first_name;
	cout<<"Last Name: ";
	cin>>last_name;
	cout<<"Date of birth (DD/MM/YYYY): ";
	cin >> day >> month >> year;
	cout << "Job title: " ;
	cin >> job_title;
	cout << "Salary: " ;
	cin >> salary;
	
	setDOB(day,month,year);
	getAge();
	
	time_t time_now = time(0);						//Current date/time based on system clock.
	tm *systemTime = localtime(&time_now);
	char *dt = ctime(&time_now);					//Converting "time_now" into string form.
	string currentDate = dt;	
	/* TODO (#1#): Record date should only be printed as (dd/mm/yyyy) */					
	strcpy(recordDate, currentDate.c_str());		// Copying the current date
}

int record_id = 0;		//To count the number of records in the database.

//To used to print the data from the database.
void Employee::show_data(){
	cout << ++record_id << setw(15) << first_name << setw(15) << last_name << setw(10) << 
	dateOfBirth.getDay() << "/" << dateOfBirth.getMonth() << "/" << dateOfBirth.getYear()  
	<< setw(12) << getAge()<< setw(15) << job_title << setw(8)  << "R" << salary<< setw(28) << recordDate  << endl;
	cout << "__________________________________________________________________________________________________________________ " << endl;
}

//Writes the inputted data to the file.
//Uses the "read_data()" to get the user inputs.
void Employee::writeRecord(){
	ofstream outfile;
	outfile.open("employees_db.txt", ios::binary|ios::app);
	read_data();
	outfile.write(reinterpret_cast<char *>(this), sizeof(*this));
	outfile.close();
	cout << first_name << " " << last_name << " added successfully.\n" << endl;
	
	int yesNo;
	cout << "Add another employee? \n1. Yes\n2. No "<< endl;
	cin >> yesNo;
	if(yesNo == 1){
		system("cls");
		writeRecord();
	}
		
	if(yesNo == 2)
		return;
}

//Reads the database and displays the records to the screen.
//Uses the "show_data()" to get the data.
void Employee::readRecord(){
	ifstream infile;
	infile.open("employees_db.txt",ios::binary);
	
	if(!infile){
		cout << "Error in Opening!... \nFile Not Found!!" << endl;
		return;
	}
	
	system("cls");
	cout << "\t\t\t=============================================================" << endl;
	cout << "\t\t\t-----------------Records in the Database---------------------" << endl;
	cout << "\t\t\t=============================================================" << endl;
	cout << "\n";
	cout << "#\t"<< setw(5) <<  "First_name" << setw(15) << "Last_name" << setw(20) <<"Date_of_birth" << setw(8) << "Age" << setw(15) 
	<< "Job_Title" << setw(12) << "Salary" << setw(20) << "Record_Date"<< endl;
	cout << "==================================================================================================================" << endl;
				
	while(!infile.eof()){
		if(infile.read(reinterpret_cast<char*>(this), sizeof(*this)) > 0){
			show_data();
		}
		else{
			cout << "==================================================================================================================" << endl;
			cout << "\nTOTAL RECORDS: " << record_id << endl;
		}
	}
	
	if(infile.read(reinterpret_cast<char*>(this), sizeof(*this)) <= 0){
		cout << "End/No Records found.\n" << endl;
	}
	
	infile.close();
}
