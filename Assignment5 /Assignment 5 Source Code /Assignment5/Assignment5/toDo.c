/*
 * CS 261 Assignment 5
 * Name: 
 * Date: 
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
    while (dySize(heap) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
    
    if(command != 'e')
    {
        char * file = malloc(sizeof(char)* 500); // file name can be 500 characters long
        char * taskName = malloc(sizeof(char)* 500);  // task name can be 500 characters long
        
        int priorityGiven;
        
        if(command == 'l')
        {
            // opening and closing files as explained in stackoverflow
            // http://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
            
            
            printf("Please enter the name of the file: ");
            
            fgets(file, 100, stdin);
            
            // new line character
            if (file[strlen(file) - 1] == '\n')
            {
                file[strlen(file) - 1] = 0;
            }
            
            FILE * fileread = fopen(file, "r");
            
            listLoad(list, fileread);
            
            printf("The list has been read from the file.\n");
            
            printf("\n");
            
            fclose(fileread);
        }
        if(command == 's')
        {
            printf("Please enter the file name to save to do list: ");
            
            fgets(file, 100, stdin);
            
            if (file[strlen(file) - 1] == '\n')
            {
                file[strlen(file) - 1] = 0;
            }
            
            FILE *fileWritten = fopen(file, "w+");
            
            listSave(list, fileWritten);
            
            printf("The list was saved to the file: '%s'.\n", file);
            
            printf("\n");
            
            fclose(fileWritten);
        }
        if(command == 'a')
        {
            printf("Please enter the task you wish to add: ");
            
            fgets(taskName, 100, stdin);
            
            if (taskName[strlen(taskName) - 1] == '\n')
            {
                taskName[strlen(taskName) - 1] = 0;
            }
            
            printf("Please enter the task priority (0-999): ");
            
            scanf("%d", &priorityGiven);
            
            while (getchar() != '\n');
            
            Task *task = taskNew(priorityGiven, taskName);
            
            dyHeapAdd(list, task, taskCompare);
            
            printf("The task '%s' has been added to the to do list.\n", taskName);
            printf("\n");
            
        }
        if(command == 'g')
        {
            if (dySize(list) != 0)
            {
                printf("Your first task on the to do list is: %s\n", ((struct Task *)dyHeapGetMin(list))->name);
            }
            else
            {
                printf("Your to do list is empty\n");
            }
            
            printf("\n");
        }
        if(command == 'r')
        {
            if (dySize(list) == 0)
            {
                printf("Your to do list is empty\n");
            }
            else
            {
                struct Task* temp = (struct Task*)dyHeapGetMin(list);
                
                printf("Your first task '%s' has been removed from the list.\n",temp->name);
                
                dyHeapRemoveMin(list, taskCompare);
                
                taskDelete(temp);
            }
            
            printf("\n");
        }
        if(command == 'p')
        {
            if (dySize(list) == 0)
            {
                printf("Your to do list is empty\n");
            }
            else
            {
                listPrint(list);
            }
            
            printf("\n");
        }
        
        // de-allocate the dynamic memory from the heap 
        free(taskName);
        free(file);
    }
    else
    {
        printf("You've choosen to exit the program.  Thank you\n");
    }
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
    dyDelete(list);
    return 0;
}
