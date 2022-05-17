 /*======================================================================================================
FILE        : menu.h
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Contains the terminal coloring and menu function prototypes
COPYRIGHT   : 4 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include "stack.h"
#ifndef MENU_H
#define MENU_H


/*
================================================================================
Terminal coloring
================================================================================
*/
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define LBLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define LRED FOREGROUND_RED | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
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
int mMenu(STACK *S);
int pushMenu();
int convertMenu();
void M_ChoiceHandler(STACK *S, int choice, int *menu);

#endif // MENU_H
