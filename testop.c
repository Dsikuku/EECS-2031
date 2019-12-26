#include <stdio.h>

main(){

int i, j, *p, *q;

p = &i;
q = &j;
i = 1;
j = 2;
p = q;
*q = 3;

printf("%d %d %d %d\n", i, j, *p, *q);

}
