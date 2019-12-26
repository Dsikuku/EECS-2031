/***********************************
* EECS2031 - Assignment 1
* Filename: poly.c 
* Author: Geller, David
* Email: dgeller@my.yorku.ca
* Login ID: Your EECS login ID
************************************/

#include "poly.h"


/* 
  Initialize all coefficients and exponents of the polynomial to zero.
 */
void init_polynom( int coeff[ ], int exp[ ] )
{

   /* ADD YOUR CODE HERE */

	int i;
	for ( i = 0; i < ASIZE; i++) {
		coeff[i] = 0;
		exp[i] = 0;
	}

}  /* end init_polynom */


/*
  Get inputs from user using scanf() and store them in the polynomial.
 */
void get_polynom( int coeff[ ], int exp[ ] )
{

   /* ADD YOUR CODE HERE */
	
	int input[ASIZE];
	int j;
	int ind;
	int indT = 0;

	/* first element*/
	scanf("%d", &input[0]);

	/* rest of input */
	for ( j = 1; j <= (input[0] * 2); j++ ) {
		scanf("%d", &input[j]);
	}
	
	for ( ind = 1; ind < j - 1; ind++, indT++ ) {
 		coeff[indT] = input[ind];
		ind++;
		exp[indT] = input[ind];
	}

}  /* end get_polynom */


/*
  Convert the polynomial to a string s.
 */
void polynom_to_string( int coeff[ ], int exp[ ], char s[ ] )
{

   /* ADD YOUR CODE HERE */

	int ind = 0;
	int indT;

	for (indT = 0; indT < ASIZE; indT++) {

		if (coeff[0] == 0) {
			s[ind++] = '0';
			break;
		} else if (coeff[indT] != 0) {
			int c = coeff[indT];
			int temp = coeff[indT];
			int z = -1;
	
			while ((temp % 10) == 0) {
				temp = c % 10;
				c = c / 10;
				z++;
			}

			c = coeff[indT];
			if (coeff[indT] < 0) {
				s[ind++] = '-';
				c = coeff[indT] * -1;
			} else if (coeff[indT] > 0 && ind > 0) {
				s[ind++] = '+';
			}

			int a = 0; int b = 0;
			
			if (c > 1) {
				if (c >= 1) {
					while ( c >= 1) {
						a = c % 10;
						c = c / 10;
						b = (b * 10) + a;
					}

					c = b; a = 0 ; 
					
					while ( c >= 1) {
						a = c % 10;
						c = c / 10;
						s[ind++] = a + '0';
					}

					int z1 = 0;
					
					while (z1 < z) {
						s[ind++] = '0';
						z1++;
					}
				}
			}

			int exp1 = exp[indT];
	
			if (exp[indT] == 0 && coeff[indT] == 1) {
				s[ind++] = coeff[indT] + '0';
			}

			if (exp[indT] == 0 && coeff[indT] == -1) {
				s[ind++] = 1 + '0';
			}

			if (exp[indT] != 0) {
				s[ind++] = 'x';
			

				if (exp[indT] != 1 && exp[indT] != -1) {
					s[ind++] = '^';
				}

				if (exp[indT] < 0) {
					s[ind++] = '-';
					exp1 = exp[indT] * -1;
				}

				int a = 0;
				int b = 0; 
				int zero = -1; 
				int temp = exp[indT];

				while ((temp % 10) == 0) {
					temp = exp1 % 10;
					exp1 = exp1 / 10;
					z++;
				}

				exp1 = exp[indT];
				if (exp1 > 1) {
					while (exp1 >= 1) {
						a = exp1 % 10;
						exp1 = exp1 / 10;
						b = (b * 10) + a;
					}

					exp1 = b; a = 0;
			
					while (exp1 >= 1) {
						a = exp1 % 10;
						exp1 = exp1 / 10;
						s[ind++] = a + '0';
					}

					int z1 = 0;
			
					while (z1 < z) {
						s[ind++] = '0';
						z1++;
					}
				}
			}
		}
	}

	s[ind] = '\0';

}  /* end polynom_to_string */



/*
  Evaluate the polynomial for the value of x and store the result p(x) in variable result.
 */
void eval_polynom( int coeff[ ], int exp[ ], double x, double *result )
{

   /* ADD YOUR CODE HERE */

	int i, j; 
	double sum = 0;
	double x1;

	for ( i = 0; i < ASIZE; i++ ) {
		x1 = x;
		if (exp[i] != 0) {
			for (j = 0; j < exp[i] - 1; j++) {
				x1 = x1 * x;
			}
			x1 = x1 * coeff[i];
			sum = sum + x1;
		} else {
			x1 = 1 * coeff[i];
			sum = sum + x1;
		}
	}

	*result = sum; 			

}  /* end eval_polynom */



/*
  Add two polynomials and the result is stored in the first polynomial (arrays co1[] and ex1[]).
 */
void add_polynom( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ] )
{

   /* ADD YOUR CODE HERE */
	
	int tempC[ASIZE], tempE[ASIZE];
	int indT;
	int ind1 = 0;	int ind2 = 0;

	for (indT = 0; indT < ASIZE; indT++) {
		if (ex1[ind1] == ex2[ind2]){
			tempC[indT] = co1[ind1] + co2[ind2];
			tempE[indT] = ex1[ind1];
			ind1++;
			ind2++;
		} else if (ex1[ind1] > ex2[ind2]) {
			tempC[indT] = co1[ind1];
			tempE[indT] = ex1[ind1++];
		} else if (ex1[ind1] < ex2[ind2]) {
			tempC[indT] = co2[ind2];
			tempE[indT] = ex2[ind2++];
		}
	}

	int ind3;
	for (ind3 = 0; ind3 < ASIZE; ind3++) {
		co1[ind3] = tempC[ind3];
		ex1[ind3] = tempE[ind3];
	}

}  /* end add_ polynom */

/************************** END OF FILE ***************************/





