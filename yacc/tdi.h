#ifndef TDS_H
#define TDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TDI 128
#define MAX_INSTRUCTIONS 256

extern int instruction[MAX_INSTRUCTIONS][4];
extern int instructionJMF[MAX_INSTRUCTIONS][3];
extern int j;
void tiAdd(char *Action);
void setValue(int val);
void tiAddJMF(void);
void printInstruction(void);
void addCOP(char * name);
void addMUL(int addr);
void addADD(int addr);
void updateJMF(void);
void addCOPIF(char * name);
#endif /* TDS_H */
