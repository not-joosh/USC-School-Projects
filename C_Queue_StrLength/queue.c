 /*======================================================================================================
FILE        : queue.c
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Contains the functions to perform queue operations and string operations.
COPYRIGHT   : 8 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "queue.h"
#include "menu.h"
/*==============================================================================
FUNCTION    : nullifyQueue
DESCRIPTION : Initializes an empty queue
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
RETURNS     : void
==============================================================================*/
void nullifyQUEUE(QUEUE *Q){
    Q->front = NULL;
    Q->rear = NULL;
    Q->count = 0;
}
/*==============================================================================
FUNCTION    : checkEmpty
DESCRIPTION : Checks if the queue is empty
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
RETURNS     : bool - returns true or false
==============================================================================*/
bool checkEmpty(QUEUE *Q) {
	bool isEmpty = false;
	if(Q->count == 0) {
		isEmpty = true;
	}
	return isEmpty;
}
/*==============================================================================
FUNCTION    : checkFull
DESCRIPTION : Checks if the queue is full
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
RETURNS     : bool - returns true or false
==============================================================================*/
bool checkFull(QUEUE *Q) {
	bool isFull = false;
	if(Q->count == MAX_QUEUE) {
		isFull = true;
	}
	return isFull;
}
/*==============================================================================
FUNCTION    : getSIZE
DESCRIPTION : Finds the amount of elements stored in queue
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
RETURNS     : int - returns the value of pointer Q->count
==============================================================================*/
int getSIZE(QUEUE *Q) {
	return Q->count;
}
/*==============================================================================
FUNCTION    : enqueue
DESCRIPTION : Inserts an element at the rear of the queue
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
              char *str - pointer to the reference address of a string
RETURNS     : bool - returns true or false
==============================================================================*/
bool enqueue(QUEUE *Q, char *str) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

	bool isEnqueued = false;
	bool isEmpty = checkEmpty(Q);
	bool isFull = checkFull(Q);
	int count = 0;
	if(isFull == true) {
		SetConsoleTextAttribute(hConsole, WHITE);
		printf("\n\t\t\t\t\t     QUEUE OVERFLOW");
	}
	else {
		NODE *newNode = (NODE *)malloc(sizeof(NODE));
		int count = 0;
		newNode->link = NULL;
		strcpy(newNode->str, *&str);
		read(newNode->str, &count);
		newNode->length = count;

		if(isEmpty == true) {
			Q->front = newNode;
			Q->rear = newNode;
		}
		else {
			Q->rear->link = newNode;
			Q->rear = newNode;
		}
		isEnqueued = true;
		Q->count++;
	}
	return isEnqueued;
}
/*==============================================================================
FUNCTION    : dequeue
DESCRIPTION : Removes an element at the rear of the queue
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
RETURNS     : bool - returns true or false
==============================================================================*/
bool dequeue(QUEUE *Q) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

	bool isDequeued = false;
	bool isEmpty = checkEmpty(Q);
	int SIZE = getSIZE(Q);
	if(isEmpty == true) {
        SetConsoleTextAttribute(hConsole, WHITE);
		printf("\n\t\t\t\t\t     QUEUE UNDERFLOW");
	}
	else {
		NODE *ptr = Q->front;
		if(SIZE == 1) { // For One Node
			Q->front = NULL;
			Q->rear = NULL;
		}
		else {
			Q->front = ptr->link;
		}
		free(ptr);
		isDequeued = true;
		Q->count--;
	}
	return isDequeued;
}
/*==============================================================================
FUNCTION    : queueFront
DESCRIPTION : Retrieves the element at the front of queue
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
              char *str - pointer to the reference address of a string variable
RETURNS     : bool - returns true or false
==============================================================================*/
bool queueFront(QUEUE *Q, char *str) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

	bool success = false;
	bool isEmpty = checkEmpty(Q);
	if(isEmpty == true) {
		SetConsoleTextAttribute(hConsole, WHITE);
		printf("\n\t\t\t\t\t     QUEUE UNDERFLOW");
	}
	else {
		NODE *ptr = Q->front;
		strcpy(*&str, ptr->str);
		success = true;
	}
	return success;
}
/*==============================================================================
FUNCTION    : queueRear
DESCRIPTION : Retrieves the element at the rear of queue
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
              char *str - pointer to the reference address of a string variable
RETURNS     : bool - returns true or false
==============================================================================*/
bool queueRear(QUEUE *Q, char *str) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

	bool success = false;
	bool isEmpty = checkEmpty(Q);
	if(isEmpty == true) {
		SetConsoleTextAttribute(hConsole, WHITE);
		printf("\n\t\t\t\t\t     QUEUE UNDERFLOW");
	}
	else {
		NODE *ptr = Q->rear;
		strcpy(*&str, ptr->str);
		success = true;
	}
	return success;
}
/*==============================================================================
FUNCTION    : read
DESCRIPTION : Finds the length of a given string by recursion
ARGUMENTS   : char *str, int *count
RETURNS     : void
==============================================================================*/
void read(char *str, int *count) {
	if(*str != NULL) {
		*count += 1;
		return read(++str, *&count);
	}
	else {
		return;
	}
}
/*==============================================================================
FUNCTION    : displayQueue
DESCRIPTION : Displays the elements stored in queue
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
RETURNS     : void
==============================================================================*/
void displayQueue(QUEUE *Q) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

	bool isEmpty = checkEmpty(Q);
	if(isEmpty == true) {
        SetConsoleTextAttribute(hConsole, LRED);
		printf("\n\t\t\t\t\t    QUEUE UNDERFLOW\n"); //displays if queue is empty
	}
	else {
		NODE *ptr;
		SetConsoleTextAttribute(hConsole, WHITE | UNDERSCORE);
		printf("\n\t\t\t\t\tString");
		printf("\t\tLength\n");
		SetConsoleTextAttribute(hConsole, DRED);
		for(ptr = Q->front; ptr != NULL; ptr = ptr->link) { //displays element in queue until node is null
            printf("\t\t\t\t\t\%s\t\t  %d", ptr->str, ptr->length);
            printf("\n");
		}

	}
}
