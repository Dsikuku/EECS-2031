#include <stdio.h>

void power_of_ten(int *k, double *my_double)
{
	int i;
	*my_double = 1;
	
	for (i = 0; i < *k; i++)
		*my_double *= 10;
}

main()
{
	int k;
	double my_double;

	scanf( "%d", &k );

	power_of_ten(&k, &my_double);

	printf("%.15f\n", my_double);
}

