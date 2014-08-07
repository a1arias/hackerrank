/******************************************************************************
 *
 *       Filename:  palindromes.c
 *
 *    Description:  A program to play with palidromes
 *
 *
 *         Author:  Adrian Arias (a-a), 
 *   Organization:  Elusys
 *
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  char *line1;
  int numTestCases;
  // read 1 line of input
  fgets(line1, sizeof(line1), stdin);
  // T represents the number of test cases
  int matches = sscanf(line1, "%d", &numTestCases);
  // this line, T, should be an int
  if(matches < 1)
  {
    printf("input must be in integer\n");
    return 1;
  }

  // T should be <= 10 and >= 1
  if(!(1 <= numTestCases) || !(numTestCases <= 10))
  {
    printf("number of test cases must be between 1 and 10, inclusive\n");
    return 1;
  }

  printf("line1: %d\n", numTestCases);

  // for each test case 
  
  for(int i=0; i<numTestCases; i++)
  {
    //char testLine[100];
    printf("testcase[%d]: \n", i);
    //char line2[100];
    // read a line
    //fgets(testLine, sizeof(testLine), stdin);
    //printf("testLine: %s", testLine);
    // the line should be a string (one word)
    //sscanf(testLine, "%s", word);
    //puts(word);
    //printf("testLine[%d]: %s\n", i, testLine);
    // the length of the string should be >=1  and <= 10e4
  }
  
  return 0;
}
