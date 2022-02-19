#include<iostream>
#include<string>
using std::cout; using std::cin; using std::string;
//write include statements
#include "decisions.h"

/*
In main write code to capture a letter_grade and credit_hours from the keyboard:


Grade   Credit Hours	grade_points   credit_points
A          3            4              12
B          3            3               9
C          3            2               6
-----------------------------------------------
           9                           27
After each user input convert the Grade to grade points by calling the get_grade_points function, and
keep a running total for both credit_points and credit_hours.

Call the calculate_gpa function with its arguments.
The GPA should calculate to 3.0, make sure to display it before program exits.

Display:
GPA 3.0

*/
/* int main() 
{
	string letter_grade;
	int credit_hours, sum_credit_hours = 0, sum_credit_points = 0;

	cout << "Enter letter grade: ";
	cin >> letter_grade;
	cout << "Enter credit hours: ";
	cin >> credit_hours;
	sum_credit_points += get_grade_points(letter_grade) * credit_hours;
	sum_credit_hours += credit_hours;

	cout << "Enter letter grade: ";
	cin >> letter_grade;
	cout << "Enter credit hours: ";
	cin >> credit_hours;
	sum_credit_points += get_grade_points(letter_grade)  * credit_hours;
	sum_credit_hours += credit_hours;

	cout << "Enter letter grade: ";
	cin >> letter_grade;
	cout << "Enter credit hours: ";
	cin >> credit_hours;
	sum_credit_points += get_grade_points(letter_grade)  * credit_hours;
	sum_credit_hours += credit_hours;


	double gpa = calculate_gpa(sum_credit_hours, sum_credit_points);
	cout << "GPA: " << gpa;

	return 0;
} */


int main()
{	
	int userInput;
	
	// Printing the menu
	cout << 
	"	MAIN MENU\n\n" <<
	"1-Letter grade using if\n" <<
	"2-Letter grade using switch\n" <<
	"3-Exit\n";
	cin >> userInput;


	// Running the if function
	if (userInput == 1)
	{
		cout << "===Letter Grade evaluation using If Else-If statements===\n";
		cout << "Enter a number grade between 0 and 100 (inclusive): ";
		cin >> userInput;


		if ((userInput >= 0) && (userInput <= 100)) 
		{
			cout << "Your letter grade is: " << get_letter_grade_using_if(userInput) << "\n";
		}
		else
		{
			cout << "Your number is out of range.\n";
		}

	}

	// Running the switch function
	else if (userInput == 2)
	{
		cout << "===Letter Grade evaluation using a switch statement===\n";
		cout << "Enter a number grade between 0 and 100 (inclusive): ";
		cin >> userInput;

		if ((userInput >= 0) && (userInput <= 100)) 
		{
			cout << "Your letter grade is: " << get_letter_grade_using_switch(userInput) << "\n";
		}
		else
		{
			cout << "Your number is out of range.\n";
		}
		
	// Exit
	}
	else
	{
		cout << "Exiting...";
	}


	return 0;
}