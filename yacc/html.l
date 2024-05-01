/*Idriss Bensouda, Samy Saad Chaouch */

%{
#include <stdio.h>
#include "html.tab.h"
%}

%option noyywrap
%option noinput
%option nounput
%option yylineno
DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          {LETTER}({LETTER}|{DIGIT})*
HEX_NB      0x{DIGIT}+
DEC_NB      {DIGIT}+
COMMENT     ("//".*|\/\*([^*]|\*+[^*/])*\*+\/)
WS          [ \t\r\n]+

/* Token Definitions */
%%

if           {return tIF;} 
else         { return tELSE;} 
while        { return tWHILE;} 
print        {return tPRINT;} 
return       {return tRETURN;} 
int          {return tINT;}; 
void         {return tVOID;} 
{ID}         {
    
            yylval.s = strdup(yytext);
            return tID;} 
{DEC_NB}     {
            yylval.n = atoi(yytext);
            return tNB;
}
{HEX_NB}     {return tNB;}
{COMMENT}   
"+"          { return tADD;} 
"-"          { return tSUB;}
"*"          { return tMUL;}
"/"          { return tDIV;}
"<"          {return tLT;}
">"          {return tGT;}
"!="         {return tNE;}
"=="         {return tEQ;}
">="         {return tGE;}
"<="         {return tLE;}
"="          { return tASSIGN;}
"&&"         {return tAND;}
"||"         {return tOR;}
"!"          { return tNOT;}
"{"          {return  tLBRACE;}
"}"          {return tRBRACE;}
"("          {return tLPAR;}
")"          {return tRPAR;}
";"          {return tSEMI;}
","         {return tCOMMA;}
{WS}        {}
.           { return tERROR;}
%%

