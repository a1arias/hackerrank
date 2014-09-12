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

int calcMovesToPalindrome(char *word)
{
  int totalOperations = 0;
  char palindromed[strlen(word)];
  strcpy(palindromed, word);
  #ifdef DEBUG
  //printf("palindromed: %s\n", palindromed);
  #endif
  char first = palindromed[0];
  char last = palindromed[sizeof(palindromed)-1];
  int midway = (first + last) / 2;
  #ifdef DEBUG
  //printf("first: %d last: %d \n", first - 'a' + 1, last - 'a');
  printf("first: %c %d, last: %c %d\n", first, first, last, last);
  #endif

  // get the midway point
  float ffirst = (float)first;
  float flast = (float)last;
  float fmidway = (ffirst + flast) / 2;

  // iterate for half the times of characters (minus the \0)
  // or (strlen(word))/2
  int timesToIter = strlen(palindromed)/2;
  int result[timesToIter];
  #ifdef DEBUG
  printf("palindromed length: %lu\n", strlen(palindromed));
  printf("times to iterate: %d\n", timesToIter);
  printf("---------------------------\n");
  #endif
  // iterate half the times of chars
  for(int i=0; i<timesToIter; i++)
  {
      char left = palindromed[i];
      char right = palindromed[(strlen(palindromed)-1)-i];
      int distance = abs(left - right);
      int opsThisLoop = 0;
      #ifdef DEBUG
      printf("%d_____\n", i);
      printf("left: %c, right: %c\n", left, right);
      printf("distance: %d\n", distance);
      #endif


      // if left is > right
      if(left > right)
      {
        // convert left
        #ifdef DEBUG
        printf("setting left (%c) to %c\n", right, left);
        #endif
        palindromed[i] = right;
      } else if(left < right) {
        #ifdef DEBUG
        printf("setting right (%c) to %c\n", right, left);
        #endif
        palindromed[(strlen(palindromed)-1)-i] = left;
      } else {
        #ifdef DEBUG
        printf("right (%c) and left (%c) are equal\n", right, left);
        break;
        #endif
      }
      #ifdef DEBUG
      printf("palindromed %s\n", palindromed);
      printf("---------------------------\n");
      #endif
      // you can't just count the copy assignment as a single operation.
      // you have to count down from the distance
      opsThisLoop += distance;
      totalOperations += opsThisLoop;
      #ifdef DEBUG
      printf("opsThisLoop: %d\n", opsThisLoop);
      printf("totalOpsSoFar: %d\n", totalOperations);
      #endif
  }

  return totalOperations;
}

int main()
{
  char line1[100];
  int numTestCases;
  char *testCases[10];
  int testCaseResults[10];
  
  // read 1 line of input
  fgets(line1, sizeof(line1), stdin);
  // T represents the number of test cases
  int matches = sscanf(line1, "%d", &numTestCases);
  // this line, T, should be an int
  if(matches < 1)
  {
    #ifdef DEBUG
    printf("input must be in integer\n");
    #endif
    return 1;
  }

  // T should be <= 10 and >= 1
  if(!(1 <= numTestCases) || !(numTestCases <= 10))
  {
    #ifdef DEBUG
    printf("number of test cases must be between 1 and 10, inclusive\n");
    #endif
    return 1;
  }
  #ifdef DEBUG
  printf("Number of Test Cases: %d\n", numTestCases);
  printf("**********************************\n");
  #endif

  // for each test case 
  for(int i=0; i<numTestCases; i++)
  {
    char testLine[10000];
    char *word;

    // read a line
    fgets(testLine, sizeof(testLine), stdin);
    //printf("testLine strlen: %lu\n", strlen(testLine));
    // allocate just enough memory for length of input string
    word = malloc(strlen(testLine));

    // the line should be a string (one word)
    int matches = sscanf(testLine, "%s", word);
    //printf("matches: %d\n", matches);
    if(matches < 1)
    {
      #ifdef DEBUG
      printf("Invalid test case input. Must be a single word < 100");
      #endif
      return 1;
    }

    // save the testCase word for later
    // the length of the string should be >=1  and <= 10e4

    testCases[i] = word;

    #ifdef DEBUG
    printf("**********************************\n");
    #endif

    free(word);
  }

  for(int i=0; i<numTestCases; i++)
  {
    int moves = calcMovesToPalindrome(testCases[i]);
    #ifdef DEBUG
    printf("testWord: %s\n", testCases[i]);
    #endif
    testCaseResults[i] = moves;
    #ifdef DEBUG
    printf("**********************************\n");
    #endif
    printf("%d\n", moves);
  }
  
  return 0;
}

