/***********************************
* EECS 2031 - Lab 6		   
* Filename: mmavg.c	  	
* Author: Geller, David    
* Email: dgeller@my.yorku.ca	 	
* Login ID: dgeller	
************************************/


#include <stdio.h>
#include <stdlib.h>

	int str2int (char *s){
		int i = 0, value = 0, sign = 1;
		if (s[i] == '-')
			sign = -1;
		if (s[i] == '-' || s[i] == '+')
			i++;
		while (s[i] != '\0'){
			value = value * 10 + s[i] - '0';
			i++;
		}
		return (sign * value);
	}

  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/



/* Function main()
   Input: a set of integers as command-line arguments.
   Output: the maximum, minimum and average of the above set displayed on the standard output.
 */

main( int argc, char *argv[] )
{
  int max, min;
  float avg;

  /*****************************************/
  /***** ADD YOUR CODE BELOW THIS LINE *****/

	int i, num;
	
	if (argc == 1) {
		printf("Usage: mmavg int1 int2 int3... \n");
		exit(1);
	}

	avg = max = min = str2int( argv[1]);
	
	for (i = 2; i < argc; i++){
		num = str2int(argv[i]);		
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		avg += num;
	}

	avg /= (argc - 1);


  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/

  /**** DO NOT ADD OR CHANGE ANYTHING BELOW THIS LINE ****/

  printf( "%d %d %.2f\n", max, min, avg );
}
