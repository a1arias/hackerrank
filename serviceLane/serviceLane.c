/******************************************************************************
 *
 *       Filename:  serviceLane.c
 *
 *    Description:  A program that calculates when a given vehicle can enter
 *                  and exit a service lane, given a specific point along
 *                  the highway.
 *
 *
 *         Author:  Adrian Arias (a-a), 
 *   Organization:  Elusys
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// this is represented by 'k' in the problem
enum vehicle
{
  BIKE  = 1,
  CAR   = 2,
  TRUCK = 3
};

int determineLargestVehicle(int entryPoint, int exitPoint, int *freeway, int freewayLength)
{
  int valToReturn = 0;

  //printf("%d %d\n", entryPoint, exitPoint);
  if(2 <= (exitPoint - entryPoint + 1) <= fmin(freewayLength, 1000)){
    for(int iter=entryPoint; iter<=exitPoint; iter++)
    {
      //printf("iter: %d\n", iter);

      // check for an initial value of 0
      // the valToReturn be the smallest of all
      // the segments between entryPoint and exitPoint
      //printf("freeway[%d]: %d\n", iter, freeway[iter]);
      if(freeway[iter] < valToReturn || valToReturn == 0)
      {
        valToReturn = freeway[iter];
        //printf("setting valtoReturn: %d\n", valToReturn);
      }
    }
  }

  return valToReturn;
}

int printFreeway(int *freeway, int freewayLength)
{
  for(int iter=0; iter<freewayLength; iter++)
  {
    char asciiSegment[6];
    
    int width = freeway[iter];
    
    if(width == BIKE)
    {
      strcpy(asciiSegment, "|-|  ");
    } else if(width == CAR) {
      strcpy(asciiSegment, "|--| ");
    } else if(width == TRUCK) {
      strcpy(asciiSegment, "|---|");
    }
    printf("%d: | \t%s \t%d\n", iter, asciiSegment, width);
  }

  return 0;
}

int getTestCases()
{
  return 0;
}

int main()
{
  int freewayLength;
  int numTestCases;
  char line1[100];

  // get the first line of input
  fgets(line1, sizeof(line1), stdin);
  // the first digit is the freeway length. the second digit is the number
  // of test cases.
  sscanf(line1, "%d %d", &freewayLength, &numTestCases);

  if(!(2 <= freewayLength && freewayLength <= 100000) || 
     !(1 <= numTestCases && numTestCases <= 1000))
  {
    return 1;
  }

  //printf("***********************************************\n");

  // create freeway of given length
  int freeway[freewayLength];

  // create array for storing test case points
  // testCasePoints[numTestsCases][0] is the entryPoint
  // testCasePoints[numTestsCases][1] is the exitPoint
  int testCasePoints[numTestCases][2];
  
  int line2Size = freewayLength * 2 + 1;
  char line2[line2Size];
  // get the second line of input
  fgets(line2, sizeof(line2), stdin);

  //printf("***********************************************\n");

  // start counting freeway segments
  int freewaySegment = 0;

  char *sep = " ";
  char *token, *brkt;
  char line2copy[line2Size];

  // split the line by spaces
  strcpy(line2copy, line2);
  if(line2copy == NULL)
    return 1;

  for(token = strtok(line2copy, sep); token; token = strtok(NULL, sep))
  {
    //printf("token: %s %d\n", token, atoi(token));
    //printf("freewaySegment: %d\n", freewaySegment);
    // assign this segment's width to the value of token
    freeway[freewaySegment] = atoi(token);
    // increment the segment count for the next pass of strsep
    freewaySegment++;
  }

  //printf("***********************************************\n");

  // for each test case
  for(int iter=0; iter<=numTestCases-1; iter++)
  {
    // setup for getting points
    int entryPoint, exitPoint;
    char line3[100];

    // get the values for entry point and exit point (i and j respectively)
    fgets(line3, sizeof(line3), stdin);
    sscanf(line3, "%d %d", &entryPoint, &exitPoint);
    
    // assign the points for later use
    testCasePoints[iter][0] = entryPoint;
    testCasePoints[iter][1] = exitPoint;
  }

  //printf("***********************************************\n");

  // execute testCases
  for(int iter=0; iter<numTestCases; iter++)
  {
    int entryPoint = testCasePoints[iter][0], exitPoint = testCasePoints[iter][1];
    //printf("test case %d: %d %d\n", iter, entryPoint, exitPoint);
    if(0<=entryPoint && entryPoint < exitPoint && exitPoint < freewayLength)
    {
      // all good
      int largestVehicle = determineLargestVehicle(
        entryPoint, exitPoint, freeway, freewayLength);

      //printf("largestVehicle: %d\n", largestVehicle);
      printf("%d\n", largestVehicle);
      //printf("***********************************************\n");
    }
  }

  //printFreeway(freeway, freewayLength);

  return 0;
}

