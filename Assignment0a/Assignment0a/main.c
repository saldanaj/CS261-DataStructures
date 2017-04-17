/*
 Name: Joaquin Saldana
 Course: CS261 / Data Structures
 Title: Assignment 0
 
 Description: this is the main function to assignment zero (0).  In this main.c file is a C program
 that will convert a value from inches to centimeters and vice versa.  This ia test program to
 ensure my local IDE and the flip server can compile my code along with the purpose of gaining
 practice.
 */

#include <stdio.h>

int main ()
{
    // variable declaration
    
    double inches;
    double centimeters;
    
    // print statement that describes the program to the user and what we will be requesting from them
    
    printf("This program will convert inches from centimeters and vice versa.\nThe user will need to enter a number in inches to convert to centimeters and then will be asked a number in centimeters to convert to inches.\n");
    
    // print statement to create a new line
    
    printf("\n");
    
    // print statement that requests the user enter the number of inches they wish to convert.  Immediately following the print statement is a input statement that reads the
    // user's input and stores it in the variable type double labeled inches
    
    printf("Please enter the number of inches you wish to convert to centimeters: ");
    scanf("%lf",&inches);
    
    // calculating the measurement. Each inch is 2.54 centimeters, so we multiply the number of inches times 2.54
    
    double totalCentimeters  = inches * 2.54;
    
    // printf statement prints the conversion total from inches to centimeters
    
    printf("%lf inches equals %lf centimeteters \n", inches, totalCentimeters);
    
    // print statement requesting the user enter the number of centimeters they wish to convert to inches.  Immediately following the print statement is a input statement that reads
    // the user's input and stores it in the variable type double labeled centimeters
    
    printf("Please enter the number of centimeters you wish to convert to inches: ");
    scanf("%lf", &centimeters);
    
    // math formula converting centimeters to inches.  1 cm = 0.39370079 inches
    
    double totalInches = centimeters * 0.39370079;
    
    // print statement prints the conversion total from centimeters from inches
    
    printf("%lf centimeters equates to %lf inches\n", centimeters, totalInches);
    
    printf("\n");
    
    // exit statement
    
    printf("Thank you for using this program.  Goodbye\n");
    
    return 0;
}
