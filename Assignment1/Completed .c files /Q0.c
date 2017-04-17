/* CS261- Assignment 1 - Q. 0*/
/* Name: Joaquin Saldana
 * Date: 09/30/2016
 * Solution description: this program declares the variable x, then pass the variables address to a pointer 
 * declared in the function fooA.  This function then confirms it's pointing to the variable x and it's contents
 * and it also prints the pointer's own address.
 */
 
#include <stdio.h>
#include <stdlib.h>


/* Function: fooA
 * Description: this function will print the value and address of the integer variable 
 * pass by reference.  Additionally it will print the address of the pointer itself.
 * Parameters: Pointer to an integer data type
 * Pre-Conditions: Variable must not point to NULL
 * Post-Conditions: N/A
 */
void fooA(int* iptr){
    
    /*Informs the user you are now in the fooA function*/
    printf("\nThe program has now entered the fooA function..\n");
    
    /*Print the value pointed to by iptr*/
    printf("Pointer iptr points to the value %d\n", *iptr);
    
    /*Print the address pointed to by iptr*/
    printf("Pointer iptr points to address %p\n", iptr);
    
    /*Print the address of iptr itself*/
    printf("Pointer iptr address is: %p\n", &iptr);
    
    /*Print statement that informs the user they have exited the fooA function*/
    printf("The fooA function has terminated\n");
}

int main(){
    
    /*declare an integer x*/
    int x;
    
    /*Prompts the user to enter a value for the integer variable x */
    printf("What value do you wish to assign to integer variable x: ");
    scanf("%d", &x);
    
    /*print the address of x*/
    printf("The memory address of x is: %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("\n");
    printf("Value of x = %d\n", x);
    
    return 0;
    
} // end of main function
