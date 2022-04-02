//write include statements
#include<string>
#include<iostream>
using std::cout; using std::cin;

#include "sequence.h"

//write using statements for cin cout


/*
Write code to create a vector of string names, add the values "John", "Mary", "Patty",
"Sam" to the vector, call the function display_vector and pass the names vector as
an argument, prompt user for a name to search for and a value to replace searched value with.
Afterward, call the update_vector_element with the names vector and call the display_vector
function.
Don't worry about displaying a message for values that aren't found.  Assume user will
give you a valid name.
*/



/*
In main.cpp, write code that prompts user to enter 1 for Get GC Content, or 2 for Get DNA Complement.
The program will prompt user for a DNA string and call either get gc content or get dna complement function and display the result. 
*/
int main()
{

	int menu_choice;
	string dna_string;
	bool exit = false;


	do
	{
		//display menu
		cout <<
		"\n===MENU===\n"
		"1-Get GC Content\n" <<
		"2-Get DNA Complement\n" <<
		"3-Exit\n";

		cin >> menu_choice;


		switch (menu_choice)
		{
		case 1:
			cout << "==GC Content==\n";

			do
			{
				cout << "Enter a DNA string: ";
				cin >> dna_string;
				if ( !validate_dna_string(dna_string) )
				{
					cout << "Invalid DNA string format. Make sure the DNA code is all caps.\n";
				}
			} while ( !validate_dna_string(dna_string) );
			
			
			cout << "The GC Content of \"" << dna_string << "\" is " <<
			(get_gc_content(dna_string) * 100) << "%. (function returned \"" << 
			get_gc_content(dna_string) << "\")\n";
			break;


		case 2:
			cout << "==DNA Complement==\n";

			do
			{
				cout << "Enter a DNA string: ";
				cin >> dna_string;
				if ( !validate_dna_string(dna_string) )
				{
					cout << "Invalid DNA string format. Make sure the DNA code is all caps.\n";
				}
			} while ( !validate_dna_string(dna_string) );


			cout << "The DNA Complement of \"" << dna_string << "\" is \"" <<
			get_dna_complement(dna_string) << "\".\n";
			break;


		case 3:
			exit = true;
			cout << "Exiting...\n";
			break;
		
		default:
			cout << "Invalid menu option.\n";
			break;
		}

	} while (!exit);
	

	return 0;
}

