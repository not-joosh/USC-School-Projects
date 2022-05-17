 /*======================================================================================================
FILE        : AVL.c
AUTHOR      : Josh B. Ratificar, Paolo Jansen A. Enrera, Mohan Nuelle T. Francis, & Rhett Joshua L. Surban.
DESCRIPTION : Holds the implementation of AVL Tree operations such as inserting, balancing, deletion of nodes,
              and printing of traversals.
COPYRIGHT   : 10 May 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
/*==============================================================================
Header Files
==============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AVL.h"
/*==============================================================================
FUNCTION    : newNode
DESCRIPTION : Creates a brand new node in a tree.
ARGUMENTS   : INT value - holds value of node to be inserted
RETURNS     : NODE - returns a new NODE
==============================================================================*/
NODE * newNode(int value) {
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}
/*==============================================================================
FUNCTION    : height
DESCRIPTION : Extracts a node's current height
ARGUMENTS   : NODE *root - root or current node passed into function
RETURNS     : INT - returns the height of a node
==============================================================================*/
int height(NODE* root) {
    if(root == NULL)
        return 0;
    else
        return root->height;
}
/*==============================================================================
FUNCTION    : max_Height
DESCRIPTION : Compares the left and right node's height and returns the largest
              node's height.
ARGUMENTS   : INT left, INT right - height of the left node and the height of the
              right node
RETURNS     : INT - returns the greatest height between the two nodes.
==============================================================================*/
int max_Height(int left, int right) {
    if(left>right)
        return left;
    else
        return right;
}
/*==============================================================================
FUNCTION    : computeBalanceF
DESCRIPTION : Computes the Balance Factor of a node
ARGUMENTS   : NODE *node - current node being read
RETURNS     : INT - returns the balance factor of the current node being read
==============================================================================*/
int computeBalanceF(NODE *node) {
    if (node == NULL)
       return 0;
    else
        return (height(node->left)-height(node->right));
}
/*==============================================================================
FUNCTION    : rightRotate
DESCRIPTION : Operates a single right rotation.
ARGUMENTS   : NODE *node - current node being read
RETURNS     : NODE - returns temp node
==============================================================================*/
NODE * rightRotate(NODE *node) {
	// Switch Children to new node
    NODE *temp = node->left;
    NODE *temp2 = temp->right;
    temp->right = node;
    node->left = temp2;
    // Update Height of the node
    node->height = max_Height(height(node->left), height(node->right))+1;
    temp->height = max_Height(height(temp->left), height(temp->right))+1;
    return temp;
}
/*==============================================================================
FUNCTION    : leftRotate
DESCRIPTION : Operates a single left rotation.
ARGUMENTS   : NODE *node - current node being read
RETURNS     : NODE - returns temp node
==============================================================================*/
NODE * leftRotate(NODE *node) {
	// Switch Children to new node
    NODE *temp = node->right;
    NODE *temp2 = temp->left;
    temp->left = node;
    node->right = temp2;
    // Update Height of the node
    node->height = max_Height(height(node->left),height(node->right))+1;
    temp->height = max_Height(height(temp->left), height(temp->right))+1;
    return temp;
}
/*==============================================================================
FUNCTION    : lrrotation
DESCRIPTION : Operates a double rotation, left to right rotation.
ARGUMENTS   : NODE *node - current node being read
RETURNS     : NODE - returns a right rotated node
==============================================================================*/
NODE * lrrotation(NODE *node) {
	// Double Rotation, left rotate, right rotate
	node->left = leftRotate(node->left);
	return rightRotate(node);
}
/*==============================================================================
FUNCTION    : rlrotation
DESCRIPTION : Operates a double rotation, right to left rotation.
ARGUMENTS   : NODE *node - current node being read
RETURNS     : NODE - returns a left rotated node
==============================================================================*/
NODE * rlrotation(NODE *node) {
	// Double Rotation, right rotate, left rotate
	node->right = rightRotate(node->right);
	return leftRotate(node);
}
/*==============================================================================
FUNCTION    : insertAVL
DESCRIPTION : Inserts a new node into the AVL tree WHILE maintaining the balance
              of an AVL tree while computing for BF and rotations.
ARGUMENTS   : NODE *node, INT value - current node being read and value to be inserted
              with node.
RETURNS     : NODE - returns node
==============================================================================*/
NODE * insertAVL(NODE *node, int value) {
    if(node == NULL) // If tree empty
        return newNode(value);
    else if(value<node->data) // Left Subtree
        node->left = insertAVL(node->left, value);
    else if(value > node->data) // Right  Subtree
        node->right = insertAVL(node->right, value);
    else // Reject duplicates
    	printf("\nNo duplicate numbers allowed.\n");
    node->height = max_Height(height(node->left),height(node->right))+1;
    int bf = computeBalanceF(node);
    if (bf > 1 && value < node->left->data) // case 1 left Heavy
        return rightRotate(node);
    else if (bf < -1 && value > node->right->data) // case 1 right Heavy
        return leftRotate(node);
    else if (bf > 1 && value > node->left->data) // case 2 right Heavy
        return lrrotation(node);
    else if (bf < -1 && value < node->right->data) // case 2 left Heavy
        return rlrotation(node);
    return node;
}
/*==============================================================================
FUNCTION    : max_Node
DESCRIPTION : Locates the largest node on the left subtree.
ARGUMENTS   : NODE *node - current node being read
RETURNS     : NODE - returns node
==============================================================================*/
NODE * max_Node(NODE *node) {
	NODE *temp = node;
	for(temp = node; temp->right != NULL; temp = temp->right); // Locate the Max Node on left Subtree
	return temp;
}
/*==============================================================================
FUNCTION    : deleteAVL
DESCRIPTION : Deletes a node while maintaining AVL tree balancing through rotations.
ARGUMENTS   : NODE *root, INT key, BOOL *success - current node being read, value to
              search for in tree, and BOOLEAN to store success or false.
RETURNS     : NODE - returns node
==============================================================================*/
NODE * deleteAVL(NODE *root, int key, bool *success) {
    //searching for the item to be deleted
    if(root==NULL) {
    	*success = false;
    	return NULL;
	}
    if (key > root->data)
        root->right = deleteAVL(root->right, key, &*success);
    else if(key < root->data)
        root->left = deleteAVL(root->left, key, &*success);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            *success = true;
            return NULL;
        }
        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            NODE *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            *success = true;
            return temp;
        }
        //Two Children
        else
        {
            NODE *temp = max_Node(root->left);
            root->data = temp->data;
            root->left = deleteAVL(root->left, temp->data, &*success);
        }
    }
    int bf = computeBalanceF(root);
    if(bf== 2 && computeBalanceF(root->left) == -1) { root = lrrotation(root); }
	else if(bf==-2 && computeBalanceF(root->right) == 1) { root = rlrotation(root); }
	else if((bf == -2 && computeBalanceF(root->right) == -1) || (bf ==-2 && computeBalanceF(root->right) == 0)) { root = leftRotate(root); }
    else if((bf==2 && computeBalanceF(root->left) == 1) || (bf == 2 && computeBalanceF(root->left) == 0) ) { root = rightRotate(root); } // right Heavy

    return root;
}
/*==============================================================================
FUNCTION    : searchResult
DESCRIPTION : Prints if a key was found or not through the boolean "success."
ARGUMENTS   : INT key, BOOL success - key to search for and success status (T or F).
RETURNS     : void
==============================================================================*/
void searchResult(int key, bool success) {
    if(success)
		printf("\n%d was found\n", key);
	else
		printf("\n%d was not found\n", key);
}
/*==============================================================================
FUNCTION    : nullifyQUEUE
DESCRIPTION : Initializes a QUEUE.
ARGUMENTS   : QUEUE *Q - Q that is being intialized
RETURNS     : void
==============================================================================*/
void nullifyQUEUE(QUEUE *Q) {
	Q->count = 0, Q->front = NULL, Q->rear = NULL;
}
/*==============================================================================
FUNCTION    : emptyQUEUE
DESCRIPTION : Checks to see if QUEUE is empty or not.
ARGUMENTS   : QUEUE *Q - Q that is being read.
RETURNS     : BOOL - returns true or false
==============================================================================*/
bool emptyQUEUE(QUEUE *Q) {
	// Check if QUEUE is empty or not
	bool isEmpty = false;
	if(Q->count == 0)
		isEmpty = true;
	return isEmpty;
}
/*==============================================================================
FUNCTION    : enqueue
DESCRIPTION : Appends a node to the rear of a QUEUE
ARGUMENTS   : QUEUE *Q, NODE *temp - Q being read, and temp that is being added
              to the QUEUE
RETURNS     : void
==============================================================================*/
void enqueue(QUEUE *Q, NODE *temp) {
	// ENQUEUE at front
	temp->next = NULL;
	if(emptyQUEUE(Q)) // If QUEUE empty
	{
		Q->front = temp;
		Q->rear = temp;
	}
	else
	{
		Q->rear->next = temp;
		Q->rear = temp;
	}
	Q->count++;
}
/*==============================================================================
FUNCTION    : dequeue
DESCRIPTION : Dequeues a NODE in a QUEUE from the front.
ARGUMENTS   : QUEUE *Q - Q that is being read
RETURNS     : void
==============================================================================*/
void dequeue(QUEUE *Q) {
	if(emptyQUEUE(Q)) // If QUEUE Empty
		return;
	else
	{
		NODE *ptr = Q->front;
		if(Q->count == 1) // If QUEUE has only 1
		{
			Q->front = NULL;
			Q->rear = NULL;
		}
		else
			Q->front = Q->front->next;
		Q->count--;
	}
}
/*==============================================================================
FUNCTION    : infix
DESCRIPTION : Processes each NODE in a tree through LNR (infix) traversal.
ARGUMENTS   : NODE *root - root of the AVL tree
RETURNS     : void
==============================================================================*/
void infix(NODE *root) {
  	if (root != NULL) // LNR
	{
    	infix(root->left);
    	printf("%d -> ", root->data);
    	infix(root->right);
  	}
}
/*==============================================================================
FUNCTION    : prefix
DESCRIPTION : Processes each NODE in a tree through NLR (prefix) traversal.
ARGUMENTS   : NODE *root - root of the AVL tree
RETURNS     : void
==============================================================================*/
void prefix(NODE *root) {
	if(root != NULL) // NLR
	{
		printf("%d ->", root->data);
		prefix(root->left);
		prefix(root->right);
	}
}
/*==============================================================================
FUNCTION    : postfix
DESCRIPTION : Processes each NODE in a tree through LRN (postfix) traversal.
ARGUMENTS   : NODE *root - root of the AVL tree
RETURNS     : void
==============================================================================*/
void postfix(NODE *root) {
	if(root != NULL) // LRN
	{
		postfix(root->left);
		postfix(root->right);
		printf("%d ->", root->data);
	}
}
/*==============================================================================
FUNCTION    : breadthf
DESCRIPTION : Processes each NODE in a tree through breadthe-first traversal by
              using the implementation of a QUEUE to process nodes.
ARGUMENTS   : NODE *root - root of the AVL tree
RETURNS     : void
==============================================================================*/
void breadthf(NODE *root) {
	// Initialize QUEUE & Variables
	NODE *temp;
	QUEUE *Q = (QUEUE *)malloc(sizeof(QUEUE));
	nullifyQUEUE(Q);

	// Process Root
	enqueue(Q, root);

	// Breadthe-First Traversal
	for(temp = Q->front; !emptyQUEUE(Q); temp = Q->front)
	{
		printf("%d ->", temp->data);
		if(temp->left != NULL)
			enqueue(Q, temp->left);
		if(temp->right != NULL)
			enqueue(Q, temp->right);
		if(!emptyQUEUE(Q))
			dequeue(Q);
	}
	free(Q); // free QUEUE
}
/*==============================================================================
FUNCTION    : traversals
DESCRIPTION : Calls infix, prefix, postfix, and breadthe-first traversals to print
              onto terminal.
ARGUMENTS   : NODE *root - root of the AVL tree
RETURNS     : void
==============================================================================*/
void traversals (NODE *root) {
    printf("\nINFIX: ");
    infix(root);
    printf("\nPREFIX: ");
    prefix(root);
    printf("\nPOSTFIX: ");
    postfix(root);
    printf("\nBREADTHEFIRST: ");
    breadthf(root);
    printf("\n");
}
