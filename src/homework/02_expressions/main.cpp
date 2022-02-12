//write include statements
#include "../src/homework/02_expressions/expressions.h"
#include <iostream>

//write namespace using statement for cout
using std::cout, std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;
	cout << "Enter the amount for the meal:  ";
	cin >> meal_amount;

	tax_amount = get_sales_tax_amount(meal_amount);

	cout << "Enter the tip rate in decimal format (example: 20% written as 0.20):  ";
	cin >> tip_rate;
	tip_amount = get_tip_amount(meal_amount, tip_rate);

	total = (tip_amount + tax_amount + meal_amount);


	cout << "\n\n--Your Receipt--\n";
	cout << "Meal Amount:      $" << meal_amount << "\n";
	cout << "Sales Tax:        $" << tax_amount << "\n";
	cout << "Tip Percentage:    " << (tip_rate*100) << "%\n";
	cout << "Tip Amount:       $" << tip_amount << "\n";
	cout << "Total:            $" << total << "\n";

	return 0;
}
