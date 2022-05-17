 /*======================================================================================================
FILE        : menu.c
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Contains the functions for displaying the menu and handling user choice.
COPYRIGHT   : 8 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "queue.h"
#include "menu.h"
/*==============================================================================
FUNCTION    : printMenu
DESCRIPTION : Displays the menu and receives user input
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
RETURNS     : int - returns user choice
==============================================================================*/
int printMenu(QUEUE *Q){
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    // Displaying Menu Options and Initiating choice
    int choice;
    system("CLS");
    SetConsoleTextAttribute(hConsole, WHITE);
    printf("\n\n\n\t\t\t\t\t    QUEUE MAIN MENU");
    SetConsoleTextAttribute(hConsole, DRED);
    printf("\n\t\t\t\t   __________________________________\n");
    SetConsoleTextAttribute(hConsole, WHITE);
    printf("\n\t\t\t\t\t[1] Enqueue");
    printf("\n\t\t\t\t\t[2] Dequeue");
    printf("\n\t\t\t\t\t[3] Queue Front Search");
    printf("\n\t\t\t\t\t[4] Queue Rear Search\n");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t\t[5] Exit");
    SetConsoleTextAttribute(hConsole, DRED);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t      ");
    SetConsoleTextAttribute(hConsole, WHITE | UNDERSCORE);
    printf("\t\tQUEUE");
    SetConsoleTextAttribute(hConsole, DRED);
    displayQueue(Q);
    SetConsoleTextAttribute(hConsole, DRED);
    printf("\t\t\t\t   __________________________________\n\t\t\t\t\t\t");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("Choice: ");
    SetConsoleTextAttribute(hConsole, WHITE);

    scanf("%d", &choice);
    return choice;
}
/*==============================================================================
FUNCTION    : choiceHandler
DESCRIPTION : Handles user choice and calls functions to perform queue operations
ARGUMENTS   : QUEUE *Q - pointer to the reference address of QUEUE
              int choice - stores the user input
              int *menu - pointer to the reference address of menu
RETURNS     : void
==============================================================================*/
void choiceHandler(QUEUE *Q, int choice, int *menu) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    char str[30];
    switch(choice) {
        case 1: { // Enqeueue
            SetConsoleTextAttribute(hConsole, WHITE);
            printf("\t\t\t\t  Enter a string: ");
            SetConsoleTextAttribute(hConsole, DRED);
            scanf("%s", &str);
            if(enqueue(Q, str)) {
                SetConsoleTextAttribute(hConsole, WHITE);
                printf("\n\t\t\t\t\t\t  Success!");
            }
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\t\t\t\t        Press any key to continue... ");
            getch();
            break;
        }
        case 2: { // Dequeue
            if(dequeue(Q)) {
                SetConsoleTextAttribute(hConsole, WHITE);
                printf("\n\t\t\t\t\t\t  Success!");
            }
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\t\t\t\t        Press any key to continue... ");
            getche();
            break;
        }
        case 3: { // Queue Front Search
            if(queueFront(Q, &str)) {
                SetConsoleTextAttribute(hConsole, DRED);
                printf("\n\t\t\t\t   %s ", str);
                SetConsoleTextAttribute(hConsole, WHITE);
                printf("is at the front of the queue.");
            }
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\t\t\t\t        Press any key to continue... ");
            getche();
            break;
        }
        case 4: { // Queue Rear Search
            if(queueRear(Q, &str)) {
                SetConsoleTextAttribute(hConsole, DRED);
                printf("\n\t\t\t\t   %s ", str);
                SetConsoleTextAttribute(hConsole, WHITE);
                printf("is at the rear of the queue.");
            }
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\t\t\t\t        Press any key to continue... ");
            getche();
            break;
        }
        case 5: { // Exit
            system("CLS");
            *menu -= 1;
            SetConsoleTextAttribute(hConsole, WHITE);
            printf("\n\n\n\t\tTerminal Terminated.\n\n\n\n");
            SetConsoleTextAttribute(hConsole, DRED);
            break;
        }
        default: { // Invalid
            SetConsoleTextAttribute(hConsole, WHITE);
            printf("\n\t\t\t\t\t      INVALID CHOICE");
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\t\t\t\t        Press any key to continue... ");
            getche();
            break;
        }
    }
}
