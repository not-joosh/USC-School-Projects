 /*======================================================================================================
FILE        : stack.h
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Contains the function prototypes, structures, and constant variables.
COPYRIGHT   : 4 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdbool.h>
#ifndef STACK_H
#define STACK_H
/*
================================================================================
Structures
================================================================================
*/
typedef struct node {
	bool isHexa;
	char hexa[30];
	int decimal;
	struct node *next, *prev;
}NODE;
typedef struct stack {
	int count;
	struct node *top;
}STACK;

/*
================================================================================
Constant variables
================================================================================
*/
#define STACK_MAX 5
#define HEXAVALUE 16

/*
================================================================================
Function prototypes
================================================================================
*/
void nullifyStack(STACK *S);
int getSIZE(STACK *S);
bool checkFull(STACK *S);
bool checkEmpty(STACK *S);
bool pushStack(STACK *S, int dataIn);
bool popStack(STACK *S, int *dataOut, char *dataOutHex, int *flag);
bool topStack(STACK *S, int *dataOutInt, char *dataOutHex, int *flag);


void generate(STACK *S);
void manual(STACK *S);
void decToHex(STACK *S, int method);
void printStack(STACK *S);

#endif // STACK_H
