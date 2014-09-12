/******************************************************************************
 *
 *       Filename:  utopianTree.c
 *
 *    Description:  A program to print the growth of a utopian tree given a
 *                  very specific growth cycle.
 *
 *
 *         Author:  Adrian Arias (a-a), 
 *   Organization:  Elusys
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int calculateGrowth(int cycles)
{
    int newHeight = 1;
    
    if(cycles == 0)
    {
        return newHeight;
    }
    
    for(int i=0; i<cycles; i++)
    {
        if(i % 2 == 0)
        {
            newHeight = (newHeight * 2);
        } else {
            newHeight++;
        }
    }
    
    return newHeight;
}

int main()
{
    char line[100];
    int numOfTestCases;
    int growth[50];
    
    // get the number of test cases from the first line
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &numOfTestCases);
    
    // for each test case
    for(int i=0; i < numOfTestCases; i++)
    {
        int cycles;
        
        // get the number of cycles
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &cycles);
        
        // set the new height
        growth[i] = calculateGrowth(cycles);
    }
    
    // for each result
    for(int i = 0; i<=numOfTestCases -1; i++)
    {
        // print result from growth array
        printf("%d\n", growth[i]);
    }

    return 0;
}
