 /*======================================================================================================
FILE        : main.c
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Program that demonstrates the queue operations - Enqueue, Dequeue, Queue front, and Queue rear.
COPYRIGHT   : 8 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "menu.h"
#include "queue.h"
/*==============================================================================
FUNCTION    : main
DESCRIPTION : Execute the main program that initializes queue and loops a menu
              until the user exits.
ARGUMENTS   :
RETURNS     : void
==============================================================================*/
void main() {
    QUEUE *Q = (QUEUE *)malloc(sizeof(QUEUE));
    nullifyQUEUE(Q);
    int menu = 1, choice;
    while(menu == 1) {
        choice = printMenu(Q);
        choiceHandler(Q, choice, &menu);
    }
}
