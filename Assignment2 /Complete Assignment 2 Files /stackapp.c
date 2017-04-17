/* Author: Joaquin Saldana
 * Date: 10/08/2016
 * Description: this .c file implements a stack to 
 * test if a string is "balanced" by utilizing the reverse 
 * polish notation or "postfix" notation.  The isBalanced 
 * function will return true if the string is balanced, or 
 * false if it is not.
 */


/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
    
    // char c will temporarily hold the char values as we
    // iterate through the char entered
    char c = 'a';
    
    // create a pointer to a dynamic array
    DynArr *dyn;
    
    // create a new dynamic array that will in which we will
    // utilize the stack interface
    dyn = newDynArr(2);
    
    // while loop will continue until the c char
    // reaches the nul terminator
    while(c != '\0')
    {
        // char c get's the next char in the string
        c = nextChar(s);
        
        // if the char is an open bracket, brace, or paren
        // then we simply push it to the dynamic stack
        if(c == '{' || c == '[' || c == '(')
        {
            pushDynArr(dyn, c);
        }
        
        // if the char is a closing paren, brace or bracket
        // then we go through a system of checks
        // that if true will return a 1 signaling the string is
        // unbalanced
        if(c == '}' || c == ']' || c == ')')
        {
            if(isEmptyDynArr(dyn))
            {
                return 0;
            }
            
            char temp = topDynArr(dyn);
            
            popDynArr(dyn);
            
            if(c == ')' &&  temp != '(')
            {
                return 0;
            }
            if(c == ']' && temp != '[' )
            {
                return 0;
            }
            if(c == '}' && temp != '{')
            {
                return 0;
            }
        }
    }
    
    // if the stack is empty then we free the dynamic memory
    // and return to reflect the string is balanced
    if(isEmptyDynArr(dyn))
    {
        deleteDynArr(dyn);
        
        return 1; 
    }
    else
    {
        // means the string is not balanced and we will
        // return false, but first we must free the
        // dynamic memory
        
        deleteDynArr(dyn);
        
        return 0;
    }
}

int main(int argc, char* argv[])
{
	
	char* s = argv[1];
	
    int res;
	
	printf("Assignment 2\n");
    
	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
    
	return 0;	
}

