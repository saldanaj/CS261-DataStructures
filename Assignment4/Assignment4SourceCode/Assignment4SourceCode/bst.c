/*
 Author: Joaquin Saldana
 Date: 10/27/2016
 Description: in this .C file we are responsible for putting together the following functions 
 - addNode 
 - containsBSTree 
 - leftMost 
 - removeLeftMost 
 - removeNode
 */



/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"


struct Node
{
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree
{
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initBSTree(struct BSTree *tree)
{
	tree->cnt  = 0;
	tree->root = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0)
    {
		_freeBST(node->left); /// recursively free's each left and right node
		_freeBST(node->right);
        
		free(node);
	}
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
		tree->root = 0;
		tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, TYPE val)                               // THIS IS ONE OF THE FUNCTIONS I MODIFIED
{
    // create Node pointer that will be later used to place the new node
    struct Node * newNode;
    
    // base case which is we arrived to the bottom depth of the tree
    if(cur == 0)
    {
        // dynamically allocate the new node in the heap
        newNode = malloc(sizeof(struct Node));
        assert(newNode != 0);
        
        // assign the value from the function parameter/argument to the new node's
        // value variable and then ensure the left and right node pointers are set to NULL
        newNode->val = val;
        newNode->left = 0;
        newNode->right = 0;
        
        // return the new Node and the recursive return
        return newNode;
    }
    else if(compare(val, cur->val) == -1)
    {
        // if the value were trying to add to the tree is less than the
        // current value then we need to move to the left of the current node
        cur->left = _addNode(cur->left, val);
    }
    else
    {
        // else the value we're currently trying to add is greater than the value
        // of the current node so we will move to the right of the current
        // node
        cur->right = _addNode(cur->right, val);
    }
    
    // our final return statement
    return cur;
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
		val is not null
 pose:  tree size increased by 1
		tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, TYPE val)
{
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, TYPE val)                                   // THIS IS ONE OF THE FUNCTIONS I MODIFIED
{

    assert(tree != 0);
    
    if(sizeBSTree(tree) == 0)
    {
        return 0;
    }
    
    struct Node * temporary = tree->root;
    
    while(temporary != 0)
    {
        if(compare(val, temporary->val) == 0)
        {
            // return 1 for true to reflect the tree has a node that contains
            // the value we are looking for
            return 1;
        }
        else if(compare(val, temporary->val) == -1)
        {
            // if the value is < the current value in the node
            // then we need to move to the "left" of the current node
            temporary = temporary->left;
        }
        else
        {
            // else we are moving to the right of the current node
            // because that means that the value is > the current value
            // in the node
            temporary = temporary->right;
        }
    }
    
    return 0; // returning 0 to reflect false, the binary tree does not have the value
                // in any of it's nodes
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)                                                    // THIS IS ONE OF THE FUNCTIONS I MODIFIED
{
    // were going to keep traversing the list until we arrive to the left most
    // child and we know we're there because the pointer will be pointing
    // to the next left child and if it's NULL the loop will terminate
    while(cur->left != 0)
    {
        cur = cur->left;
    }
    
    return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)                                      // THIS IS ONE OF THE FUNCTIONS I MODIFIED
{
    struct Node * leftMostNode;
    
    // base case
    
    if(cur->left == 0)
    {
        leftMostNode = cur->right;
        free(cur);
        return leftMostNode;
    }
    else
        // recursive call to keep returning splitting the left most node
        cur->left = _removeLeftMost(cur->left);
    
    return cur;
}
/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, TYPE val)                                // THIS IS ONE OF THE FUNCTIONS I MODIFIED
{
    // create temporary node pointer to hold the address of the node
    // in the binary tree we want to delete (free) from the tree and
    // dynamic memory
    struct Node *temporary;
    
    // we found the value to remove
    if(compare(val, cur->val) == 0)
    {
        if(cur->left == 0 && cur->right == 0)
        {
            return NULL;
        }
        else if(cur->left == 0)
        {
            temporary = cur->right;
            free(cur);
            return temporary;
        }
        else if (cur->right == 0)
        {
            temporary = cur->left;
            free(cur);
            return temporary;
        }
        else
        {
            cur->val = _leftMost(cur->right);
            
            cur->right = _removeLeftMost(cur->right);
        }

    }
    else if (compare(val, cur->val) == -1)
    {
        cur->left = _removeNode(cur->left, val);
    }
    else
    {
        cur->right = _removeNode(cur->right, val);
    }

    return cur;
}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, TYPE val)
{
	if (containsBSTree(tree, val))
    {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

/*----------------------------------------------------------------------------*/


#if 1
#include <stdio.h>

/*----------------------------------------------------------------------------*/
void printNode(struct Node *cur)
{
	 if (cur == 0) return;
	 printf("(");
	 printNode(cur->left);	 
	 /*Call print_type which prints the value of the TYPE*/
	 print_type(cur->val);
	 printNode(cur->right);
	 printf(")");
}

void printTree(struct BSTree *tree)
{
	 if (tree == 0) return;	 
	 printNode(tree->root);	 
}
/*----------------------------------------------------------------------------*/

#endif


#if 1
/*
function to built a Binary Search Tree (BST) by adding numbers in this specific order
the graph is empty to start: 50, 13, 110 , 10

*/
struct BSTree *buildBSTTree()
{
    /*     50
         13  110
        10 
    */
    struct BSTree *tree	= newBSTree();		
		
	/*Create value of the type of data that you want to store*/
	struct data *myData1 = (struct data *) malloc(sizeof(struct data));
	struct data *myData2 = (struct data *) malloc(sizeof(struct data));
	struct data *myData3 = (struct data *) malloc(sizeof(struct data));
	struct data *myData4 = (struct data *) malloc(sizeof(struct data));
		
	myData1->number = 50;
	myData1->name = "rooty";
	myData2->number = 13;
	myData2->name = "lefty";
	myData3->number = 110;
	myData3->name = "righty";
	myData4->number = 10;
	myData4->name = "lefty of lefty";
	
	/*add the values to BST*/
	addBSTree(tree, myData1);
	addBSTree(tree, myData2);
	addBSTree(tree, myData3);
	addBSTree(tree, myData4);
    
    return tree;
}

/*
function to print the result of a test function
param: predicate:  the result of the test 
       nameTestFunction : the name of the function that has been tested
	   message

*/
void printTestResult(int predicate, char *nameTestFunction, char *message)
{
	if (predicate)
	   printf("%s(): PASS %s\n",nameTestFunction, message);
    else
	   printf("%s(): FAIL %s\n",nameTestFunction, message);        
}

/*
fucntion to test each node of the BST and their children

*/
void testAddNode()
{
    struct BSTree *tree	= newBSTree();
    
    struct data myData1,  myData2,  myData3,  myData4;
		
	myData1.number = 50;
	myData1.name = "rooty";
    addBSTree(tree, &myData1);
    //check the root node
    if (compare(tree->root->val, (TYPE *) &myData1) != 0) {
        printf("addNode() test: FAIL to insert 50 as root\n");
        return;
    }
	//check the tree->cnt value after adding a node to the tree
    else if (tree->cnt != 1) {
        printf("addNode() test: FAIL to increase count when inserting 50 as root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 50 as root\n");
    
    
	myData2.number = 13;
	myData2.name = "lefty";
    addBSTree(tree, &myData2);
    
    //check the position of the second element that is added to the BST tree
    if (compare(tree->root->left->val, (TYPE *) &myData2) != 0) {
        printf("addNode() test: FAIL to insert 13 as left child of root\n");
        return;
    }
    else if (tree->cnt != 2) {
        printf("addNode() test: FAIL to increase count when inserting 13 as left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 13 as left of root\n");
    
    
	myData3.number = 110;
	myData3.name = "righty";
    addBSTree(tree, &myData3);
        
    //check the position of the third element that is added to the BST tree    
    if (compare(tree->root->right->val, (TYPE *) &myData3) != 0)
    {
        printf("addNode() test: FAIL to insert 110 as right child of root\n");
        return;
    }
    else if (tree->cnt != 3) {
        printf("addNode() test: FAIL to increase count when inserting 110 as right of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 110 as right of root\n");
    
    
	myData4.number = 10;
	myData4.name = "righty of lefty";
	addBSTree(tree, &myData4);
    
	//check the position of the fourth element that is added to the BST tree
    if (compare(tree->root->left->left->val, (TYPE *) &myData4) != 0) {
        printf("addNode() test: FAIL to insert 10 as left child of left of root\n");
        return;
    }
    else if (tree->cnt != 4) {
        printf("addNode() test: FAIL to increase count when inserting 10 as left of left of root\n");
        return;
    }
    else printf("addNode() test: PASS when adding 10 as left of left of root\n");
}

/*
fucntion to test that the BST contains the elements that we added to it

*/
void testContainsBSTree()
{
    struct BSTree *tree = buildBSTTree();
    
    struct data myData1,  myData2,  myData3,  myData4, myData5;
	
	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    myData5.number = 111;
	myData5.name = "not in tree";
    
    printTestResult(containsBSTree(tree, &myData1), "containsBSTree", "when test containing 50 as root");
        
    printTestResult(containsBSTree(tree, &myData2), "containsBSTree", "when test containing 13 as left of root");
    
	printTestResult(containsBSTree(tree, &myData3), "containsBSTree", "when test containing 110 as right of root");
        
    printTestResult(containsBSTree(tree, &myData4), "containsBSTree", "when test containing 10 as left of left of root");

     //check containsBSTree fucntion when the tree does not contain a node    
    printTestResult(!containsBSTree(tree, &myData5), "containsBSTree", "when test containing 111, which is not in the tree");
    
}

/*
fucntion to test the left_Most_element 

*/
void testLeftMost()
{
    struct BSTree *tree = buildBSTTree();
    
	struct data myData3, myData4;

	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    
	printTestResult(compare(_leftMost(tree->root), &myData4) == 0, "_leftMost", "left most of root");
    
	printTestResult(compare(_leftMost(tree->root->left), &myData4) == 0, "_leftMost", "left most of left of root");
    
	printTestResult(compare(_leftMost(tree->root->left->left), &myData4) == 0, "_leftMost", "left most of left of left of root");
    
	printTestResult(compare(_leftMost(tree->root->right), &myData3) == 0, "_leftMost", "left most of right of root");

}

void testRemoveLeftMost()
{
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
    
    cur = _removeLeftMost(tree->root);

	printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 1st try");
    
    cur = _removeLeftMost(tree->root->right);
    printTestResult(cur == NULL, "_removeLeftMost", "removing leftmost of right of root 1st try");
   
 	cur = _removeLeftMost(tree->root);
    printTestResult(cur == tree->root, "_removeLeftMost", "removing leftmost of root 2st try");
}

void testRemoveNode()
{
    struct BSTree *tree = buildBSTTree();
    struct Node *cur;
     struct data myData1,  myData2,  myData3,  myData4;
		
	myData1.number = 50;
	myData1.name = "rooty";
	myData2.number = 13;
	myData2.name = "lefty";
	myData3.number = 110;
	myData3.name = "righty";
	myData4.number = 10;
	myData4.name = "lefty of lefty";
    
    _removeNode(tree->root, &myData4);
    printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left->left == NULL, "_removeNode", "remove left of left of root 1st try");
	        
    _removeNode(tree->root, &myData3);
	 printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->right == NULL, "_removeNode", "remove right of root 2st try");
	   
    _removeNode(tree->root, &myData2);
	printTestResult(compare(tree->root->val, &myData1) == 0 && tree->root->left == 0, "_removeNode", "remove right of root 3st try");
        
    cur = _removeNode(tree->root, &myData1);
    printTestResult(cur == NULL, "_removeNode", "remove right of root 4st try");       
}

/*

Main function for testing different fucntions of the Assignment#4.

*/

int main(int argc, char *argv[]){	

   //After implementing your code, please uncommnet the following calls to the test functions and test your code 

    // struct BSTree * tree1 = buildBSTTree();
    
    // deleteBSTree(tree1);
   
    
    testAddNode();
	
    printf("\n");
    testContainsBSTree();
	
	printf("\n");
    testLeftMost();
	
	printf("\n");
    testRemoveLeftMost();
	
	printf("\n");
    testRemoveNode();
    
	return 0;


}

#endif
