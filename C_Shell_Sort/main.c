/*
================================================================================
FILE        : main.c
AUTHORS     : Paul Corsino, Ivan Galicia, and Josh Ratificar
DESCRIPTION : Contains the Menu Display, Choice Handler, and the main which keeps
              the menu in loop.
COPYRIGHT   : 1 March 2022
REVISION HISTORY
Date: 				By: 		Description:
================================================================================
*/
/*
================================================================================
Header Files
================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "search.h"
/*
================================================================================
FUNCTION    : displayMenu
DESCRIPTION : Displays the menu options in color and prompts to get
              user's choice.
ARGUMENTS   : int choice -
RETURNS     : INT - Returns Choice Value
================================================================================
*/
int displayMenu(int choice) {
    // Unix Terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    // Displaying Menu Options
    system("CLS");
    SetConsoleTextAttribute(hConsole, YELLOW);
    printf("\n\n\n\t\t\t\t\t\tMAIN MENU");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n");
    SetConsoleTextAttribute(hConsole, YELLOW);
    printf("\n\t\t\t\t\t[1] Create List");
    printf("\n\t\t\t\t\t[2] Destroy List");
    printf("\n\t\t\t\t\t[3] Binary Search");
    printf("\n\t\t\t\t\t[4] Linear Search");
    printf("\n\t\t\t\t\t[5] Sort List");
    printf("\n\t\t\t\t\t[6] Display List\n");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t\t[7] Exit");
    SetConsoleTextAttribute(hConsole, LBLUE);
    printf("\n\t\t\t\t   __________________________________\n\t\t\t\t\t\t");
    printf("Choice: ");
    SetConsoleTextAttribute(hConsole, YELLOW);
    // Exiting and returning choice
    scanf("%d", &choice);
    return choice;
}
/*
================================================================================
FUNCTION    : main
DESCRIPTION : Initializes a List, flag, and sort flag. Runs the menu conditions
              until asked to terminate.
ARGUMENTS   : void
RETURNS     : INT - return value 0;
================================================================================
*/
int main(void) {
    // Unix Terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int menu = 1, flag = 0, userChoice, sortFlag = 0;
    LIST *L;
    while(menu == 1) {
        userChoice = displayMenu(userChoice);
        if(userChoice == 1) {
            L = createList(L, &flag);
            // Returning to menu.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t  Returning to main menu, press any key to continue...\n\t\t\t\t\t\t  ");
            getch();
        }
        else {
            choiceHandler(L, userChoice, &menu, &flag, &sortFlag);
        }
    }
    return 0;
}
/*
================================================================================
FUNCTION    : choiceHandler
DESCRIPTION : Updates flag(list status), sort flag(sort status), menu status,
              and List in retrospect to user choice. Will call certain functions
              based on the user's choice.
ARGUMENTS   : LIST *L, int userChoice, int *menu, int *flag, int *sortFlag
RETURNS     : void - uses pointers to return LIST, menu status, flag, & sortFlag.
================================================================================
*/
void choiceHandler(LIST *L, int userChoice, int *menu, int *flag, int *sortFlag) {
    // Unix Terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    switch(userChoice) {
        case 2: { // Destroy List
            destroyList(L, *&flag, *&sortFlag);
            // Returning to menu.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t  Returning to main menu, press any key to continue...\n\t\t\t\t\t\t  ");
            getch();
            break;
        }
        case 3: { // Binary Search
            binarySearch(L, *&flag, *&sortFlag);
            // Returning to menu.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t  Returning to main menu, press any key to continue...\n\t\t\t\t\t\t  ");
            getch();
            break;
        }
        case 4: { // Linear Search
            linearSearch(L, *&flag);
            // Returning to menu.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t  Returning to main menu, press any key to continue...\n\t\t\t\t\t\t  ");
            getch();
            break;
        }
        case 5: { // Sort
            shellSort(L, *&sortFlag, *&flag);
            // Returning to menu.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t  Returning to main menu, press any key to continue...\n\t\t\t\t\t\t  ");
            getch();
            break;
        }
        case 6: { //
            displayList(L, *flag);
            // Returning to menu.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t  Returning to main menu, press any key to continue...\n\t\t\t\t\t\t  ");
            getch();
            break;
        }
        case 7: { // Exit
            *menu -= *menu;
            system("CLS");
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\n\n\n\t\t\tMenu Terminated\n\n\n\n\n\n  ");
            SetConsoleTextAttribute(hConsole, LBLUE);
            break;
        }
        default: { // Invalid Case
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\n\t\t\t\t         Invalid Choice!");
            // Returning to menu.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t  Returning to main menu, press any key to continue...\n\t\t\t\t\t\t  ");
            getch();
            break;
        }
    }
}
