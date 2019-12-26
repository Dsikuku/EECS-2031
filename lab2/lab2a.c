#include <stdio.h>

main() {

	int c;
	int d = 0;
	int v = 0;
	int i;

	while ((c = getchar()) != '\n') {
			for (i = 0; i <= 9; i++) {
				if (c - '0' == i){
					d++;
					v = v + i;	
			}		
		}
	}

	printf("%d\t", d);
	printf("%d\n", v);

}
