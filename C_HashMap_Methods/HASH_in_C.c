
/*
*
*
*	Closed Hashing: Linear Probing
*
*
*/

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdint.h>
//#include <stdbool.h>
//
//
//#define nameSize 256
//#define tableSize 10
//#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)
//
//typedef struct {
//	char name[nameSize];
//	int age;
//}person;
//person *hashTable[tableSize];
//unsigned int hash(char *name) {
//	int length = strnlen(name, nameSize);
//	int i;
//	unsigned int hashValue = 0;
//	for(i = 0; i < length; i++) {
//		hashValue += name[i];
//		hashValue = hashValue * name[i] % tableSize;
//	}
//	return hashValue;
//}
//void nullifyHash() {
//	int i;
//	for(i = 0; i < tableSize; i++)
//		hashTable[i] = NULL;
//}
//void printHash() {
//	int i;
//	printf("START\n");
//	for(i = 0; i < tableSize; i++)
//	{
//		if(hashTable[i] == NULL)
//		{
//			printf("\t%i\t---\n", i);
//		}
//		else if(hashTable[i] == DELETED_NODE)
//		{
//			printf("\t%i\t---<deleted>\n", i);
//		}
//		else 
//		{
//			printf("\t%i\t%s\n", i, hashTable[i]->name);
//		}
//	}
//	printf("END\n");
//}
//bool insertHash(person *p) {
//	if(p == NULL)
//		return false;
//	int index = hash(p->name);
//	int i;
//	for(i = 0; i < tableSize; i++)
//	{
//		int TRY = (i + index) % tableSize;
//		if(hashTable[TRY] == NULL || hashTable[TRY] == DELETED_NODE)
//		{
//			hashTable[TRY] = p;
//			return true;
//		}
//	}
//	return false;
//}
//person *deleteHash(char *name) {
//	int index = hash(name);
//	int i;
//	for(i = 0; i < tableSize; i++)
//	{
//		int TRY = (index + i) % tableSize;
//		if(hashTable[TRY] == NULL)
//			return NULL;
//		if(hashTable[TRY] == DELETED_NODE)
//			continue;
//		if(strncmp(hashTable[TRY]->name, name, tableSize) == 0)
//		{
//			person *tmp = hashTable[TRY];
//			hashTable[TRY] = NULL;
//			return tmp;
//		}
//	}
//	
//	return NULL;
//}
//person * searchHash(char *name) {
//	int index = hash(name);
//	int i;
//	for(i = 0; i < tableSize; i++)
//	{
//		int TRY = (index + i) % tableSize;
//		if(hashTable[TRY] == NULL) {
//			return false;
//		}
//		if(hashTable[TRY] == DELETED_NODE)
//			continue;
//		if(strcmp(hashTable[TRY]->name,name) == 0)
//		{
//			return hashTable[TRY];
//		}
//	}	
//	return NULL;
//}
//
//void main() {
//	nullifyHash();
//	printHash();
//	getche();
//	system("CLS");
//	
//	insertHash("Jacob");
//	insertHash("Sydney");
//	insertHash("Mark");
//	insertHash("Joe");
//	insertHash("Aya");
//	insertHash("Holchi");
//	insertHash("Mohan");
//	insertHash("Myl");
//	insertHash("Juanite");
//	
//	printHash();
//	
//	person *temp = searchHash("Juanite");
//	if(temp == NULL)
//		printf("\n Not found.\n");
//	else
//		printf("\n %s was found.\n", temp->name);
//	
//	temp = searchHash("Myl");
//	if(temp == NULL)
//		printf("\n Not found.\n");
//	else
//		printf("\n %s was found.\n", temp->name);
//	
//	
//	getche();
//	system("CLS");
//	
//	deleteHash("Myl");
//	printHash();
//	return 0;
//}

