#include <stdio.h>

main() {

	int blanks = 0;
	char c;

	printf("Enter a line of characters > ");
	c = getchar();
	
	while ((c = getchar()) != '\n'){
		if (c == ' ')
			blanks++;
	}
	printf("%d\n", blanks);

}
