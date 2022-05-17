 /*======================================================================================================
FILE        : main.c
AUTHOR      : Josh B. Ratificar, Paolo Jansen A. Enrera, Mohan Nuelle T. Francis, & Rhett Joshua L. Surban.
DESCRIPTION : Holds the instructions to further perform AVL Binary Tree operations.
COPYRIGHT   : 10 May 2022
REVISION HISTORY
Date: 			By: 		Description:

======================================================================================================*/
/*==============================================================================
Header Files
==============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AVL.h"
/*==============================================================================
FUNCTION    : main
DESCRIPTION : Execute the main program that displays a menu and handles a set of instructions
              for AVL. Instructs for RR, RL, LR, and LL AVL tree rotations & node
              removals.
ARGUMENTS   :
RETURNS     : void
==============================================================================*/
void main() {

    // Initialize root and variables
    NODE *root;
    int key;
    bool success;

    /*////////////////////////////////////////
    *
    * Right to Right Rotation Test Case
    *
    */

    printf("\n\nRight to Right Rotation: Inserting 20, 10, 30, 40... deleting 10 & 4\n\n");

    // Inserting Nodes to Tree
    root = NULL;
    key = 20;
    root = insertAVL(root, key);

    key = 10;
    root = insertAVL(root, key);

    key = 30;
    root = insertAVL(root, key);

    key = 40;
    root = insertAVL(root, key);

    traversals(root); // Print Tree before Deletion

    // Deleting "10" from Tree
	key = 10, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion

    key = 4, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion


    printf("\n\nPress a key to proceed...");
	getche();
	system("CLS");

    /*////////////////////////////////////////
    *
    * Right to Left Rotation Test Case
    *
    */
    printf("\n\nRight to Left Rotation: Inserting 20, 10, 40, 30... deleting 10 & 4\n\n");
    // Inserting Nodes to Tree
    root = NULL;
    key = 20;
    root = insertAVL(root, key);

    key = 10;
    root = insertAVL(root, key);

    key = 40;
    root = insertAVL(root, key);

    key = 30;
    root = insertAVL(root, key);

    traversals(root); // Print Tree before Deletion

    // Deleting "10" from Tree
	key = 10, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion

    key = 4, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion


    printf("\n\nPress a key to proceed...");
	getche();
	system("CLS");

	/*////////////////////////////////////////
    *
    * Left to Left Rotation Test Case
    *
    */
    printf("\n\nLeft to Left Rotation: Inserting 30, 20, 40, 10... deleting 40 & 4\n\n");
    // Inserting Nodes to Tree
    root = NULL;
    key = 30;
    root = insertAVL(root, key);

    key = 20;
    root = insertAVL(root, key);

    key = 40;
    root = insertAVL(root, key);

    key = 10;
    root = insertAVL(root, key);

    traversals(root); // Print Tree before Deletion

    // Deleting "10" from Tree
	key = 40, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion

    key = 4, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion


    printf("\n\nPress a key to proceed...");
	getche();
	system("CLS");

	/*////////////////////////////////////////
    *
    * Left to Right Rotation Test Case
    *
    */

    printf("\n\nLeft to Right Rotation: Inserting 30, 10, 40, 20... deleting 40 & 4\n\n");
    // Inserting Nodes to Tree
    root = NULL;
    key = 30;
    root = insertAVL(root, key);

    key = 10;
    root = insertAVL(root, key);

    key = 40;
    root = insertAVL(root, key);

    key = 20;
    root = insertAVL(root, key);

    traversals(root); // Print Tree before Deletion

    // Deleting "10" from Tree
	key = 40, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion

    key = 4, success = false;
	root = deleteAVL(root, key, &success);
	searchResult(key, success);
	traversals(root); // Print Tree after Deletion


    printf("\n\nPress a key to proceed...");
	getche();
	system("CLS");

    return 0;
}

