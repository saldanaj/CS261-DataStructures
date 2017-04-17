/*
 Author: Joaquin Saldana 
 Date: 10/16/2016
 Description: this is the implementation file for a double linked 
 circular list.  The list carries values of type int, this file implements 
 the function to add, remove, delete, and destroy the list.
 */



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
    
    // assert the list is not poinint to NULL
    assert(list != 0);
    
    // initialize the objects variables
    list->size = 0;
    list->sentinel = (struct Link*)malloc(sizeof(struct Link));
    
    assert(list->sentinel != 0);
    
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
    
    // create a new link
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    // assert the pointer is not pointing to NULL
    assert(newLink != 0);
    // assign the value
    newLink->value = value;
    
    return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    
    // check the pointers are not pointing to NULL
    assert(list != 0);
    assert(link != 0);
    assert(link->next != 0);
    assert(link->prev != 0);
    
    // create the new link
    struct Link* newLink = createLink(value);
    
    // reassignment of pointers
    newLink->next = link->next;
    newLink->prev = link;
    
    link->next->prev = newLink;
    link->next = newLink;
    
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
    
    // check the pointers are not pointing to NULL
    assert(list != 0);
    assert(link != 0);
    assert(link->next != 0);
    assert(link->prev != 0);
    assert(!circularListIsEmpty(list));
    
    // reassignment of pointers
    link->prev->next = link->next;
    link->next->prev = link->prev;
    
    // free the link from the heap
    free(link);
    
    // decrement the list size
    list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
    
    // assertion statement
    assert(list != 0);
    // create a temporary link to be able to traverse the list
    struct Link* temporaryLink = list->sentinel;
    
    // keep removing from the front of the list until we've
    // traversed the entire list
    while(!circularListIsEmpty(list))
    {
        temporaryLink = temporaryLink->next;
        circularListRemoveFront(list);
    }
    
    // free the dynamic memory
    free(list->sentinel);
    
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    
    // assert the list is not pointing to NULL
    assert(list != 0);
    
    // add to the front of the list
    addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
    
    // check the list is not pointing to null
    assert(list != 0);
    // add it after the last link
    addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
    
    // check that the list is not pointing to null
    assert(list != 0);
    assert(!circularListIsEmpty(list));
    
    return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this

    // check that the list is not pointing to null
    assert(list != 0);
    assert(!circularListIsEmpty(list));
    
    return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
    
    // check that the list is not pointing to null
    assert(list != 0);
    assert(!circularListIsEmpty(list));
    
    removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
    
    // check that the list is not pointing to null
    assert(list != 0);
    assert(!circularListIsEmpty(list));

    removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
    
    assert(list != 0);

    if(list->size > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
    
    // routine checks/assertions to ensure it's not pointing to null
    assert(list != 0);
    assert(!circularListIsEmpty(list));
    
    struct Link *printLink = list->sentinel->next;
    
    while(printLink != list->sentinel)
    {
        printf("%f\n", printLink->value);
        printLink = printLink->next;
    }
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
    
    // routine assertions
    assert(list != 0);
    assert(!circularListIsEmpty(list));
    
    struct Link* iteratorLink = list->sentinel->next;
    list->sentinel->prev = iteratorLink;
    
    // will point to the next node
    struct Link* temporaryLink;
    
    while(iteratorLink != list->sentinel)
    {
        temporaryLink = iteratorLink->next;
        
        // we have reached the final node and reassuring that
        // sentinel will point to the starting node

        if(temporaryLink == list->sentinel)
        {
            list->sentinel->next = iteratorLink;
        }
        
        // reassignment of pointers using the iterator and temporary link
        // pointing to the next node/link
        iteratorLink->next = iteratorLink->prev;
        iteratorLink->prev = temporaryLink;
            
        // move the next node/link
        iteratorLink = temporaryLink;
    }
}