/*
*
*
*	Closed Hashing: Quadratic Probing
*
*
*/

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdint.h>
//#include <stdbool.h>
//
//
//#define nameSize 256
//#define tableSize 10
//#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)
//
//typedef struct {
//	char name[nameSize];
//	int age;
//}person;
//person *hashTable[tableSize];
//unsigned int hash(char *name) {
//	int length = strnlen(name, nameSize);
//	int i;
//	unsigned int hashValue = 0;
//	for(i = 0; i < length; i++) {
//		hashValue += name[i];
//		hashValue = hashValue * name[i] % tableSize;
//	}
//	return hashValue;
//}
//void nullifyHash() {
//	int i;
//	for(i = 0; i < tableSize; i++)
//		hashTable[i] = NULL;
//}
//void printHash() {
//	int i;
//	printf("START\n");
//	for(i = 0; i < tableSize; i++)
//	{
//		if(hashTable[i] == NULL)
//		{
//			printf("\t%i\t---\n", i);
//		}
//		else if(hashTable[i] == DELETED_NODE)
//		{
//			printf("\t%i\t---<deleted>\n", i);
//		}
//		else 
//		{
//			printf("\t%i\t%s\n", i, hashTable[i]->name);
//		}
//	}
//	printf("END\n");
//}
//bool insertHash(person *p) {
//	if(p == NULL)
//		return false;
//	int index = hash(p->name);
//	int i;
//	for(i = 0; i < tableSize; i++)
//	{
//		int TRY = (i^2 + index) % tableSize;
//		if(hashTable[TRY] == NULL || hashTable[TRY] == DELETED_NODE)
//		{
//			hashTable[TRY] = p;
//			return true;
//		}
//	}
//	return false;
//}
//person *deleteHash(char *name) {
//	int index = hash(name);
//	int i;
//	for(i = 0; i < tableSize; i++)
//	{
//		int TRY = (index + i) % tableSize;
//		if(hashTable[TRY] == NULL)
//			return NULL;
//		if(hashTable[TRY] == DELETED_NODE)
//			continue;
//		if(strncmp(hashTable[TRY]->name, name, tableSize) == 0)
//		{
//			person *tmp = hashTable[TRY];
//			hashTable[TRY] = NULL;
//			return tmp;
//		}
//	}
//	
//	return NULL;
//}
//person * searchHash(char *name) {
//	int index = hash(name);
//	int i;
//	for(i = 0; i < tableSize; i++)
//	{
//		int TRY = (index + i) % tableSize;
//		if(hashTable[TRY] == NULL) {
//			return false;
//		}
//		if(hashTable[TRY] == DELETED_NODE)
//			continue;
//		if(strcmp(hashTable[TRY]->name,name) == 0)
//		{
//			return hashTable[TRY];
//		}
//	}	
//	return NULL;
//}
//
//void main() {
//	nullifyHash();
//	printHash();
//	getche();
//	system("CLS");
//	
//	insertHash("Jacob");
//	insertHash("Sydney");
//	insertHash("Mark");
//	insertHash("Joe");
//	insertHash("Aya");
//	insertHash("Holchi");
//	insertHash("Mohan");
//	insertHash("Myl");
//	insertHash("Juanite");
//	
//	printHash();
//	
//	person *temp = searchHash("Juanite");
//	if(temp == NULL)
//		printf("\n Not found.\n");
//	else
//		printf("\n %s was found.\n", temp->name);
//	
//	temp = searchHash("Myl");
//	if(temp == NULL)
//		printf("\n Not found.\n");
//	else
//		printf("\n %s was found.\n", temp->name);
//	
//	
//	getche();
//	system("CLS");
//	
//	deleteHash("Myl");
//	printHash();
//	return 0;
//}

