#include <stdio.h>

main () {
	float c;

	printf("Enter the measurement in inches> ");
	
	scanf("%f", &c);
	
	while (c != 0) {
		c = c * 2.54;
		printf("%.2f cm\n", c);
		printf("Enter the measurement in inches> ");
		scanf("%f", &c);		
		}	
	
	}
