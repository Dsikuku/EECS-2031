#include <stdio.h>

#define MAX_SIZE 100

main(){

	char my_strg[ MAX_SIZE ];
	int my_int;
	char c;
	int i = 0;
	int j;
	int oct = 1;
	int neg = 0;

	while ((c = getchar()) != '\n'){
		if (c == '-')
			neg = 1;
		else if ((c - 48) > 7)
			oct = 0;
		else
			my_strg[i++] = c - 48;
	}

	if (!oct){
		printf("%s\n", "Error: not an octal number");
	} else {
		my_int = 0;
		for (j = 0; j < i; j++)
			my_int = my_strg[j] + (my_int * 8);
		if (neg) my_int *= -1;
		printf("%d\n", my_int); 
	}
}
