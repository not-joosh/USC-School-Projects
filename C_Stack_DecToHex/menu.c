 /*======================================================================================================
FILE        : menu.c
AUTHOR      : Holchi Henche B. Alin, Josh B. Ratificar, Mohan Nuelle T. Francis, John Myl B. Alinsonsorin
DESCRIPTION : Contains functions designed to display menu and store the choices of the user
COPYRIGHT   : 4 April 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "menu.h"
#include "stack.h"
/*==============================================================================
FUNCTION    : mMenu
DESCRIPTION : Displays the main menu and gets a choice from the user
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : void
==============================================================================*/
int mMenu(STACK *S) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    // Displaying Menu Options and Initiating choice
    int choice;
    system("CLS");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("\n\n\n\t\t\t\t\t    STACK MAIN MENU");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("\n\t\t\t\t\t[1] Push");
    printf("\n\t\t\t\t\t[2] Pop");
    printf("\n\t\t\t\t\t[3] Top");
     printf("\n\t\t\t\t\t[4] Convert\n");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t\t[5] Exit");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\n\t\t\t\t");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("   STACK: ");
    printStack(S);
    SetConsoleTextAttribute(hConsole, WHITE);
    printf("\t\t\t\t   WHITE: [DECIMAL]");
    SetConsoleTextAttribute(hConsole, DRED);
    printf("\tDARKRED: [HEX]\n");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\t\t\t\t   __________________________________\n\t\t\t\t\t\t");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("Choice: ");
    SetConsoleTextAttribute(hConsole, LRED);

    scanf("%d", &choice);
    return choice;
}
/*==============================================================================
FUNCTION    : pushMenu
DESCRIPTION : Displays a menu for choosing the method to push the stack
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : void
==============================================================================*/
int pushMenu() {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    // Displaying Menu Options and Initiating choice
    int choice;
    system("CLS");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t\t     ");
    SetConsoleTextAttribute(hConsole, YELLOW);
    printf("\n\t\t\t\t\t    PUSH SELECTED!");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t\t     ");
    SetConsoleTextAttribute(hConsole, CYAN |UNDERSCORE);
    printf("Choose Method\n");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t\t[1] Generate Random Values");
    printf("\n\t\t\t\t\t[2] Manually Push Value\n");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t\t[3] Return");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t\t\t");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("Choice: ");
    SetConsoleTextAttribute(hConsole, LRED);

    scanf("%d", &choice);
    return choice;
}
/*==============================================================================
FUNCTION    : convertMenu
DESCRIPTION : Displays a conversion menu and gets a choice from the user
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
RETURNS     : void
==============================================================================*/
int convertMenu() {
     // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    // Displaying Menu Options and Initiating choice
    int choice;
    system("CLS");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t\t     ");
    SetConsoleTextAttribute(hConsole, YELLOW);
    printf("\n\t\t\t\t\t    CONVERT SELECTED!");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t\t     ");
    SetConsoleTextAttribute(hConsole, CYAN | UNDERSCORE);
    printf("Choose Method\n");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t\t[1] Convert All Values");
    printf("\n\t\t\t\t\t[2] Convert Top\n");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t\t[3] Return");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t\t\t");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("Choice: ");
    SetConsoleTextAttribute(hConsole, LRED);

    scanf("%d", &choice);
    return choice;
}
/*==============================================================================
FUNCTION    : M_ChoiceHandler
DESCRIPTION : Handles the user choice from the main menu to execute a stack operation
ARGUMENTS   : STACK *S - pointer to the reference address of STACK
              int choice - stores user choice
              int *menu - pointer to the menu
RETURNS     : void
==============================================================================*/
void M_ChoiceHandler(STACK *S, int choice, int *menu) {
    // Unix terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  	WORD saved_attributes;
  	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
  	saved_attributes = consoleInfo.wAttributes;

    int method;
    switch(choice)
    {
        case 1: // Push Stack Menu
        {
            method = pushMenu();
            if(method == 1){
                generate(S);
            }
            else if (method == 2){
                manual(S);
            }
            // Returning to Menu
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\t     Press a key to continue...");
            getche();
            break;
        }
        case 2: // Pop Stack
        {
            int dataOut = 0, flag;
            char dataOutHex[30];
            if(popStack(S, &dataOut, &dataOutHex, &flag)){
                SetConsoleTextAttribute(hConsole, CYAN);
                if(flag == 1) {
                    printf("\n\t\t\t\t\t  Deleted %d successfully\n", dataOut);
                }
                else{
                    printf("\n\t\t\t\t\t  Deleted %s successfully\n", dataOutHex);
                }
            }
            // Returning to Menu
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\t     Press a key to continue...");
            getche();
            break;
        }
        case 3: // Top Stack
        {
            int dataOut, flag;
            char dataOutHex[30];
            if(topStack(S, &dataOut, &dataOutHex, &flag)) {
                if(flag == 1) {
                    SetConsoleTextAttribute(hConsole, CYAN);
                    printf("\n\n\t\t\t\t     Top of Stack: %d", dataOut);
                }
                else{
                   printf("\n\n\t\t\t\t     Top of Stack: %s", dataOutHex);
                }
            }
            // Returning to Menu
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\t     Press a key to continue...");
            getche();
            break;
        }
        case 4: // Convert
        {
            method = convertMenu();
            if(method == 1 || method == 2) {
                decToHex(S, method);
            }

            // Returning to Menu
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\t     Press a key to continue...");
            getche();
            break;
        }
        case 5: // Exit
        {
            system("CLS");
            *menu -= 1;
            SetConsoleTextAttribute(hConsole, LBLUE);
            printf("\n\n\n\t\tTerminal Terminated.\n\n\n\n");
            SetConsoleTextAttribute(hConsole, YELLOW);
            break;
        }
        default:
        {
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\n\n\t\t\t\t\t   Invalid Choice!\n");
            // Returning to Menu
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\t\t\t\t     Press a key to continue...");
            getche();
            break;
        }
    }
}
