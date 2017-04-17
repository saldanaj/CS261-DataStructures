/* Author: Joaquin Saldana 
 * Date: 10/08/2016 
 * Description: this is the implementation file (.c file) in which we 
 * implement the initialization, and functions for a dynamic array.  This dynamic array 
 * will hold elements of type int.  These functions include the following: 
 * 1. initialize the array 
 * 2. return a new dynamic array 
 * 3. destroy the dynamically created array 
 * 4. increase the size of the array 
 * 5. return an item within the array 
 * 6. add to the dynamic array 
 * 7. remove an item from the array 
 * 
 * Please remove the function headers for more information.
 */


/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include "dynArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
    // check the integer capacity is greater than 0
	assert(capacity > 0);
    
    // check the pointer variable v is not point to NULL
	assert(v!= 0);
    
    // initialize the sentinel *data in the struct DynArr is now pointing
    // to a block of memory that can hold the number of elements passed as
    // the int capacity parameter
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	
    // check that the *data pointer is not pointing to NULL
    assert(v->data != 0);
	
    // the array has no elements so the size is 0
    v->size = 0;
    
    // the capacity of the array is the integer capacity passed as the variable
	v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* newDynArr(int cap)
{
    // check that the integer cap variable is greater than 0
	assert(cap > 0);
    
    // initialize the *r pointer of type struct DynArr
    // in a block of memory (just 1 address is assigned)
    // not the entire block of memory
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	
    // check that the new dynamic array is not pointing to NULL
    assert(r != 0);
	
    // pass the new DynArr pointer to initialize the dynamic array
    // to the size passed as the capacity.  The pointer will then
    // point to a block of memory of the capacity requested by the
    // the user
    initDynArr(r,cap);
    
    // at this point the *r pointer will now be pointing to a block of
    // memory that will be of the size requested by the user so the
    // pointer is returned to the user
	return r;
}

/* Deallocate data array in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
    // check that the pointer *data is not pointing to
    // NULL, because if it is then we dont have to
    // free anything
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
    
    // reassign the size and capacity of the array
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
    // the function calls the freeDynArr function
    // and frees the dynamically located pointer
    // initialized in the newDynArr function
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{	
	/* FIXME: You will write this function */
    
    // check that *v pointer is not pointing to NULL
    assert(v != 0);
    
    // create a sentinel variable/pointer that will point
    // to the new chunk of memory which is the dynamic
    // array that is the new size passed as the parameter
    TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
    assert(newData != 0);
    
    // copy the elements from the old array to thew
    // new array
    for(int i = 0; i < v->size; i++)
    {
        newData[i] = v->data[i];
    }
    
    // deallocate the chunk of memory the *data pointer is currently
    // pointing to and it's the old array
    free(v->data);

    // reassign the *data pointer to the new array
    v->data = newData;
    
    // reassign the capacity variable to the new capazity of the
    // dynamic array
    v->capacity = newCap;
	
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
    
    // check the *v pointer is not pointing to NULL
    assert(v != 0);
    
    // check if the array is full, and if it is, then double
    // it's size
    if(v->size >= v->capacity)
    {
        _dynArrSetCapacity(v, v->capacity * 2);
    }
    
    // add the val variable to the array at the
    // end of the array
    v->data[v->size] = val;
    
    // increase the variable which reflects the
    // total number of elements in the array
    v->size++;
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	/* FIXME: You will write this function */
    
    // check that v is not pointing to NULL, it has atleast one element
    // and the position integer is greater than 0 and less than the actual
    // size of the dynamic array
    assert(v != 0);
    assert(v->size > 0);
    assert(pos < v->size);
    assert(pos >= 0);

	/* FIXME: you must change this return value */
    
    // once all the assertions are complete, then return the value
    // at the position/index given
	return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	/* FIXME: You will write this function */
    
    // do routine checks which are ensuring the pointer is
    // not pointing to NULL, and the values passed are greater
    // than 0 and less than the array size
    assert(v != 0);
    assert(v->size > 0);
    assert(pos < v->size);
    assert(pos >= 0);
    
    // replace the value at the index passed as a parameter
    v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	/* FIXME: You will write this function */
    
    // temporary variable to hold the value that will be swapped
    // before it's destroyed and replaced
    TYPE  temporary;
    
    // assertions to check that list is not empty, the pointer is not
    // pointing to NULL, and is greater than 0 and less than the size of
    // the list
    assert(v!= 0);
    assert(v->size > 0);
    assert(i < v->size);
    assert(j < v->size);
    assert(i >= 0);
    assert(j >= 0);
    
    // perform the swap of the values
    temporary = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = temporary;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{
	/* FIXME: You will write this function */
    
    // assert the pointer is not pointing to NULL
    assert(v != 0);
    
    // assert v is not empty
    assert(v->size > 0);
    
    // assert the index parameter is above 0 or
    // equal to 0, and is less than the size of the
    // dynamic array
    assert(idx < v->size);
    assert(idx >= 0);
    
    // move all of the items from that index down to
    // shrink the array - 1 since were removing the item
    for(int i = idx; i < v->size-1; i++)
    {
        v->data[i] = v->data[i+1];
    }
    
    // decrement the size of the list which
    // tells how many items are in the list
    v->size--;
}



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
    
    // assert the array is not pointing to NULL
    assert(v != 0);

	/* FIXME:  You will change this return value*/
    
    // check if the list is empty if not, return 0, else
    // return 1
    if(v->size > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
    
    // check that v is not pointing to NULL
    assert(v!=0);
    
    // insert the value at the "top" of the array
    addDynArr(v, val);
}

/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
    
    // check it's not pointing to NULL
    assert(v != 0);
    
    // checking if the array is empty
    assert(!isEmptyDynArr(v));
	
	/* FIXME: You will change this return value*/
    
    // return the value on the "top" of the stack
    return v->data[v->size-1];
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
    
    // check it's not pointing to NULL
    assert(v != 0);
    
    // check the array is not empty
    assert(!isEmptyDynArr(v));
    
    // decrement the total number of elements
    // this is necessary when we create a new array we only copy
    // the elements in the array to n - 1, n being the item we want
    // to "pop" or "remove"
    v->size--;
    
    // copy the array to a new dynamic array and only up to the
    // element we want to pop, this element will not be added to the
    // new copy of the dynamic array
    _dynArrSetCapacity(v, v->capacity);
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
	
    // assertion it's not pointing to NULL
    assert(v != 0);
    // assertion the list is not empty
    assert(!isEmptyDynArr(v));
    
    // iterate through the array to determine
    // if the value is present, if it is, then
    // control goes into the if statement
    // which then returns 1 and the function terminates
    // never arriving to the return 0 statement that follows
    for(int i = 0; i < sizeDynArr(v); i++)
    {
        if(EQ(v->data[i], val))
        {
            return 1;
        }
    }
    
    /* FIXME:  You will change this return value */

    // the boolean condition was not meet and as such
    // the function returns 0
    return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
    
    // assertions taht the pointer is not pointing to NULL
    assert(v != 0);
    
    // assert the list is not empty
    assert(!isEmptyDynArr(v));
    
    // verify the value is in the container if not then an error is thrown
    assert(containsDynArr(v,val));  /* Design decision: Error if they try to remove something not in there! */
    
    // we now know the value is in the dynamic array
    // so we will traverse the array once more
    // to remove the first occurence of the value in the array
    for(int i = 0; i < sizeDynArr(v); i++)
    {
        if(EQ(v->data[i], val))
        {
            removeAtDynArr(v,i);
            break;
        }
    }
}
