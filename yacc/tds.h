#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 128
#define MAX_NAME_LENGTH 50

static int scopeG;

typedef struct stack {
    char name[MAX_NAME_LENGTH];
    int scope;
    int address;
    int value;
} SymbolStack;

extern int id;
extern SymbolStack * myStack;

void incrementerS(void);
void decrementerS(void);
void createSymbol(char *name);
int createSymbolTmp(char * name, int val);
int searchSymbol(char *namesearch);
int tsGetAddress(char * a);
void deleteSymboltmp(void);
SymbolStack * getLastSymbol(void);
void printStack(void);
#endif /* SYMBOL_TABLE_H */
