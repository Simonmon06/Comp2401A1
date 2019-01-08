#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_POS 70
#define MAX_STR 32
#define TRUE     1
#define FALSE    0

int  randomInt(int);


int main()
{

  srand(time(NULL));



  return 0;
}


/*
  Function:  randomInt
  Purpose:   returns a random number in the range [0,max)
  Parameters:
    in:      maximum of range
    return:  randomly generated number
*/

int randomInt(int max)
{
  return(rand() % max);
}

