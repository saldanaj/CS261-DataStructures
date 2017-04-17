/* CS261- Assignment 1 - Q.3*/
/* Name: Joaquin Saldana
 * Date: 09/30/2016
 * Solution description: program creates a list of random number and sorts them using the 
 * sort function, which will sort them in ascending order
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


/* Function: sort(...)
 * Parameters: Pointer to integer data type, and size of array
 * Description: array is sorted using the bubble sort algorithm
 * Pre-Condition: array must not be empty 
 * Post-Condition: array will be sorted
 */
void sort(int* number, int n)
{
    // variable declaration to hold values when swapping
    int swap;
    
     /*Sort the given array number , of length n*/
    for(int a = 0; a < (n - 1); a++)
    {
        for(int b = 0; b < n - a - 1; b++)
        {
            if(number[b] > number[b+1])
            {
                swap = number[b];
                number[b] = number[b+1];
                number[b+1] = swap;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *ptr = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    for(int i = 0; i < n; i++)
    {
        ptr[i] = rand();
    }
    
    /*Print the contents of the array.*/
    printf("Current number in the array ... \n");
    
    for(int i = 0; i < n; i++)
    {
        printf("%d\n",ptr[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(ptr, n);
    
    /*Print the contents of the array.*/    
    printf("Below is the array now sorted ... \n");
    
    for(int j = 0; j < n; j++)
    {
        printf("%d\n", ptr[j]);
    }
    
    free(ptr);
    
    return 0;
}
