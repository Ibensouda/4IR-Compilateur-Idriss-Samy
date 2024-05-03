#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tds.h"

#define MAX_TDI 128
#define MAX_INSTRUCTIONS 256

int instruction[MAX_INSTRUCTIONS][4];
int instructionJMF[MAX_INSTRUCTIONS][3];
int j = 0;

/* 
    instruction add = 1
    instruction mul = 2
    instruction sou = 3
    instruction div = 4
    instruction COP = 5
    instruction AFC = 6
    instruction JMP = 7
    instruction JMF = 8
    instruction INF = 9
    instruction SUP = 10
    instruction EQU = 11
    instruction PRI = 12
*/
void tiAdd(char * Action)
{
    int t = id-1;
}
void setValue(int val) {
    //printf("AFC %d %d 0\n", searchSymbol("tmp"), val);
    instruction[j][0] = 6;
    instruction[j][1] = searchSymbol("tmp");
    instruction[j][2] = val;
    instruction[j][3] = 0;
    //printf("AFC %d %d %d\n", instruction[j][1], instruction[j][2], instruction[j][3]);
    j++;
}

void addCOP(char * name) {
    instruction[j][0] = 5;
    instruction[j][1] = searchSymbol(name);
    instruction[j][2] = searchSymbol("tmp");
    instruction[j][3] = 0;
    //printf("COP %d %d %d\n", instruction[j][1], instruction[j][2], instruction[j][3]);
    j++;
}
void addMUL(int addr) {
    int src = searchSymbol("tmp");
    instruction[j][0] = 2;
    instruction[j][1] = src;
    instruction[j][2] = src;
    instruction[j][3] = addr;
    //printf("ADD %d %d %d\n", instruction[j][1], instruction[j][2], instruction[j][3]);
    j++;
}
void addADD(int addr) {
    int src = searchSymbol("tmp");
    instruction[j][0] = 1;
    instruction[j][1] = src;
    instruction[j][2] = src;
    instruction[j][3] = addr;
    //printf("ADD %d %d %d\n", instruction[j][1], instruction[j][2], instruction[j][3]);
    j++;
}
void tiAddJMF() {
    instruction[j][0] = 8;
    instruction[j][1] = searchSymbol("tmp");
    instruction[j][2] = -1;
    instruction[j][3] = 0;
    //printf("JMF %d %d %d\n", instruction[j][1], instruction[j][2], instruction[j][3]);
    j++;
}
void updateJMF() {
    int toModify = -1;
    int i;
    for (i = 0; i < MAX_INSTRUCTIONS-1; i++) {
        if (instruction[i][0] == 8 && instruction[i][2] == -1) {
            toModify = i;
        }
    }
    instruction[toModify][2] = j;
    //printf("JMF %d %d %d\n", instruction[toModify][1], j+1, instruction[toModify][3]);
}
void addCOPIF(char * name) {
    instruction[j][0] = 5;
    instruction[j][1] = searchSymbol("tmp");
    instruction[j][2] = searchSymbol(name);
    instruction[j][3] = 0;
    //printf("COP %d %d %d\n", instruction[j][1], instruction[j][2], instruction[j][3]);
    j++;
}
void printInstruction() {
    for (int i = 0; i < j; i++) {
        switch (instruction[i][0]) {
            case 1:printf("ADD %d %d %d\n", instruction[i][1],  instruction[i][2], instruction[i][3]);break;
            case 2:printf("MUL %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 3:printf("SUB %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 4:printf("DIV %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 5:printf("COP %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 6:printf("AFC %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 7:printf("JMP %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 8:printf("JMF %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 9:printf("INF %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 10:printf("SUP %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 11:printf("EQU %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            case 12:printf("PRI %d %d %d\n", instruction[i][1], instruction[i][2], instruction[i][3]);break;
            
        }
    }
}