/*
*
*
*	Closed Hashing: Double Hashing
*
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


#define nameSize 256
#define tableSize 10
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct {
	char name[nameSize];
	int age;
}person;
person *hashTable[tableSize];
unsigned int hash(char *name) {
	int length = strnlen(name, nameSize);
	int i;
	unsigned int hashValue = 0;
	for(i = 0; i < length; i++) {
		hashValue += name[i];
		hashValue = hashValue * name[i] % tableSize;
	}
	return hashValue;
}

void nullifyHash() {
	int i;
	for(i = 0; i < tableSize; i++)
		hashTable[i] = NULL;
}
void printHash() {
	int i;
	printf("START\n");
	for(i = 0; i < tableSize; i++)
	{
		if(hashTable[i] == NULL)
		{
			printf("\t%i\t---\n", i);
		}
		else if(hashTable[i] == DELETED_NODE)
		{
			printf("\t%i\t---<deleted>\n", i);
		}
		else 
		{
			printf("\t%i\t%s\n", i, hashTable[i]->name);
		}
	}
	printf("END\n");
}

bool isPrime(int R) {
    if(R <= 1) return false;
    if(R == 2 || R == 3) return true;
    if(R % 2 == 0 || R % 3 == 0) return false;
    int i = 5;
    while(i * i <= R) {
        if(R % i == 0 || R % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}
int h1(int k) {
	return k % tableSize;
}
int h2(int R, int k) {
	return R - (k % R);
}

bool insertHash(person *p) {
    if(p == NULL)
        return false;
    int index = hash(p->name);
    int i;
    int currentPrime = tableSize - 1;
    for(i = 0; i < tableSize; i++) {
        for(; currentPrime > 0; currentPrime--) {
            if(isPrime(currentPrime)) break;
        }
        int TRY = (h1(index) + i * h2(currentPrime, index)) % tableSize;
        if(hashTable[TRY] == NULL || hashTable[TRY] == DELETED_NODE) {
            hashTable[TRY] = p;
            return true;
        }
    }
    return false; 
}


person * deleteHash(char *name) {
    int index = hash(name);
    int i;
    for(i = 0; i < tableSize; i++) {
        int TRY = (index + i * h2(index, i)) % tableSize;
        if(hashTable[TRY] == NULL) {
            return NULL; 
        }
        if(strcmp(hashTable[TRY]->name, name) == 0) {
            person *tmp = hashTable[TRY];
            hashTable[TRY] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL; 
}

person * searchHash(char *name) {
    int index = hash(name);
    int i;
    int currentPrime = tableSize - 1;
    for(i = 0; i < tableSize; i++) {
        for(; currentPrime > 0; currentPrime--) {
            if(isPrime(currentPrime)) break;
        }
        int TRY = (h1(index) + i * h2(currentPrime, index)) % tableSize;
        if(hashTable[TRY] == NULL) {
            return NULL;
        }
        if(hashTable[TRY] == DELETED_NODE) {
            continue;
        }
        if(strcmp(hashTable[TRY]->name, name) == 0) {
            return hashTable[TRY];
        }
    }   
    return NULL;
}


void main() {
	nullifyHash();
	printHash();
	getche();
	system("CLS");
	
	person p1 = {"Jacob", 24};
	person p2 = {"Sydney", 21};
	person p3 = {"Mark", 32};
	person p4 = {"Joe", 47};
	person p5 = {"Aya", 19};
	person p6 = {"Holchi", 27};
	person p7 = {"Mohan", 42};
	person p8 = {"Myl", 38};
	person p9 = {"Juanite", 55};
	
	insertHash(&p1);
	insertHash(&p2);
	insertHash(&p3);
	insertHash(&p4);
	insertHash(&p5);
	insertHash(&p6);
	insertHash(&p7);
	insertHash(&p8);
	insertHash(&p9);
	
	printHash();
	
	person *temp = searchHash("Juanite");
	if(temp == NULL)
		printf("\n Not found.\n");
	else
		printf("\n %s was found.\n", temp->name);
	
	temp = searchHash("Myl");
	if(temp == NULL)
		printf("\n Not found.\n");
	else
		printf("\n %s was found.\n", temp->name);
	
	
	getche();
	system("CLS");
	
	deleteHash("Myl");
	printHash();
}

/*
*
*
*	Open Hash: Block Chaining
*
*
*/

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdint.h>
//#include <stdbool.h>
//
//// Hash Block Chaining
//
//#define nameSize 256
//#define tableSize 10
//
//typedef struct person{
//	char name[nameSize];
//	int age;
//	struct person *next;
//}person;
//person *hashTable[tableSize];
//unsigned int hash(char *name) {
//	int length = strnlen(name, nameSize);
//	int i;
//	unsigned int hashValue = 0;
//	for(i = 0; i < length; i++) {
//		hashValue += name[i];
//		hashValue = hashValue * name[i] % tableSize;
//	}
//	return hashValue;
//}
//void nullifyHash() {
//	int i;
//	for(i = 0; i < tableSize; i++)
//		hashTable[i] = NULL;
//}
//void printHash() {
//	int i;
//	printf("START\n");
//	for(i = 0; i < tableSize; i++)
//	{
//		if(hashTable[i] == NULL)
//		{
//			printf("\t%i\t---\n", i);
//		}
//		else 
//		{
//			printf("\t%i\t", i);
//			person *tmp = hashTable[i];
//			while(tmp != NULL)
//			{
//				printf("%s -> ", tmp->name);
//				tmp = tmp->next;
//			}
//			printf("\n");
//		}
//	}
//	printf("END\n");
//}
//bool insertHash(person *p) {
//	if(p == NULL) return false;
//	int index = hash(p->name);
//	p->next = hashTable[index];
//	hashTable[index] = p;
//	return true;
//}
//person *deleteHash(char *name) {
//	int index = hash(name);
//	person *tmp = hashTable[index];
//	person *prev = NULL;
//	while(tmp != NULL && strncmp(tmp->name,name,nameSize) != 0) {
//		prev = tmp;
//		tmp = tmp->next;
//	}
//	if(tmp == NULL)
//		return NULL;
//	if(prev == NULL) 
//	{
//		hashTable[index] = tmp->next;
//	}
//	else 
//	{
//		prev->next = tmp->next;
//	}
//	return tmp;
//}
//person * searchHash(char *name) {
//	int index = hash(name);
//	person *tmp = hashTable[index];
//	while(tmp != NULL && strncmp(tmp->name,name,nameSize) != 0) {
//		tmp = tmp->next;
//	}
//	return tmp;
//}
//
//void main() {
//	nullifyHash();
//	printHash();
//	getche();
//	system("CLS");
//	
//	person jacob = {.name="Jacob", .age ="17"};
//	person myl = {.name="myl", .age ="20"};
//	person mohan = {.name="mohan", .age ="21"};
//	person josh = {.name="josh", .age ="20"};
//	person holchi = {.name="holchi", .age ="20"};
//	person juanite = {.name="juanite", .age ="21"};
//	person rodjean = {.name="rodjean", .age ="20"};
//	person reo = {.name="reo", .age ="20"};
//	person liwag = {.name="liwag", .age ="89"};
//	person alvin = {.name="alvin", .age ="97"};
//	
//	insertHash(&jacob);
//	insertHash(&myl);
//	insertHash(&mohan);
//	insertHash(&josh);
//	insertHash(&holchi);
//	insertHash(&juanite);
//	insertHash(&rodjean);
//	insertHash(&reo);
//	insertHash(&liwag);
//	insertHash(&alvin);
//	
//	printHash();
//	
//	person *temp = searchHash("liwag");
//	if(temp == NULL)
//		printf("\n Not found.\n");
//	else
//		printf("\n %s was found.\n", temp->name);
//	
//	temp = searchHash("mohan");
//	if(temp == NULL)
//		printf("\n Not found.\n");
//	else
//		printf("\n %s was found.\n", temp->name);
//	
//	
//	getche();
//	system("CLS");
//	
//	deleteHash("liwag");
//	deleteHash("mohan");
//	printHash();
//	return 0;
//}
