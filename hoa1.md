CASE STUDY 
In this study, our aim is to write a program with multiple functions where we perform computations with common fractions (i.e. a fraction where both top and bottom numbers are integers, e.g. 3/4. For instance, 4.7/4 is not a common fraction) and get results that are also common fractions in a reduced form (e.g. 3/4 is the reduced form of 6/8, 12/16, etc.)

Problem Inputs
int n1, d1, n2, d2 //numerator and denominators
char op //+, -, *, /
char cont // continue or not

Problem Outputs
int n_ans, d_ans

How many functions you need?
•	scan_fraction
•	get_operator
•	add_fractions 
o	for subtracion, use addition with minus sign
•	multiply_fractions
o	for division, use multiply with reciprocal of second 
•	reduce_fraction
o	Find the greatest common divisor of the numerator and denominator
o	Divide both the numerator and the denominator by the greatest common divisor
•	find_gcd
•	print_fraction
•	main

Sample output of scanFraction function:
 















#include <stdio.h>
#include <stdlib.h>    /* provides function abs */

/* Function prototypes */
void scan_fraction(int *nump, int *denomp);
char get_operator(void);
void add_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp);
void multiply_fractions(int n1, int d1, int n2, int d2, int *n_ansp, int *d_ansp);
int find_gcd (int n1, int n2);
void reduce_fraction(int *nump, int *denomp);
void print_fraction(int num, int denom);

int main(void)
{
      int n1, d1;    /* numerator, denominator of first fraction               */
      int n2, d2;    /* numerator, denominator of second fraction              */
      char op;       /* arithmetic operator + - * or /                         */
      char again;    /* y or n depending on user's desire to continue          */
      int n_ans, d_ans; /* numerator, denominator of answer                    */

      /* While the user wants to continue, gets and solves arithmetic
         problems with common fractions                                        */
      do {
          /* Gets a fraction problem                                           */






          /* Computes the result */








         




          /* Displays problem and result                                     */
          printf("\n");
          print_fraction(n1, d1);
          printf(" %c ", op);
          print_fraction(n2, d2);
          printf(" = ");
          print_fraction(n_ans, d_ans);

          /* Asks user about doing another problem                           */
          printf("\nDo another problem? (y/n)> ");
          scanf(" %c", &again);
      }  while (again == 'y' || again == 'Y');
      return (0);
}


//Functions come here





















































