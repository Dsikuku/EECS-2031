/***********************************
* EECS 2031 - Lab 7		   
* Filename: marks.c  	
* Author: Geller, David 
* Email: dgeller@my.yorku.ca	 	
* Login ID: dgeller	
************************************/

#include <stdio.h>
#include <stdlib.h>


  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/

void main( int argc, char *argv[] )
{


  /*****************************************/
  /***** ADD YOUR CODE BELOW THIS LINE *****/

	FILE *ip, *op;
	char first[50], last [50];
	int a1, a2;
	float avg;

	if (argc != 3){
		printf("Usage: marks [input_file] [output_file]\n");
		exit(1);
	}

	ip = fopen(argv[1], "read");

	if (ip == NULL){
		printf("Can't open file %s for reading.\n", argv[1]);
		exit(1);
	}

	op = fopen(argv[2], "write");
	
	if (op == NULL){
		printf("Can't open file %s for writing.\n", argv[1]);
		exit(1);
	}

	while (fscanf(ip, "%s %s %d %d", first, last, &a1, &a2) != EOF){
		avg = ((float)a1 + a2) / 2;
		fprintf( op, "%s %s %d %d %.1f\n", first, last, a1, a2, avg);
		}

	fclose(ip);
	fclose(op);

  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/

}  /* end main */
