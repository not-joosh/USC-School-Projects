/*
================================================================================
FILE        : search.c
AUTHORS     : Paul Corsino, Ivan Galicia, and Josh Ratificar
DESCRIPTION : Contains instructions to function prototypes to handle a
              creation of a list, destruction of a list, sorting of a list,
              searching, and displaying a list.
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
FUNCTION    : nullifyList
DESCRIPTION : Sets a LIST's tail, head, and count to their respective
              default values.
ARGUMENTS   : LIST *L
RETURNS     : void - does not return anything
================================================================================
*/
void nullifyList(LIST *L) {
	L->count = 0;
	L->tail = NULL;
	L->head = NULL;
}
/*
================================================================================
FUNCTION    : createList
DESCRIPTION : Determines whether or not a List is currently active. If it is
              not active, then the program will create a new list and update
              the flag. Otherwise, it will stop the creation of a new list.
ARGUMENTS   : LIST *L, int *flag
RETURNS     : LIST * - returns an empty List.
================================================================================
*/
LIST * createList(LIST *L, int *flag) {
    // Unix Terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*flag == 0) { // If list does not exist.
        LIST *L = (LIST *)malloc(sizeof(LIST));
        nullifyList(L);
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\n\t\t\t\t    List successfully generated!");
        generateNum(L);
        *flag = 1;
        return L;
    }
    else { // If there is an active list.
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t\t    Please destroy current list.");
        return L;
    }
}
/*
================================================================================
FUNCTION    : generateNum
DESCRIPTION : Generates 10 random integers and appends them into a
              doubly linked list.
ARGUMENTS   : LIST *L
RETURNS     : void - does not return anything
================================================================================
*/
void generateNum(LIST *L) {
    int i, n;
    time_t t;
	srand((unsigned) time(&t));
    for(i = 0; i < 10; i++) {
		n = rand() % 101;
		appendRear(L, n);
	}
}
/*
================================================================================
FUNCTION    : appendRear
DESCRIPTION : Adds a value at the end of a doubly linked list.
ARGUMENTS   : LIST *L, int x
RETURNS     : void - does not return anything
================================================================================
*/
void appendRear(LIST *L, int x) {
	// Creating empty node with stored value.
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	if(L->count == 0) { // If list empty.
		L->head = newNode;
		L->tail = newNode;
		L->count++;
	}
	else { // Succeeding Nodes.
		NODE *ptr = L->tail;
		newNode->prev = ptr;
		ptr->next = newNode;
		L->tail = newNode;
		L->count++;
	}
}
/*
================================================================================
FUNCTION    : destroyList
DESCRIPTION : If a list exists, then this function will destroy that list
              and reset the flag and sort flag. The program will go through each
              node and free them until the list is empty.
ARGUMENTS   : LIST *L, int *flag, int *sortFlag
RETURNS     : void - does not return anything
================================================================================
*/
void destroyList(LIST *L, int *flag, int *sortFlag){
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	if(*flag == 1) { // If List Exists
        if(L->count > 0) { // Travels through each node and frees them.
            NODE *ptr = L->tail;
            while(ptr->prev != L->head->prev) {
                NODE *temp = ptr;
                L->tail = ptr->prev;
                L->tail->next = NULL;
                free(temp);
                L->count--;
                ptr = ptr->prev;
            }
            free(ptr);
            L->head = NULL;
            L->tail = NULL;
            L->count--;
        }
        *sortFlag = 0;
        *flag = 0;
        free(L);
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\n\t\t\t\t    List successfully destroyed!");
	}
	else {
		SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t\t         List does not exist.");
	}
}
/*
================================================================================
FUNCTION    : shellSort
DESCRIPTION : This function will sort the doubly linked list in ascending order
              by using a nodal structure implementation of Shell Sort. If list is
              already sorted, then it will refuse the user of services.
ARGUMENTS   : LIST *L, int *sortFlag, int *flag
RETURNS     : void - does not return anything
================================================================================
*/
void shellSort(LIST *L, int *sortFlag, int *flag) {
    // Unix Terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*sortFlag == 0 && *flag == 1) { // If List exists and is not sorted
        int gap, temp, j, i, travelLeft, travelRight;
        NODE *leftPtr, *gapPtr;
        for(gap = L->count/2; gap > 0; gap /= 2) { // Decrementing Gap Iteratively
            for(j = gap; j < L->count; j++) {
                for(gapPtr = L->head, travelRight = 0; travelRight < j; travelRight++, gapPtr = gapPtr->next); // Traveling to gap position
                for(leftPtr = gapPtr, travelLeft = 0; travelLeft < gap; travelLeft++,leftPtr = leftPtr->prev); // Traveling left by "gap" amount
                NODE *tempPtr = gapPtr;
                temp = gapPtr->data;
                for(i = j; i >= gap && leftPtr->data >= temp; i -= gap) { // Sorting
                    tempPtr->data = leftPtr->data;
                    tempPtr = leftPtr;
                    if(i - gap >= gap)
                        for(travelLeft = 0; travelLeft < gap; travelLeft++, leftPtr = leftPtr->prev);
                }
                tempPtr->data = temp;
            }
        }
        *sortFlag = 1;
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\n\t\t\t\t    List successfully sorted!");
	}
	else if(*flag == 1 && *sortFlag == 1) { // List is already sorted.
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t\t         List already sorted.");
	}
	else { // List does not exist
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t\t         List does not exist.");
	}
}
/*
================================================================================
FUNCTION    : binarySearch
DESCRIPTION : If the list is sorted, then this program will binary search
              through the linked list.
ARGUMENTS   : LIST *L, int *flag, int *sortFlag
RETURNS     : void - does not return anything
================================================================================
*/
void binarySearch(LIST *L, int *flag, int *sortFlag) {
    // Unix Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*flag == 1 && *sortFlag == 1) { // List Exists and is sorted
        // Initializing Variables
        int index = 0, end = L->count - 1, begin = 0, mid, i, x, searchFlag = 0, travelUp = 0;
        NODE *ptr;
        // Prompt user for data to search.
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\n\t\t\t\t\tWhat value?: ");
        SetConsoleTextAttribute(hConsole, YELLOW);
        scanf("%d", &x);
        // Binary Search
        while(begin <= end) {
            mid = (begin + end) / 2;
            for(ptr = L->head, travelUp = 0; travelUp < mid; ptr = ptr->next, travelUp++);
            if(ptr->data < x) {
                begin = mid + 1;
            }
            else if(ptr->data > x) {
                end = mid - 1;
            }
            else {
                begin = end + 1;
                searchFlag = 1;
                index = mid;
            }
        }
        // Print out Index found if found
        displayIndex(searchFlag , x, index);
    }
    else if(*sortFlag == 0 && *flag == 1) {
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t      Please sort list before Binary Searching.");
    }
    else { // List does not exist
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t\t         List does not exist.");
    }
}
/*
================================================================================
FUNCTION    : linearSearch
DESCRIPTION : This function will evaluate a sorted or unsorted linked list to
              see if prompted value is found!
ARGUMENTS   : LIST *L, int *flag
RETURNS     : void - does not return anything
================================================================================
*/
void linearSearch(LIST *L, int *flag) {
    // Unix Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(*flag == 1) { // If List Exists
        // Initializing Variables
        int x, searchFlag = 0, index = 0;

        // Prompt user for data to search.
        SetConsoleTextAttribute(hConsole, CYAN);
        printf("\n\n\t\t\t\t\tWhat value?: ");
        SetConsoleTextAttribute(hConsole, YELLOW);
        scanf("%d", &x);

        // Node linear search
        NODE *ptr = L->head;
        while(ptr->data != x && ptr->next != NULL) {
            ptr = ptr->next;
            index++;
        }
        if(ptr->data == x) {
            searchFlag = 1;
        }
        displayIndex(searchFlag , x, index);
    }
    else {
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t\t         List does not exist.");
    }
}
/*
================================================================================
FUNCTION    : displayIndex
DESCRIPTION : Takes the searchFlag, x(value to search for), and index to display
              whether the integer exists in the doubly linked list.
ARGUMENTS   : int searchFlag, int x, int index
RETURNS     : void - does not return anything
================================================================================
*/
void displayIndex(int searchFlag, int x, int index) {
    // Unix Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	if(searchFlag == 0) { // If Number does not Exist
        SetConsoleTextAttribute(hConsole, LRED);
		printf("\t\t\t\t        %d was not found!", x);
	}
	else if(searchFlag == 1) { // If Number does Exist
        SetConsoleTextAttribute(hConsole, LBLUE);
		printf("\t\t\t\t        %d was found at index %d!", x, index);
	}
}
/*
================================================================================
FUNCTION    : displayList
DESCRIPTION : This function will go through each node in a list and display its
              data until the pointer exhausts the entire list.
ARGUMENTS   : LIST *L, int flag
RETURNS     : void - does not return anything
================================================================================
*/
void displayList(LIST *L, int flag) {
    // Unix Terminal Coloring
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    if(flag == 1) { // If List Exists
        NODE *ptr = L->head;
        SetConsoleTextAttribute(hConsole, LBLUE);
        printf("\n\n\t\t\t\t  LIST: ");
        while(ptr != NULL) {
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else { // List does not exist
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\t\t\t\t         List does not exist.");
    }
}
