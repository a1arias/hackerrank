/******************************************************************************
 *
 *       Filename:  insertionSort1.c
 *
 *    Description:  insertion sort part 1
 *
 *
 *         Author:  Adrian Arias (a-a), 
 *   Organization:  Elusys
 *
 ******************************************************************************

Input:
------

This program takes two arguments from stdin:

    s
and
    ar

The first line is V. The value of V, s, represents the length of a sorted 
integer array, ar. The value provided on this line must be an int in the 
range of 1 and 1000.

The second line of input are the values for ar. The cumulative number of 
input values provided on this line, x, must be in the range of 10000 and 
-10000;


Problem:
--------

Given a sorted list with an unsorted value in the rightmost "cell", insert
it into the array so that the array remains sorted. 

Print the array everytime a value is shifted until the array is fully sorted.

If, V = the length of ar = 5, then:

Sample Input
5
2 4 6 8 3

Sample Output
2 4 6 8 8 
2 4 6 6 8 
2 4 4 6 8 
2 3 4 6 8 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

/* This function prints an array: ar. Since
ar is an array, this implemntation iterates it
building a string up at each pass and finally printing it.

    Usage:

        int size = 4;
        int poo[size];
        char stringpoo[] = "1 2 3 4";
        for(int i=0; i<size; i++)
        {
            sscanf(stringpoo, "%d", &poo[i]);
        }
        printAr(4, poo);
*/
void printAr(int ar_size, int * ar)
{
    // declare a char[] the size of twice ar_size + 1
    // * 2 to give room for spaces and +1 for \0
    unsigned long loopResultSize = ((ar_size*sizeof(int))*2+1);
    char loopResult[loopResultSize];

    #ifdef DEBUG
    printf("array strlen: %lu\n", strlen(loopResult));
    printf("loopResultSize: %lu\n", loopResultSize);
    #endif

    for(int i=0; i<ar_size; i++)
    {
        // 6 for the \0
        char thisval[6];
        sprintf(thisval, "%d", ar[i]);

        // Since this is the first pass
        if(i == 0)
        {
            // string is initialized first
            strcpy(loopResult, thisval);
            // and padded with a space.
            strcat(loopResult, " ");
        } else {
            // Then, on subsequent passes
            // the string is concatenated.
            strcat(loopResult, thisval);
            strcat(loopResult, " ");
        }
    }

    // Finally the string is terminated with a newline 
    strcat(loopResult, "\n");
    // and printed.
    #ifdef DEBUG
    printf("array: %s", loopResult);
    #else
    printf("%s", loopResult);
    #endif
}

/* 
This function performs an insertion sort on the input array, 
ar. It is expectatd that the input array will have an unsorted
value in the last item of the array.

    Usage:

        int _ar_size = 5;
        int _ar[_ar_size], _ar_i;
        // initialize the integer array 
        for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)
        { 
            // reading values in at each pass.
            scanf("%d", &_ar[_ar_i]); 
        }

*/
void insertionSort(int ar_size, int *  ar)
{
    // V is the last item
    int V = ar[ar_size-1];

    #ifdef DEBUG
    printf("ar_size: %d, V: %d\n", ar_size, V);
    printf("*****************\n");
    #endif

    // Iterate, count down from the size of ar.
    for(int i=ar_size-1; i>=0; i--)
    {
        // i-1 to iterate from right to left

        int left = ar[i-1], right = ar[i];
        
        #ifdef DEBUG
        printf("%d________\n", i);
        printf("left: %d, right: %d\n", left, right);
        #endif
    
        // if left is greater than right or if i is the last item
        if(i+1 == ar_size || (left < right && left > V))
        {
            ar[i] = ar[i-1];
        } else if(left < V && (left < right && right > V)) {
            // set this item's value to the previous item's value.
            ar[i] = V;
        } else {
            // stop scanning because the array should be sorted
            break;
        }
        printAr(ar_size, ar);

    }
}

int main(void)
{
    // get the first line of input which represents the size of 
    // the input array.
    int _ar_size;
    scanf("%d", &_ar_size);
    // declare the input array and iterator counter
    int _ar[_ar_size], _ar_i;
    // initialize the integer array 
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)
    { 
        // reading and assigning values from stdin in at each pass.
        scanf("%d", &_ar[_ar_i]); 
    }

    // perform the insertion
    insertionSort(_ar_size, _ar);

    return 0;
}


