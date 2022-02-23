//write include statements
#include <iostream>
#include "dna.h"

//write using statements
using std::cout; using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int cont;
	int menu_choice;
	int fac_func_inp;
	int fac_result;
	int gcd_inp1, gcd_inp2;
	int gcd_result;

	do
	{
		//display menu
		cout <<
		"\n===MENU===\n"
		"1-Factorial\n" <<
		"2-Greatest Common Divisor\n" <<
		"3-Exit\n";


		cin >> menu_choice;


		//evaluate user's menu selection
		switch (menu_choice)
		{
		case 1:
			cout << "Factorial Function\nEnter a number: ";
			cin >> fac_func_inp;

			fac_result = factorial (fac_func_inp);

			cout << fac_func_inp << "! = " << fac_result << "\n";
			break;

		case 2:
			cout << "Greatest Common Divisor Function\nEnter the first number: ";
			cin >> gcd_inp1;
			cout << "Enter the second number: ";
			cin >> gcd_inp2;
			
			gcd_result = gcd(gcd_inp1, gcd_inp2);

			cout << "The greatest common divisor of " << 
					gcd_inp1 << " and " << gcd_inp2 << 
					" = " << gcd_result << "\n\n";

			break;

		case 3:
			cout << "Are you sure you want to exit? (enter 0 to confirm exit)   ";
			cin >> cont;
			cout << "\n";
			break;
		
		default:
			cout << "Invalid menu option.\n";
			break;
		}

	} while ( cont != 0 );
	

	return 0;
}