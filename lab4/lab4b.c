#include <stdio.h>

#define MAX_SIZE 100

main() {

	char my_strg[ MAX_SIZE ];
	double my_number = 0.0;

	int c, i = 0;
	int n = 0;
	double frac = 0.0;

	while ((c = getchar()) != '\n' )
		my_strg[ i++ ] = c;
		my_strg[ i ] = '\0';

	for (i = 0; my_strg[ i ] != '.'; i++)
		my_number = my_number * 10 + ( my_strg[ i ] - '0' );
	
	for (i++, n = 0; my_strg[i] != '\0'; i++, n++)
		frac = frac * 10 + (my_strg[ i ] - '0');

	for (i = 1; i <= n; i++)
		frac /= 10;

	my_number += frac;

	printf( "%.2f\n", my_number );
}
