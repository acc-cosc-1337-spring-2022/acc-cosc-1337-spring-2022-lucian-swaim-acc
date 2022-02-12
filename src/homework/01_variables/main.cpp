//write include statements
#include <iostream>
#include "variables.h"

//write namespace using statement for cout
using std::cin; using std::cout;


int main()
{

	// a) Create an int variable named num.
	int num;
	// c) Create an int variable name result
	int result;
	// d) Create an int variable named num1, assign it the value 4.
	int num1 = 4;


	//b) Use the cin object to capture a number from the keyboard, assign the number to num.
	cout << "Enter a number: ";
	cin >> num;


	/* c) call the multiply_numbers with num as its parameter, 
     assign the return value of the function multiply_numbers to the result variable,
	 and display the result variable to the screen.    */
	result = multiply_numbers(num);
	cout << "The result using num is: " << result << "\n";

	/* e) Call the function multiply_numbers with num1 as its parameter, assign its return value to the 
     result variable, and display the result variable to screen.    */

	 result = multiply_numbers(num1);
	 cout << "The result using num1 is: " << result << "\n";


	return 0;
}
