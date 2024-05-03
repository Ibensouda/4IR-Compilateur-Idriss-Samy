#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TDS 128
#define MAX_NAME_LENGTH 50
static int scopeG = 0;

typedef struct stack
{
    struct stack * precedent;
    char name[MAX_NAME_LENGTH];   
    int scope;   
    int address;   
    int value;
} SymbolStack;

int id = 0;
SymbolStack * myStack = NULL;
//Symbol tds[MAX_TDS];

void incrementerS() {scopeG++;}
void decrementerS() {scopeG--;}


void createSymbolTmp(char * nameParam, int val) 
{
    int precedent;
    precedent = 0;
    if (precedent != -1) {
        SymbolStack * stackP = myStack;
        SymbolStack * stackN = NULL;
        stackN = malloc(sizeof(SymbolStack));
        strcpy(stackN->name, nameParam);
        stackN->scope = scopeG;
        stackN->precedent = stackP;
        stackN->address = id;
        stackN->value = val;
        //printf("%d, %s\n", stackN->address, stackN->name);
        myStack = stackN;
        id++;
    }
}
int searchSymbol(char * nameSearch) 
{
    int result = -1;
    if (myStack != NULL) {
        SymbolStack * tmpStack = myStack;
        while (tmpStack != NULL) {
            if (strcmp(tmpStack->name, nameSearch) == 0) {
                result = tmpStack->address;
                break;
            }
            tmpStack = (tmpStack)->precedent;
        }
    }
    return result;
    // for (int j=0; j<MAX_TDS; j++)
    // {
    //     if (strcmp(tds[j].name, namesearch) == 0)
    //     {
    //         return j;
    //     }
    // }
}
void createSymbol(char * nameParam) 
{
    int precedent;
    precedent = 0;
    if (precedent != -1 && searchSymbol(nameParam) == -1) {
        SymbolStack * stackP = myStack;
        SymbolStack * stackN = NULL;
        stackN = malloc(sizeof(SymbolStack));
        strcpy(stackN->name, nameParam);
        stackN->scope = scopeG;
        stackN->precedent = stackP;
        stackN->address = id;
        //printf("%d, %s\n", stackN->address, stackN->name);
        myStack = stackN;
        id++;
    }
    // if (id < MAX_TDS) {
    //     printf("%s %d\n", name, scopeG);
    //     strcpy(tds[id].name, name);
    //     printf("%s\n", tds[id].name);
    //     tds[id].type = type;
    //     tds[id].scope = scope;
    //     id++;
    // }
}
void deleteSymboltmp() {
    if (myStack != NULL) {
        SymbolStack * stackP = myStack;
        SymbolStack * stackN = myStack->precedent;
        id--;
        free(myStack);
        myStack = stackN;
    }
}

SymbolStack * getLastSymbol(){
    return myStack;
}

void printStack() {
    if (myStack != NULL) {
        SymbolStack * tmpStack = myStack;
        printf("---------------------Etat de la pile----------------------\n");
        while (tmpStack->precedent != NULL) {
            printf("%d, %s\n", tmpStack->address, tmpStack->name);
            tmpStack = tmpStack->precedent;
        }
        printf("%d, %s\n", tmpStack->address, tmpStack->name);
        printf("---------------------Fin Etat de la pile------------------\n");
    }
}