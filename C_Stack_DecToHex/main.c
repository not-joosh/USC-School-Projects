 /*======================================================================================================
FILE        : main.c
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Program that demonstrates the stack operation - Push, Top, Pop.
COPYRIGHT   : 4 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "stack.h"
#include "menu.h"

/*==============================================================================
FUNCTION    : main
DESCRIPTION : Execute the main program that displays a menu and handles user input
ARGUMENTS   :
RETURNS     : void
==============================================================================*/

void main() {
    STACK *S = (STACK *)malloc(sizeof(STACK));//initializes stack
    nullifyStack(S);
    int menu = 1, choice;
    while(menu == 1)//loops menu
    {
        choice = mMenu(S);
        M_ChoiceHandler(S, choice, &menu);
    }
    return 0;
}
