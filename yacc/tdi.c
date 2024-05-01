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


void tiAdd(char * Action, int addr, int val)
{
    if (id <MAX_TDI) {
        strcpy(tdi[idInst].action, Action);
        tdi[idInst].tsAddr = addr;
        tdi[idInst].value = val;
        printf("%s %d %d\n", tdi[idInst].action, addr, val);
        idInst++;
    }
}