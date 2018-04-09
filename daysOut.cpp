#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

int numEmployees(); //to return the number of employees in the company
int daysMissed(string, int); //to generate a file and return total days missed
double averager(int, int); //to return the average number of days absent



int main() {

	string filename = "employeeAbsences.txt";
	//Create output stream for entered data
	ofstream outputFile;
	outputFile.open(filename);

	//Send headers to file 
	outputFile << "EMPLOYEE ABSENCE REPORT" << endl;
	outputFile << "Employee ID    Days Absent" << endl;

	//Close file to allow daysMissed() function to write
	outputFile.close();

	//Console header
	cout << "Calculate the average number of days a company's employees are absent." << endl << endl;
	
	//Calculate average and write to file; close file at completion
	double average = averager(numEmployees(), daysMissed(filename, numEmployees()));
	outputFile.open(filename);
	outputFile << "The average number of days absent is " << showpoint << fixed << setprecision(1) << average
		<< " days.";
	outputFile << "\n\n Programmer: Michael Meyers";
	outputFile.close();

	system("pause");
	return 0;
}

//Function to prompt for number of employees
int numEmployees() {
	int empQty; //to hold the quantity of employees
	cout << "Please enter the number of employees in the company: ";
	cin >> empQty;
	return empQty;
}

//Function to prompt for employee ID and days out for each employee specified in numEmployees()
int daysMissed(string filename, int numEmployees) {
	int empID, daysOut; //to hold entered information
	int totalDaysOut = 0; //running total to be returned at end of function

	ofstream outputFile;
	outputFile.open(filename);

	for (int i = 1; i <= numEmployees; i++) {
		//input information from user
		cout << "Please enter an employee ID: ";
		cin >> empID;
		cout << "Please enter the number of days this employee was absent: ";
		cin >> daysOut;

		//add to file and running total
		outputFile << setw(4) << empID << "      ";
		outputFile << setw(4) << daysOut << endl;
		totalDaysOut += daysOut;
	}

	outputFile.close();
	return totalDaysOut;
}

//Take the results of the previous two functions and return average
double averager(int employees, int daysOut) {
	double averageDaysOut = (daysOut / employees);
	return averageDaysOut;
}