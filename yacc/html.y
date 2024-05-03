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
       | program fonc_declaration {printInstruction();}
       ;

return_statement: tRETURN arith tSEMI

print_statement: tPRINT expression tSEMI  

if_statement: tIF {incrementerS();} tLPAR expression tRPAR  tLBRACE {tiAddJMF();deleteSymboltmp();} instructions tRBRACE  {decrementerS(); updateJMF();}
              | if_statement tELSE {incrementerS();} tLBRACE instructions tRBRACE {decrementerS();}


while_statement: tWHILE {incrementerS();} tLPAR expression tRPAR tLBRACE {tiAddJMF();deleteSymboltmp();} instructions tRBRACE{decrementerS();updateJMF();}
               ;

print_statement: tPRINT tLPAR tID tRPAR tSEMI;


int_declaration : tINT int_declaration
                | tID {createSymbol($1); addCOP($1);}
                | tID {createSymbol($1);} tASSIGN arith {addCOP($1);} 
                | tID tCOMMA {createSymbol($1); addCOP($1);} int_declaration 
                ;



fonc_declaration: tINT tID {incrementerS();} tLPAR params tRPAR tLBRACE instructions  tRBRACE {decrementerS();}
                | tVOID tID {incrementerS();} tLPAR params tRPAR tLBRACE instructions tRBRACE {decrementerS();}
                ;

instructions: if_statement instructions
                | while_statement instructions 
                | print_statement instructions 
                | int_declaration tSEMI instructions 
                | return_statement
                ;

params: tVOID
      | tINT tID tCOMMA  params {createSymbol($2);}
      | tVOID tID tCOMMA params {createSymbol($2);}
      | tINT tID {createSymbol($2);}
      | tVOID tID {createSymbol($2);}
      ;
    
arith: arith tADD arith {int addr1 = searchSymbol("tmp"); deleteSymboltmp(); addMUL(addr1);}
          | arith tSUB arith 
          | arith tMUL arith {int addr1 = searchSymbol("tmp"); deleteSymboltmp(); addADD(addr1);}
          | arith tDIV arith  
          | tID {createSymbol("tmp"); addCOP($1);}
          | tID tLPAR args tRPAR
          | tNB {createSymbol("tmp"); setValue($1);}
          ;

expression : expression tEQ expression 
          | expression tCOMMA expression 
          | expression tLE expression 
          | expression tGE expression 
          | expression tNE expression 
          | expression tLT expression 
          | expression tGT expression 
          | tID {createSymbol("tmp");  addCOPIF($1);}
          | tNB {createSymbol("tmp");  setValue($1);}
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
