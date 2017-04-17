/* CS261- Assignment 1 - Q.2*/
/* Name: Joaquin Saldana
 * Date: 09/30/2016
 * Solution description: the objective of this program is to show how a variable, when passed by reference 
 * can be modified within a function since it's not a copy.
 */
 
#include <stdio.h>
#include <stdlib.h>

/* Function: foo(...)
 * Parameters: Pointer to integer values a & b, and copy of int variable 
 * Pre-conditions: All three integer variables must have a value
 * Post-conditions: N/A
 */
int foo(int* a, int* b, int c)
{
    /*Set a to double its original value*/
    *a = *a * 2;
    
    /*Set b to half its original value*/
    *b = *b / 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main()
{
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    
    /*Print the values of x, y and z*/
    printf("The current values are\nx = %d, y = %d, z = %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int temp = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("Value returned by foo function = %d \n", temp);
    
    /*Print the values of x, y and z again*/
    printf("Values for x, y, and z are ...\nx = %d, y = %d, z = %d\n", x, y, z);
    
    /*Is the return value different than the value of z?  Why?*/
    /*
     Z's value was unchanged because only a copy of the value c was pointed too was 
     pass to the foo function.  Had the c variable been passed by reference to the 
     foo function, the function would have been allowed to modify the number c was 
     pointing to.
     */
    
    return 0;
}
    
    
