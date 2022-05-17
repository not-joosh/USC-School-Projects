 /*======================================================================================================
FILE        : AVL.h
AUTHOR      : Josh B. Ratificar, Paolo Jansen A. Enrera, Mohan Nuelle T. Francis, & Rhett Joshua L. Surban.
DESCRIPTION : This file holds the structures, constant variables, and
              function prototypes for the inserting, rotating, traversals, searching
              and node deletion of binary trees.
COPYRIGHT   : 10 May 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdbool.h>
#ifndef AVL_H
#define AVL_H
/*==============================================================================
Structures
==============================================================================*/
typedef struct node {
	int data;
	int height;
	struct node *left, *right, *next;
}NODE;
typedef struct queue {
	int count;
	struct node *front, *rear;
}QUEUE;
/*==============================================================================
Function Prototypes
==============================================================================*/
NODE * newNode(int value);
int height(NODE* root);
int max_Height(int left, int right); // This Changed
int computeBalanceF(NODE *node);
NODE * rightRotate(NODE *node);
NODE * leftRotate(NODE *node);
NODE * lrrotation(NODE *node);
NODE * rlrotation(NODE *node);
NODE * insertAVL(NODE *node,int value);
NODE * max_Node(NODE *node); // This Changed
NODE * deleteAVL(NODE *root, int key, bool *success);
void searchResult(int key, bool success);
void nullifyQUEUE(QUEUE *Q);
bool emptyQUEUE(QUEUE *Q);
void enqueue(QUEUE *Q, NODE *temp);
void dequeue(QUEUE *Q);
void infix(NODE *root);
void prefix(NODE *root);
void postfix(NODE *root);
void breadthf(NODE *root);
void traversals(NODE *root);
#endif // AVL_H
