#include <iostream>
#include "Employee.h"
using namespace std;

int main(){
	
	int option;
	Employee employee;
	
	while(1){
		system("cls");
		cout << "************************************************" << endl;
		cout << "=====================WELCOME====================" << endl;
		cout << "************************************************" << endl;
		cout << "\n1. Add Employee to the database." << endl;
		cout << "2. Show all employees in the database." <<endl;
		cout << "3. Update employee details from the database." <<endl;
		cout << "4. Remove employee from the database. " <<endl;
		cout << "5. EXIT." <<endl;
		cout << "\n***********************************************" << endl;
		cout << "\n\nCHOOSE OPTION: ";
		cin >> option;
	
		switch(option){
			case 1:
				system("cls");
				employee.writeRecord();
				system("pause");
				break;
			case 2:
				system("cls");
				employee.readRecord();
				system("pause");
				break;
			case 3:
				//On the todo list
				break;
			case 4:
				//On the todo list
				break;
			case 5:
				exit(0);
			default:
				cout << "Invalid option. Please choose the correct option." <<endl;
				system("pause");
		}
	}
}
