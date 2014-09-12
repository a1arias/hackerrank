/******************************************************************************
 *
 *       Filename:  insertionSort2.c
 *
 *    Description:  insertion sort part 2
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

Given an unsorted array, sort it. Print the array everytime a value is 
shifted until the array is fully sorted.

If, V = the length of ar = 6, then:

Sample Input
6
1 4 3 5 6 2

Sample Output
1 4 3 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 2 3 4 5 6 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/* A function to compare two ints. This function returns
1 is key1 is greater than key2 and -1 otherwise.

Params:

    *int key1,
    *int key2

Return:

    signed int

*/
signed int compare(int key1, int key2)
{
    #ifdef DEBUG
    printf("key1: %d, key2: %d\n", key1, key2);
    #endif
    if(key1 > key2)
    {
        return 1;
    } else {
        return -1;
    }
}

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

    for(int i=0; i<ar_size; i++)
    {
        // 6 for the \0
        char thisval[6];
        sprintf(thisval, "%d", ar[i]);

        // Since this is the first pass
        if(i == 0)
        {
            // the string is initialized first
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
    printf("%s", loopResult);
}

/* 
This function performs an insertion sort on the input array, 
ar. It is expectatd that the input array is unsorted.

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
void insertionSort(int arSize, int *  ar)
{
    // key will be used to hold the current value
    // of the insertion sort's outer loop (the 
    // current value to be sorted).
    int key;

    #ifdef DEBUG
    printAr(arSize, ar);
    printf("*************************************************************\n");
    printf("\n");
    #endif

    // Iterate, counting up from the first index in the array
    for(int j=0; j<arSize; j++)
    {
        // i is the current point in the outer loop.
        int i = j - 1;

        bool doPrintAr = false;

        // copy the current value to key for comparison
        key = ar[j];
        #ifdef DEBUG
        printf("%d________________\n", j);
        printf("key to sort: %d\n", key);
        #endif

        // Iterate backwards from i as long as next (counting backwards)
        // value is greater than the current value of key.
        
        while(i>=0 && compare(ar[i], key) > 0)
        {
            #ifdef DEBUG
            printf("-%d-----\n", i);
            printf("innerKey: %d\n", i);
            #endif
            // Shift values one item to the right with each pass.
            //int poo;
            //poo = ar[i + 1];
            //printf("%d\n", poo);
            ar[i + 1] = ar[i];
            ar[i] = key;
            // Print the new array
            //printAr(arSize, ar);
            i--;
        }

        ar[i + 1] = key;

        #ifdef DEBUG
        printf("%d___\n", ar[i + 1]);
        #endif

        if(j != 0)
        {
            printAr(arSize, ar);
        }

        #ifdef DEBUG
        printf("\n");
        #endif
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


