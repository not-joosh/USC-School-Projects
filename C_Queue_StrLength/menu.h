 /*======================================================================================================
FILE        : menu.h
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Contains the function prototypes, and terminal coloring
COPYRIGHT   : 8 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include "queue.h"
#ifndef MENU_H
#define MENU_H
/*
================================================================================
Terminal coloring
================================================================================
*/
#define LRED FOREGROUND_RED | FOREGROUND_INTENSITY
#define DGREEN FOREGROUND_GREEN
#define DBLUE FOREGROUND_BLUE
#define DRED FOREGROUND_RED
#define WHITE DRED | DGREEN | DBLUE | FOREGROUND_INTENSITY
#define UNDERSCORE COMMON_LVB_UNDERSCORE
/*
================================================================================
Function prototypes
================================================================================
*/
int printMenu(QUEUE *Q);
void choiceHandler(QUEUE *Q, int choice, int *menu);
#endif // MENU_H
