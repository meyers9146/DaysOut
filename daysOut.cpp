/*
*Class: CMSC140
*Instructor: Ahmad Tarek
*Description: Program to calculate the average number of employee days off
*Due Date: April 17, 2018
*Platform/Compiler: Windows 7, Visual Basic Studio 2017
*I pledge that I have completed the programming assignment independently.
*I have not copied the code from a student or any source.
*I have not given my code to any student.
*Print your name here: Michael Meyers
*
*Pseudocode:
*PRINT header
*INPUT number of employees
*VALIDATE input
*INPUT employee #1 ID
*INPUT employee #1 Days Off
*VALIDATE input
*ADD days off to running total
*REPEAT as needed for each employee
*CALCULATE average as running total / number of employees
*SAVE to file
*DISPLAY programmer name
*/

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int numEmployees(); //to return the number of employees in the company
double daysMissed(ofstream&, int); //to generate a file and return total days missed
double averager(int, double); //to return the average number of days absent

int main() {

	string filename = "employeeAbsences.txt";
	
	//Create output stream for entered data
	ofstream outputFile;
	outputFile.open(filename);

	//Console header
	cout << "Calculate the average number of days a company's employees are absent." << endl << endl;
	
	//Calculate average and write to file; close file at completion 
	int numberOfEmployees = numEmployees();
	double average = averager(numberOfEmployees, daysMissed(outputFile, numberOfEmployees));
	outputFile << "The average number of days absent is " << showpoint << fixed << setprecision(1) << average
		<< " days.";
	outputFile << "\n\nProgrammer: Michael Meyers";
	outputFile.close();

	system("pause");
	return 0;
}

//Function to prompt for number of employees
int numEmployees() {
	int empQty; //To hold the quantity of employees
	cout << "Please enter the number of employees in the company: ";
	cin >> empQty;
	//Validate
	while (empQty <= 0){ 
		cout << "Employees cannot be less than 1. Please re-enter: ";
		cin >> empQty;
	}
	return empQty;
}


//Function to prompt for employee ID and days out for each employee specified in numEmployees()
double daysMissed(ofstream &outputFile, int numEmployees) {
	int empID, daysOut; //To hold entered information
	int totalDaysOut = 0; //Running total to be returned at end of function

	//Send headers to file 
	outputFile << "EMPLOYEE ABSENCE REPORT" << endl;
	outputFile << "Employee ID    Days Absent" << endl;

	for (int i = 1; i <= numEmployees; i++) {
		//Input information from user
		cout << "Please enter an employee ID: ";
		cin >> empID;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> daysOut;
		//Validate
		while (daysOut < 0){ 
			cout << "Days out cannot be negative. Please re-enter: ";
			cin >> daysOut;
		}

		//Add to file and running total
		outputFile << setw(8) << empID;
		outputFile << setw(10) << daysOut << endl;
		totalDaysOut += daysOut;
	}

	outputFile << "\nThe " << numEmployees << " employees were absent a total of "
		<< totalDaysOut << " days." << endl;

	cout << "\nProgrammer: Michael Meyers" << endl; //Send Programmer Name to console output

	return totalDaysOut;
}

//Take the results of the previous two functions and return average
double averager(int employees, double daysOut) {
	double averageDaysOut = (daysOut / employees);
	return averageDaysOut;
}