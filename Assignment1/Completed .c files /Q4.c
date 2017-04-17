/* CS261- Assignment 1 - Q.4*/
/* Name: Joaquin Saldana
 * Date: 09/30/2016
 * Solution description: programs sorts the list of students according to their score from lowest to highest.  
 * The sort function uses the bubble sort algorithm.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student
{
	int id;
	int score;
};

/* Function: sort(...)
 * Parameters: pointer to student structure, and number of elements in the array
 * Description: sorts the list of students by score in ascending order using the bubble sort algorithm
 * Pre-Condition: array of students must be initialized 
 * Post-Condition: N/A
 */
void sort(struct student* students, int n)
{
    /*Sort the n students based on their score*/
    int tempID;
    int tempScore;
    
    /*Sort the given array number , of length n*/
    for(int a = 0; a < (n - 1); a++)
    {
        for(int b = 0; b < n - a - 1; b++)
        {
            // if the student score of b is higher than that of student b+1
            // then enter the condition statement and swap the id and scores of
            // of the students while using temp integer variables
            if(students[b].score > students[b+1].score)
            {
                tempID = students[b].id;
                tempScore = students[b].score;
                
                students[b].id = students[b+1].id;
                students[b].score = students[b+1].score;
                
                students[b+1].id = tempID;
                students[b+1].score = tempScore;
            }
        }
    }
}

int main()
{
    /*Declare an integer n and assign it a value.*/
    int n;
    printf("How many students do you wish to allocate? ");
    scanf("%d", &n);
    
    /*Allocate memory for n students using malloc.*/
    struct student *stud_ptr = malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    for(int i = 0; i < n; i++)
    {
        // checks if this is the first student structure, if so then there's no need to check if the student
        // id is a duplicate since it's the first on the list.  If not, the first on list then it begins
        // to check if the student id is a duplicate.
        if(i == 0)
        {
            // assigns a number to the student id and score
            stud_ptr[i].id = rand() % n + 1;
            stud_ptr[i].score = rand() % 101;
        }
        else
        {
            // declaration of variable x that holds a number between 1 and 10
            int x = rand() % n + 1;
            
            // variable declaration to traverse the list
            int a = 0;
            
            // while loop that terminates once it's equal to or greater than i
            while(a < i)
            {
                // boolean condition to check if the random number generated is already
                // assigned to another student's id
                if(stud_ptr[a].id == x)
                {
                    // it's equal to an existing number so we will now assign x a new number
                    // and reset the counter
                    x = rand() % n + 1;
                    a = 0;
                }
                else
                {
                    // the loop condition is incremented
                    a++;
                }
            }
            // random number is assigned to the student id and score
            stud_ptr[i].id = x;
            stud_ptr[i].score = rand() % 101;
        }
    }
    
    /*Print the contents of the array of n students.*/
    printf("These are the student ID's and scores ... \n");
    
    // for loop that traverses the student structures and prints the ID's and scores
    for(int i = 0; i < n; i++)
    {
        printf("ID = %d, Score = %d\n", stud_ptr[i].id, stud_ptr[i].score);
    }
    
    /*Pass this array along with n to the sort() function*/
    sort(stud_ptr, n);
    
    
    /*Print the contents of the array of n students.*/
    printf("Below is the list of students sorted by score ...\n");
    for(int i = 0; i < n; i++)
    {
        printf("ID = %d, Score = %d\n", stud_ptr[i].id, stud_ptr[i].score);
    }
    
    // de-allocation of dynamic memory
    free(stud_ptr);
    
    return 0;
}
