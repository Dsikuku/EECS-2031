#include <stdio.h>

#define MAX_SIZE 100

main(){

	char c;
	char my_strg[MAX_SIZE];
	int my_int;
	int i = 0;

	int j;

	while ((c = getchar()) != '\n'){
		if (c >= '0' && c <= '0')
			my_strg[i++] = c - 48;
		else if (c >= 'a' && c <= 'f')
			my_strg[i++] = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			my_strg[i++] = c - 'A' + 10;
	}

	my_int = 0;
	
	for (j = 0; j < i; j++)
		my_int = my_strg[j] + (my_int * 16);

	printf("%d\n", my_int);

	return 0; 

}
