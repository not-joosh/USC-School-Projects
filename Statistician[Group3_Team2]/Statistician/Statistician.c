/*
================================================================================
FILE        : Statistician.c
AUTHORS     : Holchi Henchi Alin, John Myl B. Alinsonorin, Mohan Nuelle Francis,
              & Josh Bobier Ratificar,
DESCRIPTION : Contains functions that are designed to create list, delete list, add data,
              remove data, compute statistical traits, and display the information in
              in the a list.
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
#include <math.h>
#include "Statistician.h"
/*
================================================================================
FUNCTION    : newStatistician
DESCRIPTION : updates flag when necessary and creates a new
              Statistician according to flag condition
ARGUMENTS   : STAT *S, int *flag
RETURNS     : STAT S - returns empty statistician.
================================================================================
*/
STAT * newStatistician(STAT *S, int *flag) {
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	if(*flag == statExists) {
        SetConsoleTextAttribute(hConsole, LRED);
        printf("\n\n\n\t\t\t\tError. Please delete current Statistician.");
        return S;
	}
	else {
		STAT *S = (STAT *)malloc(sizeof(STAT));
		S->head = NULL;
		S->tail = NULL;
		S->count = 0;
		SetConsoleTextAttribute(hConsole, LBLUE);
		printf("\n\n\n\t\t\t\tSuccess! Statistician has been created.");
		*flag = 1;
		return S;
	}
}
/*
================================================================================
FUNCTION    : destroyStatistician
DESCRIPTION : updates flag when necessary and destroys current
              Statistician according to flag condition.
ARGUMENTS   : STAT *S, int *flag
RETURNS     : void - does not return anything.
================================================================================
*/
void destroyStatistician(STAT *S, int *flag) {
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	if(*flag == statExists) {
        if(S->count > 0) {
            NODE *ptr = S->tail;
            while(ptr->prev != S->head->prev) {
                NODE *temp = ptr;
                S->tail = ptr->prev;
                S->tail->next = NULL;
                free(temp);
                S->count--;
                ptr = ptr->prev;
            }
            free(ptr);
            S->head = NULL;
            S->tail = NULL;
            S->count--;
        }
        *flag = 0;
		SetConsoleTextAttribute(hConsole, LBLUE);
		printf("\n\n\n\t\t\t\tSuccess! Destroyed Statistician");
	}
	else {
        SetConsoleTextAttribute(hConsole, LRED);
		printf("\n\n\n\t\t\t\tError. Statistician does not exist.");
	}
}
/*
================================================================================
FUNCTION    : add
DESCRIPTION : Adds a value selected by the user into the list in a sorted
              order. Computes for each statistics value at the very end.
ARGUMENTS   : STAT *S, int x
RETURNS     : void - does not return anything
================================================================================
*/
void add(STAT *S, int x) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    NODE *ptr = S->head;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(S->count == 0) {
        S->head = newNode;
        S->tail = newNode;
        S->count++;
    }
    else if(ptr->data >= newNode->data) {//insert at head
        newNode->next = S->head;
        S->head->prev = newNode;
        S->head = newNode;
        S->count++;
    }
    else {
        while (ptr->data <= newNode->data && ptr->next != NULL) {
            ptr = ptr->next;
        }
        if(ptr->next == NULL && ptr->data <= newNode->data) { //insert at tail
            newNode->next = NULL;
            newNode->prev = S->tail;
            S->tail->next = newNode;
            S->tail = newNode;
            S->count++;
        }
        else {
            newNode->next = ptr;
            newNode->prev = ptr->prev;
            ptr->prev->next = newNode;
            ptr->prev = newNode;
            S->count++;
        }
    }
    // Compute Statistics
    computeStats(S);
}
/*
================================================================================
FUNCTION    : removeAt
DESCRIPTION : Removes a value selected by the user into the list. Computes for
              each statistics value at the very end.
ARGUMENTS   : STAT *S, int x
RETURNS     : void - does not return anything
================================================================================
*/
void removeAt(STAT *S, int x){
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    NODE *temp = S->head;
    if (temp->data == x && S->count > 1){ // If value is the Head node
		S->head = temp->next;
		S->head->prev = NULL;
       	free(temp);
        S->count--;
    }
    else if(temp->data == x && S->count == 1) { // If Only one node in Stat
        free(temp);
        S->head = NULL;
        S->tail = NULL;
        S->count--;
    }
	else {
		while(temp->data != x && temp->next != NULL) {
			temp = temp->next;
		}
		if(temp->next == NULL && temp->data == x) { // If value is at the tail
			S->tail = temp->prev;
			S->tail->next = NULL;
            free(temp);
            S->count--;
		}
		else if(temp->data == x) { //Succeeding Nodes
			temp->next->prev = temp->next->prev->prev;
            temp->prev->next = temp->prev->next->next;
			free(temp);
			S->count--;
		}
		else { // value not in list
            SetConsoleTextAttribute(hConsole, LRED);
            printf("\t\t\t\t%d is not in the statistician", x);
		}
	}
	computeStats(S);
}
/*
================================================================================
FUNCTION    : computeStats
DESCRIPTION : Calls major statistic calculation functions all at once to update
              their values in the current state of the Statistician. Stores the value
              updates into the STAT structure.
ARGUMENTS   : STAT *S
RETURNS     : void - does not return anything
================================================================================
*/
void computeStats(STAT *S) {
    if(S->count > 0) {
        S->minimum = minimum(S);
        S->maximum = maximum(S);
        S->range = range(S);
        S->sum = sum(S);
        S->mean = mean(S);
        S->median = median(S);

        S->mode = mode(S);
        S->variance = variance(S);
        S->standardDeviation = stdeviation(S);
    }
}
/*
================================================================================
FUNCTION    : minimum
DESCRIPTION : Computes for the minimum data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : int min - returns the minimum value.
================================================================================
*/
int minimum(STAT *S) {
    int min = S->head->data;
    return min;
}
/*
================================================================================
FUNCTION    : maximum
DESCRIPTION : Computes for the maximum data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : int max - returns the maximum value.
================================================================================
*/
int maximum(STAT *S) {
    int max = S->tail->data;
    return max;
}
/*
================================================================================
FUNCTION    : range
DESCRIPTION : Computes for the range data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : int range - returns the range value.
================================================================================
*/
int range(STAT *S) {
    int range = S->maximum - S->minimum;
    return range;
}
/*
================================================================================
FUNCTION    : sum
DESCRIPTION : Computes for the sum data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : int sum - returns the sum value.
================================================================================
*/
int sum(STAT *S) {
    NODE *ptr = S->head;
    int sum = 0;
    while(ptr->next != NULL) { // Computing Sum
        sum += ptr->data;
        ptr = ptr->next;
    }
    sum += ptr->data;
    return sum;
}
/*
================================================================================
FUNCTION    : mean
DESCRIPTION : Computes for the mean data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : float mean - returns the mean value.
================================================================================
*/
float mean(STAT *S) {
    float mean = (float)S->sum/(float)S->count;
    return mean;
}
/*
================================================================================
FUNCTION    : median
DESCRIPTION : Computes for the median data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : float median - returns the median value.
================================================================================
*/
float median(STAT *S) {
    float median;
    int i = 0;
    if(S->count == 1) {
        median = (float)S->head->data;
    }
    else {
        float pos = (float)S->count / (float)2;
        NODE *ptr1 = S->head;
        if(S->count % 2 == 0) { // for Even Count, compute median
            while(i < pos - 1) {
                ptr1 = ptr1->next;
                i++;
            }
            NODE *ptr2 = ptr1->next;
            median = ((float)ptr1->data + (float)ptr2->data)/(float)2; // final Formula
        }
        else { // For Odd Count, computes Median
            while(i < round(pos)-1) {
                ptr1 = ptr1->next;
                i++;
            }
            median = (float)ptr1->data;
        }
    }
    return median;
}
/*
================================================================================
FUNCTION    : variance
DESCRIPTION : Computes for the variance data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : float variance - returns the variance value.
================================================================================
*/
float variance(STAT *S){
    int i;
    float variance, sum = 0;
    NODE *ptr = S->head;
    for(i=0;i<S->count;i++){
        sum = sum + pow((ptr->data - S->mean), 2);
        ptr = ptr->next;
    }
    variance = sum/(S->count);
    return variance;
}
/*
================================================================================
FUNCTION    : stdeviation
DESCRIPTION : Computes for the Standard deviation data of NODES in the Statistician.
ARGUMENTS   : STAT *S
RETURNS     : float deviation - returns the Standard deviation value.
================================================================================
*/
float stdeviation(STAT *S){
    float deviation;
    deviation = sqrt(S->variance);
    return deviation;
}
/*
================================================================================
FUNCTION    : mode
DESCRIPTION : Computes for the Standard mode data of NODES in the Statistician.
              It as well stores a modeCount.
ARGUMENTS   : STAT *S
RETURNS     : int mode - returns the mode value.
================================================================================
*/
int mode(STAT *S){
    int value = 0, mode = 0, count = 1, tempCount = 1;
    NODE *ptr = S->head;

    while(ptr->next != NULL){
        ptr = ptr->next;
        if(ptr->data == ptr->prev->data){
            tempCount++;
        }
         else{
            tempCount = 1;
        }
        if (count<tempCount){
            mode = ptr->data;
            count = tempCount;
        }
    }
    S->modeCount = count;
    return mode;
}
/*
================================================================================
FUNCTION    : displayData
DESCRIPTION : Displays the NODES inside of a given Statistician. Requires flag to
              check if the Statistician exists or not.
ARGUMENTS   : STAT *S, int flag;
RETURNS     : void - no return.
================================================================================
*/
void displayData(STAT *S, int flag) {
    // Terminal Coloring for UNIX
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

	if(flag == 1) {
		if(S->count == 0) {
            SetConsoleTextAttribute(hConsole, LRED);
			printf("\n\n\n\t\t\t\tStatistician is empty!");
		}
		else {
			NODE *ptr = S->head;
            SetConsoleTextAttribute(hConsole, CYAN );
			printf("\n\n\n\t\t\t\tSTATISTICIAN DATA  :");
			while(ptr != NULL) {
                SetConsoleTextAttribute(hConsole, YELLOW);
				printf(" %d", ptr->data);
				ptr = ptr->next;
			}
			// Display Statistics here below here.
            // min
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tMinimum            : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("%d", S->minimum);
            // max
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tMaximum            : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            printf("%d", S->maximum);
            // Range
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tRange              : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            if(S->count == 1) {
                printf("N/A");
            }
            else
                printf("%d", S->range);
            // Mean
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tMean(Average)      : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            if((int)S->mean == (float)S->mean) {
                printf("%.0f", S->mean);

            }
            else {
                printf("%.12f", S->mean);
            }
            // Median
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tMedian             : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            if((int)S->median == (float)S->median) {
                printf("%.0f", S->median);
            }
            else {
                printf("%.12f", S->median);
            }
            // Mode
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tMode               : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            if (S->modeCount==1){
                printf("All numbers appeared once.");
            }
            else{
                printMode(S);
                printf("appeared %d times.", S->modeCount);
            }
            // Variance
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tVariance           : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            if((int)S->variance == (float)S->variance) {
                printf("%.0f", S->variance);
            }
            else {
                printf("%.12f", S->variance);
            }

            // Standard Deviation
            SetConsoleTextAttribute(hConsole, CYAN);
            printf("\n\t\t\t\tStandard deviation : ");
            SetConsoleTextAttribute(hConsole, YELLOW);
            if((int)S->standardDeviation == (float)S->standardDeviation) {
                printf("%.0f", S->standardDeviation);
            }
            else {
                printf("%.12f", S->standardDeviation);
            }
		}
		printf("\n");
	}
	else {
        SetConsoleTextAttribute(hConsole, LRED);
		printf("\n\n\n\t\t\t\tError. Statistician does not exist.");
	}
}
/*
================================================================================
FUNCTION    : printMode
DESCRIPTION : Function handles bimodal conditions. If there are more than one
              modes, the function will print all the possible modes.
ARGUMENTS   : STAT *S
RETURNS     : void - no return.
================================================================================
*/
void printMode(STAT *S) {
    int x, tempCount = 1, i = 0;
    int modeArr[tempCount];

    NODE *ptr2 = S->head;

    while(ptr2->next != NULL){
        ptr2 = ptr2->next;
        if(ptr2->data == ptr2->prev->data){
            tempCount++;
        }
        if (tempCount == S->modeCount){
            i++;
            modeArr[i] = ptr2->data;
            printf("%d, ", modeArr[i]);
            tempCount = 1;
        }
    }
}
