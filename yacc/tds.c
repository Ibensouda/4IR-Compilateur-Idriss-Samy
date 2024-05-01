#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TDS 128
static int scopeG = 0;

typedef struct 
{
    char name[50];   
    int type;  
    int scope;      
} Symbol;

int id = 0;
Symbol tds[MAX_TDS];

void incrementerS() {scopeG++;}
void decrementerS() {scopeG--;}

void createSymbol(char * name, int type, int scope) 
{
    if (id < MAX_TDS) {
        printf("%s %d\n", name, scopeG);
        strcpy(tds[id].name, name);
        printf("%s\n", tds[id].name);
        tds[id].type = type;
        tds[id].scope = scope;
        id++;
    }
}

int searchSymbol(char * namesearch) 
{
    for (int j=0; j<MAX_TDS; j++)
    {
        if (strcmp(tds[j].name, namesearch) == 0)
        {
            return j;
        }
    }
    return -1;
}

int ts_get_last() {

}

int createSymbolTmp(void)
{

}

int tsGetAddress(char * a)
{
    int index = searchSymbol(a);
    int address = index;
    printf("%d, %d, %s", index, address, a);
    return address;
}