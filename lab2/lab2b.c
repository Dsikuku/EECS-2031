#include <stdio.h>

main() {

	int a[100];
	int i, max, min;
	int c = 0;
	
	for (i = 0; i < 100; i++){
		scanf("%d", &a[i]);
		c++;   
		if (a[i] == 0)
		break;
	}

	max = min = a[0];
	
	for (i=1; i < c; i++){
	
	if (max < a[i])
		max = a[i];
	if (min > a[i])
		min = a[i];
	}

	printf("%d\t", max);
	printf("%d\n", min);
}
