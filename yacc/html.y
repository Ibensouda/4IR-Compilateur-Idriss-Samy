/* Idriss Bensouda, Samy Saad Chaouch */
%{
#include <stdio.h>
#include <stdlib.h>
#include "tds.h"
#include "tdi.h"
#include "html.tab.h"

%}

%code provides {
  int yylex (void);
  void yyerror (const char *);
}
%union {char *s; int n;}

%token tINT tIF tWHILE tELSE tADD tSUB tEQ tLBRACE tRBRACE tLPAR tRPAR  tSEMI tPRINT tRETURN tVOID tMUL tDIV tLT tGT tNE tGE tLE tASSIGN tAND tOR tNOT tCOMMA tERROR

%token <s> tID
%token <n> tNB

%left tSUB tADD
%left tMUL tDIV    
%left tEQ tLT tGT tNE tGE tLE
%left tCOMMA

%%

program: 
       | program fonc_declaration
       ;

return_statement: tRETURN tNB tSEMI
                |tRETURN tID tSEMI 
print_statement: tPRINT expression tSEMI  

if_statement: tIF {incrementerS();} tLPAR expression tRPAR  tLBRACE instructions tRBRACE {decrementerS();}
              | if_statement tELSE {incrementerS();} tLBRACE instructions tRBRACE {decrementerS();}


while_statement: tWHILE {incrementerS();} tLPAR expression tRPAR tLBRACE instructions tRBRACE{decrementerS();}
               ;

print_statement: tPRINT tLPAR tID tRPAR tSEMI 
                |tPRINT tLPAR tNB tRPAR tSEMI 
               ;

int_declaration: tINT int_declaration tSEMI 
                | tINT int_declaration tASSIGN arith tSEMI {tiAdd("AFC"); deleteSymboltmp();}
                | tID {createSymbol($1);} tCOMMA int_declaration  
                | tID  {createSymbol($1);}
                ;

int_assignment: tID tASSIGN arith tSEMI {tiAdd("AFC"); deleteSymboltmp();}

fonc_declaration: tINT tID {incrementerS();} tLPAR params tRPAR tLBRACE instructions  return_statement tRBRACE {decrementerS();}
                | tVOID tID {incrementerS();} tLPAR params tRPAR tLBRACE instructions tRBRACE {decrementerS();}
                ;

instructions: if_statement 
                | while_statement 
                | print_statement 
                | int_declaration 
                | int_assignment
                | if_statement instructions 
                | while_statement instructions 
                | print_statement instructions 
                | int_declaration instructions 
                | int_assignment instructions
                ;

params: tVOID
      | tINT tID tCOMMA  params {createSymbol($2);}
      | tVOID tID tCOMMA params {createSymbol($2);}
      | tINT tID {createSymbol($2);}
      | tVOID tID {createSymbol($2);}
      ;
    
arith: arith tADD arith 
          | arith tSUB arith 
          | arith tMUL arith 
          | arith tDIV arith  
          | tID {createSymbolTmp("tmp", 0);}
          | tID tLPAR args tRPAR
          | tNB {createSymbolTmp("tmp", $1);}
          ;

expression : expression tEQ expression 
          | expression tCOMMA expression 
          | expression tLE expression 
          | expression tGE expression 
          | expression tNE expression 
          | expression tLT expression 
          | expression tGT expression 
          | tID {createSymbolTmp($1, 5);}
          | tNB {createSymbolTmp("tmp", $1);}
          ;

args: arith
    | arith tCOMMA args
%%

void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
}

int main(void) {
  yyparse();
}
