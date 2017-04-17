/* CS261- Assignment 1 - Q.1*/
/* Name: Joaquin Saldana
 * Date: 09/30/2016
 * Solution description: this program has three functions that populate random data for students which 
 * have been instantiated as structures with two integer data types meant to hold their id number and score.  
 * The functions will also print the data of the structures to console.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student
{
	int id;
	int score;
};

/* Function: allocate() 
 * Parameters: N/A 
 * Description: This function will allocate dynamically 10 struct student objects in memory.  
 * It then returns a pointer to the beginning address of the chunk of memory allocated.
 * Pre-Conditions: The structure student must be defined in the program.
 * Post-Conditions: N/A
 */
struct student* allocate()
{
    /*Allocate memory for ten students*/
    struct student *tenStudents = malloc(10 * sizeof(struct student));
     
    /*return the pointer*/
    return tenStudents;
}

/* Function: generate()
 * Parameters: Pointer to a structure of type student
 * Description: generates random numbers and assigns them to the student structures 
 * id and score.  The ID number will range from 1 to 10, and the Score number will range 
 * from 0 to 100.  
 * Pre-Conditions: 10 student structures 
 * Post-Conditions: N/A
 */
void generate(struct student* students)
{
    /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    // for loop that traverses each of the 10 student structures
    for(int i = 0; i < 10; i++)
    {
        // checks if this is the first student structure, if so then there's no need to check if the student
        // id is a duplicate since it's the first on the list.  If not, the first on list then it begins
        // to check if the student id is a duplicate.
        if(i == 0)
        {
            // assigns a number to the student id and score
            students[i].id = rand() % 10 +1;
            students[i].score = rand() % 101;
        }
        else
        {
            // declaration of variable x that holds a number between 1 and 10
            int x = rand() % 10 + 1;
            
            // variable declaration to traverse the list
            int a = 0;
            
            // while loop that terminates once it's equal to or greater than i
            while(a < i)
            {
                // boolean condition to check if the random number generated is already
                // assigned to another student's id
                if(students[a].id == x)
                {
                    // it's equal to an existing number so we will now assign x a new number
                    // and reset the counter
                    x = rand() % 10 + 1;
                    a = 0;
                }
                else
                {
                    // the loop condition is incremented
                    a++;
                }
            }
            // random number is assigned to the student id and score
            students[i].id = x;
            students[i].score = rand() % 101;
        }
    }
}

/* Function: output()
 * Parameters: pointer to a student structure
 * Description: prints the the student structures id and scores of all the 
 * students.  The list does not have to be sorted.
 * Pre-Conditions: All of the student scores must have an ID and Score number
 * Post-Conditions: N/A
 */
void output(struct student* students)
{
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    printf("These are the student ID's and scores ... \n");
    
    // for loop that traverses the student structures and prints the ID's and scores
    for(int i = 0; i < 10; i++)
    {
        printf("ID = %d, Score = %d\n", students[i].id, students[i].score);
    }
}

/* Function: summary()
 * Parameters: pointer to student struct
 * Description: the function prints the minimum score, maximum score and the average score of the 10 students
 * Pre-Conditions: there must be 10 student structures with assigned ID's and scores
 * Post-Conditions: N/A
 */
void summary(struct student* students)
{
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    
    /*
     following code finds the minimum and maximum score
     */
    
    // variable declaration
    int minimumScore;
    int maximumScore;
    int a = 0;
    
    // first score of the first student is listed as the minimum score
    minimumScore = students[0].score;
    maximumScore = students[0].score;
    
    // while loop that reassigns the minimum score if while traversing through the list it finds
    // a smaller number
    while(a < 10)
    {
        // boolean condition that tests to see if the current score is still the lowest
        if(students[a].score < minimumScore)
        {
            // boolean condition was met and a new minimum score was found
            minimumScore = students[a].score;
            
            // if a new minimum score is found the counter is reset
            a = 0;
        }
        else if(students[a].score > maximumScore)
        {
            // condition was met and we have a new maximum score
            maximumScore = students[a].score;
            
            // counter is reset
            a = 0;
        }
        else
        {
            // loop counter is incremented
            a++;
        }
    }

    /*
     Following section of code finds the average
     */
    
    int average = 0;
    
    // for loop to sum all of the scores
    for(int i = 0; i < 10; i++)
    {
        average = average + students[i].score;
    }
    
    // divide the total score by 10 to obtain the average
    average = (average / 10);
    
    printf("Minimum score = %d, Maximum score = %d, and the Average = %d \n", minimumScore, maximumScore, average);
}

/* Function: deallocate()
 * Parameters: pointer to student struct
 * Description: the function deallocates the dynamic memory created in the allocate() function
 * Pre-Conditions: the struct must not point to NULL
 * Post-Conditions: N/A
 */
void deallocate(struct student* stud)
{
     /*Deallocate memory from stud*/
    if(stud != NULL)
    {
        free(stud);
    }
}

int main()
{
    /*instantiation of the student structure pointer*/
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
