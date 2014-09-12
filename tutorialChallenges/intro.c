/******************************************************************************
 *
 *       Filename:  tutorialIntro.c
 *
 *    Description:  simple program to demo iteration
 *
 *
 *         Author:  Adrian Arias (a-a), 
 *   Organization:  Elusys
 *
 ******************************************************************************

Input:
------

This program takes two arguments from stdin:

    V, n and ar

The first line is V. V represents the value to search for.

The second line of input is n. N represents the size of ar. 

The third parameter is ar. ar is an array of length n.

Problem:
--------

Output the index of V in the array.

If, V = 4 and the length of ar = 6, then:

Sample Input
4
6
1 4 5 7 9 12

Sample Output
1
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int getIndexOf(int val, int arSize, int *ar)
{
    int index = 0;
    for(int i = 0; i<arSize; i++)
    {
        if(ar[i] == val)
            return i;
    }
    return -1;
}

int main(void)
{
    // Get the first line of input which represents 
    // the value to search for.
    int V;
    scanf("%d", &V);

    // Get the second line of input which represents
    // the size of sample array
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

    // get the index
    int index = getIndexOf(V, _ar_size, _ar);
    printf("%d\n", index);

    return 0;
}


