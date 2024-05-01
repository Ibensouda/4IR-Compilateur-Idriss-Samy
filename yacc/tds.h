#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SYMBOLS 128
#define MAX_NAME_LENGTH 50

static int scopeG;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int type;
    int scope;
} Symbol;

extern int id;
extern Symbol tds[MAX_SYMBOLS];

void incrementerS();
void decrementerS();
void createSymbol(char *name, int type, int scope);
int createSymbolTmp(void);
int searchSymbol(char *namesearch);
int tsGetAddress(char * a);
int createSymbolTmp(void);

#endif /* SYMBOL_TABLE_H */
