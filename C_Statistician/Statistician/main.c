/*
================================================================================
FILE        : main.c
AUTHORS     : Holchi Henchi Alin, John Myl B. Alinsonorin, Mohan Nuelle Francis,
              & Josh Bobier Ratificar,
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
#include "Statistician.h"

/*
================================================================================
FUNCTION    : displayMenu
DESCRIPTION : Execute the main program that display list operations and make
			  a choice.
ARGUMENTS   : int choice - gets user choice.
RETURNS     : int - returns the choice selection to main
================================================================================
*/
int displayMenu(int choice) {
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, CYAN);
    system("CLS");
    printf("\n\n\n\t\t\t\t\t     Main Menu" );
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\n\t\t\t\t  _______________________________\n");
    printf("\t\t\t\t |\t\t\t\t |\n");
    printf("\t\t\t\t |\t\t\t\t |\n");
    printf("\t\t\t\t |\t\t\t\t |\n");
    printf("\t\t\t\t |");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("     [1]New Statistician");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("\t |\n");
    printf("\t\t\t\t |");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("     [2]Destroy Statistician ");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("  |\n");
    printf("\t\t\t\t |");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("     [3]Add Data\t       ");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("  |\n");
    printf("\t\t\t\t |");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("     [4]Delete Data\t       ");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("  |\n");
    printf("\t\t\t\t |");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("     [5]Display Statistics   ");
    SetConsoleTextAttribute(hConsole, LRED);
    printf("  |\n");
    printf("\t\t\t\t |\t\t\t\t |\n");
    printf("\t\t\t\t |");
    printf("     [6]Exit\t\t       " );
    printf("  |\n");
    printf("\t\t\t\t |\t\t\t\t |\n");
    printf("\t\t\t\t |\t\t\t\t |\n");
    printf("\t\t\t\t |\t\t\t\t |\n");
    printf("\t\t\t\t |_______________________________|");
    SetConsoleTextAttribute(hConsole, CYAN);
    printf("\n\t\t\t\t\t    Choice: " );
    SetConsoleTextAttribute(hConsole, LRED);
    scanf("%d", &choice);
    RESET_TEXT;
    return choice;

}
/*
================================================================================
FUNCTION    : main
DESCRIPTION : Execute the main program which initializes the flag, choice, and menu
              status for the menu loop. It as well Holds an idle Statistician pointer.
ARGUMENTS   : void
RETURNS     : int - exit code
================================================================================
*/
int main(void) {
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    STAT *S;
    int menu = 1, choice, flag = 0;
    while(menu == 1) {
        choice = displayMenu(choice);
        if(choice == 1) { // Create new Stat
            S = newStatistician(S, &flag);
            // Returning back to menu display.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\tPress any key to proceed to the main menu...\n\t\t\t\t\t\t");
            getch();
        }
        else {
            choiceHandler(choice, &menu, S, &flag);
        }
    }
    return 0;
}
/*
================================================================================
FUNCTION    : choiceHandler
DESCRIPTION : Execute the main program which initializes the flag, choice, and menu
              status for the menu loop. It as well Holds an idle Statistician pointer.
ARGUMENTS   : int choice, int *menu, STAT *S, int *flag - updates flag info and menu
              when necessary. Passes Statistician, flag, according to conditions.
RETURNS     : void - does not return a value.
================================================================================
*/
void choiceHandler(int choice, int *menu, STAT *S, int *flag) {
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int x;
    switch(choice) {
        case 2:
        { // Destroy Statistician

            destroyStatistician(S, &*flag);
            // Returning back to menu display.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\tPress any key to proceed to the main menu...\n\t\t\t\t\t\t");
            getch();
            break;

        }
        case 3:
        { // Add Data
            if(*flag == 1) {
                SetConsoleTextAttribute(hConsole, CYAN);
                printf("\n\n\n\t\t\t\tWhat value would you like to add?: ");
                SetConsoleTextAttribute(hConsole, YELLOW);
                scanf("%d", &x);
                add(S, x);
            }
            else {
                SetConsoleTextAttribute(hConsole, LRED);
                printf("\n\n\n\t\t\t\tError. Statistician does not exist.\n");
            }
            // Returning back to menu display.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\t\t\t\tPress any key to proceed to the main menu...\n\t\t\t\t\t\t");
            getch();
            break;

        }
        case 4:
        { // Delete Data

            if(*flag == 1 && S->count > 0) {
                SetConsoleTextAttribute(hConsole, CYAN);
                printf("\n\n\n\t\t\t\tWhat value would you like to remove?: ");
                SetConsoleTextAttribute(hConsole, YELLOW);
                scanf("%d", &x);
                removeAt(S, x);
            }
            else if(*flag == 1 && S->count == 0) { // Empty List
                SetConsoleTextAttribute(hConsole, LRED);
                printf("\n\n\n\t\t\t\tStatistician is empty!");
            }
            else {
                SetConsoleTextAttribute(hConsole, LRED);
                printf("\n\n\n\t\t\t\tError. Statistician does not exist.");
            }
            // Returning back to menu display.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\tPress any key to proceed to the main menu...\n\t\t\t\t\t\t");
            getch();
            break;

        }
        case 5:
        { // Display Statistics

            displayData(S, *flag);

            // Returning back to menu display.
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\tPress any key to proceed to the main menu...\n\t\t\t\t\t\t");
            getch();
            break;

        }
        case 6:
        { // Exit

            system("CLS");
            *menu -= 1;
            SetConsoleTextAttribute(hConsole, LBLUE);
            printf("\n\n\n\t\tTerminal Terminated.\n\n\n\n");
            SetConsoleTextAttribute(hConsole, YELLOW);
            break;

        }
        default:
        { // Invalid choices

            // Returning back to menu display.
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\n\t\t\t\tInvalid Input!");
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("\n\t\t\t\tPress any key to proceed to the main menu...\n\t\t\t\t\t\t");
            getch();
            break;

        }
    }
}
