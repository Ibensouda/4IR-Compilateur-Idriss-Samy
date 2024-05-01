#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tds.h"

#define MAX_TDI 128

typedef struct 
{
    char action[50];   
    int tsAddr;  
    int value;      
} Instruction;

int idInst=0;
Instruction tdi[MAX_TDI];


void tiAdd(char * Action)
{
    int t = id-1;
    printf("%s %d %d\n", Action, t, myStack->address);
}