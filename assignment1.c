/*
The purpose of this program is to simulate a race between
a tortoise and a hare. They do random move in the race.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_POS 70
#define MAX_STR 32
#define TRUE     1
#define FALSE    0
/* */
int  randomInt(int);
void printPath(int t, int h);
int moveT(int t, int random);
int moveH(int h, int random);
void printWinner(int t, int h);


int main()
{
/* t:the index of tortoise
  h: the index of hare    */
int t= 0;// the position of tortoise
int h= 0;// the position of hare

srand(time(NULL));//pick seed by current time

while(t!=(MAX_POS-1) && h!=(MAX_POS-1)){//break the loop when t=69 or h=69

t = moveT(t,randomInt(100));//move tortoise
h = moveH(h,randomInt(100));//move hare
printPath(t,h);//print the path
//printf("T index:%d\n", t);
//printf("H index:%d\n", h);
//check the update indexes in main function.
}
printWinner(t,h);//print the winner

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

/*
  Function:  printPath
  Purpose:   print a path that contains the avator of tortoise and hare, they are on positions of their updated indexes.
  Parameters:
    in:      index of tortoise
    in:      index of hare
*/

void printPath(int t, int h){
  // create a path full of space
  char newpath[MAX_POS];
  for(int i=0; i<MAX_POS; ++i){
    newpath[i]=' ';
  }
  if(t==h){// if t and h int the same position, set B
    newpath[t]='B';
  }
  else{// set the position of t and h
    newpath[t]='T';
    newpath[h]='H';
  }
  printf("|");
  for(int j=0; j<MAX_POS; ++j){//print the path
  printf("%c",newpath[j]);
  }
  printf("|\n");

  if(t < 0 || t>70){
    printf("ERROR: index t out of range");  //Error checking if t is out of range
  }
  if(h < 0 || h>70){
    printf("ERROR: index h out of range");  //Error checking if h is out of range
  }
  //printf("T is : %d H is: %d \n", t, h);
}


/*
  Function:  moveT
  Purpose:   perfrom a random picking of move for tortoise, and return the index of tortoise after the move.
  Parameters:
    in:      index of tortoise
    in:      a random number in the range [0,max)
    return:  index of tortoise after the move
*/

int moveT(int t, int random1){
  int current1=0;
  if(random1 >= 50){ // fast plod move 3 position up
      if(t<=66){
          current1=t+3;
          return current1;
        }
      else
          return 69;
  }
  else if(50> random1 && random1>=20){//Slow plod  move 1 position up
    current1 = t+1;
    return current1;
  }
  else if(20>random1 &&random1>=0 && t>=6){// Slip move 6 positions down
      current1 = t-6;
      return current1;
  }
  else{
    return t;
  }
}

/*
  Function:  moveH
  Purpose:   perfrom a random picking of move for hare, and return the index of hare after the move.
  Parameters:
    in:      index of hare
    in:      a random number in the range [0,max)
    return:  index of hare after the move
*/
int moveH(int h, int random2){
  int current2 =0;
  if(random2>=80){//Big hop  move 9 positions up
      if(h<=60){
          current2 = h+9;
          return current2;
        }
      else
          return 69;
  }
  else if(80>random2 &&random2>=50){//Small hop move 1 position up
      current2 =h+1;
      return current2;
    }
  else if(50>random2 &&random2>=40 && h>=12){//Big slip move 12 positions down
      current2 = h-12;
      return current2;
    }
  else if(40>random2 &&random2>=20 && h>=2){//Small slip move 2 positions down
      current2 = h-2;
      return current2;
  }
  else{//Sleep no move
    return h;
  }
}


/*
  Function:  printWinner
  Purpose:   print the winner
  Parameters:
    in:      index of tortoise
    in:      index of hare
*/

void printWinner(int t, int h){
  if(t == MAX_POS-1){
    printf("The Winner Is Tortoise!!!");
  }
  if(h == MAX_POS-1){
    printf("The Winner Is Hare!!!");
  }
  if(t == MAX_POS-1 && h== MAX_POS-1){
    printf("Tie!!!!!!!!!!!!!!");
  }
}
