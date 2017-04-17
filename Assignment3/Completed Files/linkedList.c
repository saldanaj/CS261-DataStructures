/*
 Author: Joaquin Saldana 
 Date: 10/16/2016
 
 Description: this is the implementation file to a linked list that has functions 
 which interface as both a deque AND a stack.  This is implementing a 
 double linked list, in which you will be able to add and remove from the front 
 and back of the list, as well as traverse the list.  
 */


#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list)
{
	// FIXME: you must write this
    
    // initiate the size variable and the front and back pointers
    list->size = 0;
    list->frontSentinel = (struct Link *) malloc(sizeof(struct Link));
    list->backSentinel = (struct Link *) malloc(sizeof(struct Link));
    
    // Check that the front and last pointers are not pointing to NULL
    assert(list->frontSentinel != 0);
    assert(list->backSentinel != 0);
    
    
    // preferred to connect the front and back sentinel rather than having
    // them point to NULL
    list->frontSentinel->next = list->backSentinel;
    list->backSentinel->prev = list->frontSentinel;
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
    
    // check the pointers dont point to NULL
    assert(list != 0);
    assert(link != 0);
    
    // create a new link and ensure it's not pointing to NULL
    struct Link* newLink = (struct Link *) malloc(sizeof(struct Link));
    assert(newLink != 0);
    
    
    // assign the new link its value and insert the link
    // in front of the link provided
    newLink->value = value;
    newLink->next = link;
    newLink->prev = link->prev;
    link->prev->next = newLink;
    link->prev = newLink;
    
    // increment the size variable
    list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
    
    assert(list != 0);
    assert(link != 0);
    assert(!linkedListIsEmpty(list));
    
    // remove the link from the list and reassign the pointers
    link->prev->next = link->next;
    link->next->prev = link->prev;
    
    // decrement the size of the list
    list->size--;
    
    
    // release the dynamic allocation of the memory
    free(link);
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
    
	init(newDeque);
    
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (linkedListIsEmpty(list) == 0) // changed it to (linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
    
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    
    // check the list is not pointing to NULL
    assert(list != 0);
    
    // adds a new link to the front of the link provided
    // add it with the value
    addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    
    // making sure the list is not pointing to NULL
    assert(list != 0);
    
    // add to the back of the list
    addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
    
    // checking to make sure the list is not empty
    assert(list != 0);
    assert(!linkedListIsEmpty(list));
    
    return list->frontSentinel->next->value;

}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
    
    // routine checks to make sure pointer is not pointing to NULL
    assert(list != 0);
    assert(list->size != 0);
    
    // returning the item in the back of the list
    return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
    
    assert(list != 0);
    assert(!linkedListIsEmpty(list));
    
    // remove the link at the front of the list
    removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
    
    assert(list != 0);
    assert(!linkedListIsEmpty(list));
    
    // removed the link at the back of the list
    removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
    
    assert(list != 0);
    
    // if the list size is less than 0
    // the list is empty and return 0
    if(list->size > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
    
    // check that its not pointing to NULL
    assert(list != 0);
    assert(!linkedListIsEmpty(list));

    
    // create a temporary link ot traverse through the list
    struct Link* temporaryLink = (struct Link *) malloc(sizeof(struct Link));
    temporaryLink = list->frontSentinel;
    
    // traverse through the list
    while(temporaryLink->next != list->backSentinel)
    {
        temporaryLink = temporaryLink->next;
        printf("%d\n", temporaryLink->value);
    }
    
    // destroy the dynamic memory link
    free(temporaryLink);
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    
    assert(list != 0);

    addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    
    assert(list != 0);
    assert(!linkedListIsEmpty(list));
  
    
    struct Link* temporaryLink = (struct Link *) malloc(sizeof(struct Link));
    
    temporaryLink = list->frontSentinel;
    
    while(temporaryLink->next != list->backSentinel)
    {
        temporaryLink = temporaryLink->next;
        
        if(temporaryLink->value == value)
        {
            free(temporaryLink);
            return 1;
        }
    }

    free(temporaryLink);
    
    return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
    
    assert(list != 0);
    assert(!linkedListIsEmpty(list));
    
    struct Link* temporaryLink = (struct Link *) malloc(sizeof(struct Link));

    temporaryLink = list->frontSentinel;
    
    while(temporaryLink->next != list->backSentinel)
    {
        temporaryLink = temporaryLink->next;
        
        if(temporaryLink->value == value)
        {
            removeLink(list, temporaryLink);
            free(temporaryLink);
        }
    }

    free(temporaryLink);
}







