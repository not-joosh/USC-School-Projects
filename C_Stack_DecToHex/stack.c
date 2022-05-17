 /*======================================================================================================
FILE        : stack.c
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Functions to perform stack operations and conversion of decimal to hexadecimal.
COPYRIGHT   : 4 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include "menu.h"
#include "stack.h"

/*==============================================================================
FUNCTION    : nullifyStack
DESCRIPTION : Initializes an empty stack
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : void
==============================================================================*/
void nullifyStack(STACK *S) {
    S->top = NULL;
    S->count = 0;
}
/*==============================================================================
FUNCTION    : getSize
DESCRIPTION : Gets the size of the stack
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : int - returns the pointer of S->count
==============================================================================*/
int getSIZE(STACK *S) {
    return  S->count;
}
/*==============================================================================
FUNCTION    : checkFull
DESCRIPTION : Checks if the stack reached the max input
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : bool - returns true or false
==============================================================================*/
bool checkFull(STACK *S) {
    bool isFull = false;
    if(S->count == STACK_MAX) {
        isFull = true;
    }
    return isFull;
}
/*==============================================================================
FUNCTION    : checkEmpty
DESCRIPTION : Checks if the stack is empty
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : bool - returns true or false
==============================================================================*/
bool checkEmpty(STACK *S) {
    bool isEmpty = false;
    if(S->count == 0) {
        isEmpty = true;
    }
    return isEmpty;
}
/*==============================================================================
FUNCTION    : pushStack
DESCRIPTION : Inserts an object at the top of the stack
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
              int dataIn - holds the value of the object added to the stack
RETURNS     : bool - returns true or false
==============================================================================*/
bool pushStack(STACK *S, int dataIn) {
    bool isPushed = false;
	bool isFull = checkFull(S);
	if(isFull == false) {
		NODE *newNode = (NODE *)malloc(sizeof(NODE));
		newNode->prev = NULL;
		newNode->next = NULL;
		newNode->decimal = dataIn;
		newNode->isHexa = false;
		if(S->count == 0) { // If STACK is empty...
			S->top = newNode;
		}
		else { // If STACK has succeeding nodes...
			S->top->next = newNode;
			newNode->prev = S->top;
			S->top = newNode;
		}
		isPushed = true;
		S->count++;
	}
	return isPushed;
}
/*==============================================================================
FUNCTION    : popStack
DESCRIPTION : Removes the top object of the stack and returns it
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
              int *dataOut - pointer to the address of variable that stores decimal
              char *dataOutHex - pointer to the address of variable that stores hex
              int *flag - pointer to the address of variable of a flag
RETURNS     : bool - returns true or false
==============================================================================*/
bool popStack(STACK *S, int *dataOut, char *dataOutHex, int *flag){
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    bool isPopped = false;
    bool isEmpty = checkEmpty(S);
    int SIZE = getSIZE(S);
    NODE *ptr = S->top;
    if(isEmpty == true)
    {
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\n\t\t\t\t\t  Stack Underflow!"); //displays if stack is empty
    }
    else {
        if(ptr->isHexa == true) //checks if data in the ptr is hexadecimal
        {
            strcpy(*&dataOutHex, ptr->hexa);
            *flag = 0;
        }
        else{
            *dataOut = ptr->decimal;
            *flag = 1;
        }
        if(SIZE == 1) //nullifies top if only one object in stack
        {
            S->top = NULL;
        }
        else
        {
            ptr = ptr->prev;
            ptr->next = NULL;
            S->top = ptr;
        }
        S->count--;
        isPopped = true;
    }
    return isPopped;
}
/*==============================================================================
FUNCTION    : topStack
DESCRIPTION : Returns the top object of the stack without deleting it
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
              int *dataOutInt - pointer to the address of variable that stores decimal
              char *dataOutHex - pointer to the address of variable that stores hex
              int *flag - pointer to the address of variable of a flag
RETURNS     : bool - returns true or false
==============================================================================*/
bool topStack(STACK *S, int *dataOutInt, char *dataOutHex, int *flag) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    bool isTopped = false;
    bool isEmpty = checkEmpty(S);
    if(isEmpty == true) {
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\n\t\t\t\t\t  Stack Underflow!");//displays if stack is empty
    }
    else {
        isTopped = true;
        if(S->top->isHexa == true) { //checks if data in top is hexadecimal
            strcpy(*&dataOutHex, S->top->hexa);
        }
        else {
            *dataOutInt = S->top->decimal;
            *flag = 1;
        }
    }
    return isTopped;
}
/*==============================================================================
FUNCTION    : generate
DESCRIPTION : Generates a random number and pushes it to stack
ARGUMENTS   : STACK *S - pointer to the reference address of STACK

RETURNS     : void
==============================================================================*/
void generate(STACK *S)
{
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    int count, n,pause, dataOut = 0, flag;
    char i, dataOutHex[30];
    time_t t;
    srand((unsigned) time(&t));

    if(checkFull(S)) //performs following conditions if stack is full
    {
        SetConsoleTextAttribute(hConsole, DRED);
        printf("\n\n\n\t\t\t\t\t  STACK OVERFLOW!");
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\t\t\t\t\t  Would you like to remove a number?");
        SetConsoleTextAttribute(hConsole, LBLUE);
        printf("\n\t\t\t\t\t  yes(y)  no(n)\n\t\t\t\t\t  Choice: ");
        SetConsoleTextAttribute(hConsole, LRED);
        i = getche();
        if(i == 'y'){
            if(popStack(S, &dataOut, &dataOutHex, &flag)){ //performs following conditions if pop was successful
                SetConsoleTextAttribute(hConsole, CYAN);
                if(dataOut > 0){
                    printf("\n\t\t\t\t\t  Deleted %d successfully\n", dataOut);
                }
                else{
                   printf("\n\t\t\t\t\t  Deleted %s successfully\n", dataOutHex);
                }
            }
        }
        else{
            return;
        }

    }
    //generates a random number between 0-1000
    n = rand() % 1001;
    pushStack(S, n);
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("\n\n\t\t\t\t   Number generated successfully!");
}
/*==============================================================================
FUNCTION    : manual
DESCRIPTION : Gets user input as an object an pushes it to the top of stack
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : void
==============================================================================*/
void manual(STACK *S)
{
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    int num, dataOut = 0, flag;
    char i, dataOutHex[30];
    if(checkFull(S))//performs following conditions if stack is full
    {
        SetConsoleTextAttribute(hConsole, DRED);
        printf("\n\n\n\t\t\t\t\t  STACK OVERFLOW!");
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\t\t\t\t\t  Would you like to remove a number?");
        SetConsoleTextAttribute(hConsole, LBLUE);
        printf("\n\t\t\t\t\t  yes(y)  no(n)\n\t\t\t\t\t  Choice: ");
        SetConsoleTextAttribute(hConsole, LRED);
        i = getche();
        if(i == 'y'){
            if(popStack(S, &dataOut, dataOutHex, &flag)){ //performs following conditions if pop was successful
                if(dataOut>0){
                    SetConsoleTextAttribute(hConsole, CYAN);
                    printf("\n\t\t\t\t\t  Deleted %d successfully\n", dataOut);
                }
                else{
                    printf("\n\t\t\t\t\t  Deleted %s successfully\n", dataOutHex);
                }
            }
        }
        else{
            return;
        }

    }

    SetConsoleTextAttribute(hConsole, CYAN);
    printf("\n\n\t\t\t\t     Enter a number: ");
    scanf("%d", &num);
    if(pushStack(S, num)) {
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\n\t\t\t\t   Number generated successfully!");
    }
}
/*==============================================================================
FUNCTION    : decToHex
DESCRIPTION : Converts decimal object to hexadecimal
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
              int method - stores user choice
RETURNS     : void
==============================================================================*/
void decToHex(STACK *S, int method) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    bool isEmpty = checkEmpty(S);
	if(isEmpty == true) {
		SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\n\t\t\t\t\t  Stack Underflow!");
	}
	else {
		NODE *ptr = S->top;
		int parse[30], original, frontNum, rearNum, i, j,k, g, temp, limit = 1;
		char localHex[30];
		if(method == 1) {
            limit = getSIZE(S);
		}
		for(g = 0; g < limit; g++, ptr = ptr->prev) {
			if(ptr->isHexa == false) { // check if this ptr already is in hexa
				original = ptr->decimal;
				for(i = 0, frontNum = original / HEXAVALUE, rearNum = original % HEXAVALUE; frontNum > 0; i++, original = frontNum) {
					frontNum = original / HEXAVALUE;
					rearNum = original % HEXAVALUE;
					parse[i] = rearNum;
					j = i;
				}
				for(i = j, k = 0; i >= 0 ; i--, k++) {
					if(parse[i] >= 10) {
						temp = parse[i] % 10;
						localHex[k]= temp + 'A';
					}
					else {
						localHex[k] = 48 + parse[i];
					}
				}
				strcpy(ptr->hexa, localHex);
				int *clearHex;
				for(clearHex = localHex; clearHex <= localHex + j; ++clearHex) {
					*clearHex = '\0';
				}
				ptr->isHexa = true;
			}
		}
		SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\t\t\t   Successfully Converted %d Decimal integers to Hex!", limit);
	}
}
/*==============================================================================
FUNCTION    : printStack
DESCRIPTION : displays the stack
ARGUMENTS   : STACK *S - pointer to the reference address of STACK

RETURNS     : void
==============================================================================*/
void printStack(STACK *S) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

	if(S->count == 0) {
		SetConsoleTextAttribute(hConsole, LRED);
        printf("Stack Underflow... \n");
	}
	else {
		NODE *ptr = S->top;
		while(ptr != NULL) {
			if(ptr->isHexa == false) {
                SetConsoleTextAttribute(hConsole, WHITE);
				printf("%d ", ptr->decimal);
			}
			else {
			    SetConsoleTextAttribute(hConsole, DRED);
				printf("%s ", ptr->hexa);
			}
			ptr = ptr->prev;
		}
		printf("\n");
	}
}
