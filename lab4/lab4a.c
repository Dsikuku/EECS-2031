#include <stdio.h>

#define MAX_SIZE 500

void myStrInput ( char *s );
int myStrCmp( char *s1, char *s2 );

main()
{
	char strg1[ MAX_SIZE ], strg2 [ MAX_SIZE ];	

	myStrInput( strg1 );
	myStrInput( strg2 );
	printf( "%d\n", myStrCmp( strg1, strg1 ));
}

void myStrInput ( char *s )
{
	char c;
	c = getchar();
	while ( c != '\n' ){
		*s = c;
		s++;
		c = getchar();
		}
		*s = '\0';
}

int myStrCmp( char *s1, char *s2)
{
	int pos = 0, dif = -1;
	while ( *(s1 + pos) != '\0' && *(s2 + pos) != '\0' ){
	if ( *(s1 + pos) != *(s2 + pos) && dif == -1)
		dif = pos;
		pos++;
	}
	if ( *(s1 + pos) != *(s2 + pos) && dif == -1 )
		dif = pos;

	return dif;
}
