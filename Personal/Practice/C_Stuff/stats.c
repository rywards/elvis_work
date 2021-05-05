/*
 *
 * Original stats_safest appended by Ryan Edwards.
 *
 */
#include <stdio.h>

#define BUFSIZE 256

int main()
{
    int    itemsread = 0;
    double item = -1;     // initial value so loop starts
    int    howmany = 0;
    double    max;
    double    min;
    double sum = 0;
    double mean = 0;
    char   line[BUFSIZE]; // fgets() knows about the NULL

    // check last item wasn't zero; if not
    // read the line from input and copy it to memory as a string
    while ( item != 0 && fgets(line, BUFSIZE, stdin) != NULL ) {

        // scan the number from the line - extra stuff on line is ignored
        itemsread = sscanf(line, "%lf", &item);

        // check to see if we got valid input
        if (itemsread == 1 && item != 0) {
	  if (howmany == 0){
	    min = item;
	    max = item;
	  }
            howmany++;
	  
        }

	// min and max checking
	if (item > max){
	  max = item;
	}

	if (item < min){
	  min = item;
	}
	
	sum = sum + item;
	mean = sum/howmany;

        // this will not get stuck in an infinite loop,
        // plus we can examine the input data
        if (itemsread == 0) {
            printf("bad input\n");
        }
    }
    if (howmany !=0){

      printf("# items: %d\n", howmany);
      printf("Sum: %lf\n", sum);
      printf("Max: %lf\n",max);
      printf("Min: %lf\n", min);
      printf("Mean: %lf\n", mean);
      
    }else{
      printf("No numbers entered\n");
    }
    
    return 0;
}
