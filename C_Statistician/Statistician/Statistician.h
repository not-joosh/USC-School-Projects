/*
================================================================================
FILE        : Statistician.h
AUTHORS     : Holchi Henchi Alin, John Myl B. Alinsonorin, Mohan Nuelle Francis,
              & Josh Bobier Ratificar,
DESCRIPTION : Contains the function prototypes, structure, and constant variables.
COPYRIGHT   : 1 March 2022
REVISION HISTORY
Date: 				By: 		Description:
================================================================================
*/
#ifndef Statistician_h
#define Statistician_h
/*
================================================================================
Structures
================================================================================
*/
typedef struct node {
	int data;
	struct node *next, *prev;
}NODE;
typedef struct Statistician {
	int count;
	int minimum;
	int maximum;
	int range;
	int sum;
	float mean;
	float median;

	int mode;
	int modeCount;

	float variance;
	float standardDeviation;


	struct node *head, *tail;
}STAT;
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
#define statExists 1
/*
================================================================================
Function Prototypes
================================================================================
*/
int displayMenu(int choice);
void choiceHandler(int choice, int *menu, STAT *S, int *flag);
STAT * newStatistician(STAT *S, int *flag);
void destroyStatistician(STAT *S, int *flag);
void add(STAT *S, int x);
void removeAt(STAT *S, int x);
void computeStats(STAT *S);
int maximum(STAT *S);
int minimum(STAT *S) ;
int sum(STAT *S);
int range(STAT *S);
float mean(STAT *S);
float median(STAT *S);
float variance(STAT *S);
float stdeviation(STAT *S);
int mode(STAT *S);
void printMode(STAT *S);
void displayData(STAT *S, int flag);
#endif //Statistician_H
