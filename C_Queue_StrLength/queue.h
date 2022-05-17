 /*======================================================================================================
FILE        : queue.h
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Contains the function prototypes, structures, and constant variables.
COPYRIGHT   : 8 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdbool.h>
#ifndef QUEUE_H
#define QUEUE_H
/*
================================================================================
Structures
================================================================================
*/
typedef struct node {
	int length;
	char str[30];
	struct node *link;
}NODE;
typedef struct queue {
	int count;
	struct node *front, *rear;
}QUEUE;
/*
================================================================================
Constant variables
================================================================================
*/
#define MAX_QUEUE 5
/*
================================================================================
Function prototypes
================================================================================
*/
void nullifyQUEUE(QUEUE *Q);
bool checkEmpty(QUEUE *Q);
bool checkFull(QUEUE *Q);
bool enqueue(QUEUE *Q, char *str);
bool dequeue(QUEUE *Q);
bool queueFront(QUEUE *Q, char *str);
bool queueRear(QUEUE *Q, char *str);
void read(char *str, int *count);
void displayQueue(QUEUE *Q);
#endif
