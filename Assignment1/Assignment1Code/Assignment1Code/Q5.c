/* CS261- Assignment 1 - Q.5*/
/* Name: Joaquin Saldana
 * Date: 09/30/2016
 * Solution description: this program creates sticky letters.  The program will 
 * ask the user to enter a word/string and will then convert it to a sticky letter.
 * It will detect the letter case by it's ASCII code.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch)
{
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch)
{
     return ch-'A'+'a';
}

/* Function: void sticky(...)
 * Parameters: Pointer to char 
 * Description: this function will convert a string of characters to 
 * randomly from upper to lower case.  It does so by reading the char's 
 * case by it's ASCII code.  
 * Preconditions: pointer must not point to NULL 
 * Postcondition: N/A
 */

void sticky(char* word)
{
    /*Convert to sticky caps*/
    char temp;
    int randomNumber;
    
    // while loop that traverses the string array
    while(*word != '\0')
    {
        // generates a random number between 1 and 2
        randomNumber = rand() % 2 + 1;
        
        // variable holds the current char at the address from word
        temp = *word;
        
        // if statements checks if the random number generated is 1
        // if so, then the character is changed from either upper to lower
        // or vice versa
        if(randomNumber == 1)
        {
            // if statement checking if the char is an upper case letter
            // in which case we will need to conver to lower case
            if(temp > 64 && temp < 91)
            {
                temp = toLowerCase(temp);
            }
            else
            {
                temp = toUpperCase(temp);
            }
            
            // assign the new
            *word = temp;
        }
        // increment loop counter
        word++;
    }
}

int main()
{
    /*Read word from the keyboard using scanf*/
    // declarating an array of char that can hold 79 chars and the nul terminator
    char string1[16];
    printf("Please enter a string of no more than 15 characters: ");
    scanf("%s", string1);
    
    /*Call sticky*/
    sticky(string1);
    
    /*Print the new word*/
    printf("This is the new \"sticky\" string: %s\n", string1);
    
    return 0;
}















