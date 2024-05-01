#ifndef TDS_H
#define TDS_H

#define MAX_TDI 128

typedef struct 
{
    char action[50];   
    int tsAddr;  
    int tiAddr;
    int x;      
} Instruction;

void tiAdd(char * Action);

#endif /* TDS_H */
