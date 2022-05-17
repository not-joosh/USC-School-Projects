/*
================================================================================
FILE        : search.h
AUTHORS     : Paul Corsino, Ivan Galicia, and Josh Ratificar
DESCRIPTION : This file holds the structures, constant variables, and
              function prototypes for the sorting, destruction, creation,
              searching, and displaying of a linked list.
COPYRIGHT   : 1 March 2022
REVISION HISTORY
Date: 				By: 		Description:
================================================================================
*/
#ifndef search_h
#define search_h
/*
================================================================================
Structures
================================================================================
*/
typedef struct node {
	int data;
	struct node *next, *prev;
}NODE;

typedef struct list {
	int count;
	struct node *tail, *head;
}LIST;
/*
================================================================================
Constant Variables
================================================================================
*/
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define DRED FOREGROUND_RED
#define LRED FOREGROUND_RED | FOREGROUND_INTENSITY
#define LBLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define RESET_TEXT SetConsoleTextAttribute(hConsole, saved_attributes)
/*
================================================================================
Function Prototypes
================================================================================
*/
void nullifyList(LIST *L);
LIST * createList(LIST *L, int *flag);
void generateNum(LIST *L);
void appendRear(LIST *L, int x);
void destroyList(LIST *L, int *flag, int *sortFlag);
void shellSort(LIST *L, int *sortFlag, int *flag);
void binarySearch(LIST *L, int *flag, int *sortFlag);
void linearSearch(LIST *L, int *flag);
void displayIndex(int searchFlag, int x, int index);
void displayList(LIST *L, int flag);
#endif // search_h
