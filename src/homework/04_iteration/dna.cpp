#include "dna.h"
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/




/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/



/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/




//write the function code for the factorial and gcd functions using 
//a loop of your choice.  Do not use a recursive solution to solve this problem.

int factorial (int num)
{
    int sum = 1;
    
        while (num > 0)
        {
             sum *= num;
             num -= 1;
        }

return sum;
}


int gcd (int num1 , int num2)
{
    int swap_placeholder;

    while (!(num1 == num2))
    {
        if (num1 < num2)
        {
            //swap num1 and num2
            swap_placeholder = num1;
            num1 = num2;
            num2 = swap_placeholder;
        }
        else if (num1 > num2)
        {
            num1 -= num2;
        }
    }

    return num1;
}