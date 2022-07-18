   /* cs152-miniL phase3 */
   
%{   
   /* write your C code here for definitions of variables and including headers */
#include "miniL-parser.hpp"
#include "y.tab.h"
   int currLine = 1, currPos = 1;

%}

   /* some common rules */

LETTER   [a-zA-Z]
DIGIT    [0-9]
ID       {LETTER}(({LETTER}|{DIGIT}|"_")*({LETTER}|{DIGIT})+)*
ERROR_START_ID   ({DIGIT}|"_")({ID}|{DIGIT}|"_")*
ERROR_END_ID   {ID}"_"+
/* COMP     [==|<>|<|>|<=|>=] */

%%
   /* specific lexer rules in regex */

   /* RESERVED WORDS */
function          { currPos += yyleng; return FUNCTION;}
beginparams	         {currPos += yyleng; return BEGIN_PARAMS;}
endparams	         {currPos += yyleng; return END_PARAMS;}
beginlocals	         {currPos += yyleng; return BEGIN_LOCALS;}
endlocals         	{currPos += yyleng; return END_LOCALS;}
beginbody	         {currPos += yyleng; return BEGIN_BODY;}
endbody           	{currPos += yyleng; return END_BODY;}
integer           	{currPos += yyleng; return INTEGER;}
array	               {currPos += yyleng; return ARRAY;}
enum	               {currPos += yyleng; return ENUM;}        
of	                  {currPos += yyleng; return OF;}
if	                  {currPos += yyleng; return IF;}
then                	{currPos += yyleng; return THEN;}
endif                {currPos += yyleng; return ENDIF;}
else                 {currPos += yyleng; return ELSE;}
for	               {currPos += yyleng; return FOR;}
while               	{currPos += yyleng; return WHILE;}
do	                  {currPos += yyleng; return DO;}
beginloop	         {currPos += yyleng; return BEGINLOOP;}
endloop	            {currPos += yyleng; return ENDLOOP;}
continue	            {currPos += yyleng; return CONTINUE;}
read                	{currPos += yyleng; return READ;}
write                {currPos += yyleng; return WRITE;}
and	               {currPos += yyleng; return AND;}
or                	{currPos += yyleng; return OR;}
not                	{currPos += yyleng; return NOT;}
true                	{currPos += yyleng; return TRUE;}
false                {currPos += yyleng; return FALSE;}
return	            {currPos += yyleng; return RETURN;}

         /*    ARITHMETIC OPERATORS    */
"-"                    {currPos += yyleng; return SUB;}
"+"                  {currPos += yyleng; return ADD;}
"*"                  {currPos += yyleng; return MULT;}
"/"                  {currPos += yyleng; return DIV;}
"%"                  {currPos += yyleng; return MOD;}


         /*    COMPARISON OPERATORS    */
"=="                 {currPos += yyleng; return EQ;}
"<>"	               {currPos += yyleng; return NEQ;}
"<"	               {currPos += yyleng; return LT;}
">"	               {currPos += yyleng; return GT;}
"<="	               {currPos += yyleng; return LTE;}
">="                 {currPos += yyleng; return GTE;}


          /*    IDENTIFIERS AND NUMBERS    */
{ID}+                 {currPos += yyleng; yylval.strVal = strdup(yytext); return IDENT;}
{DIGIT}+             {currPos += yyleng; yylval.iVal = atoi(yytext); return NUMBER;}


         /*    OTHER SPECIAL SYMBOLS    */
";"	                  {currPos += yyleng; return SEMICOLON;}
":"	                  {currPos += yyleng; return COLON;}
","	                  {currPos += yyleng; return COMMA;}
"("	                  {currPos += yyleng; return L_PAREN;}
")"	                  {currPos += yyleng; return R_PAREN;}
"["	                  {currPos += yyleng; return L_SQUARE_BRACKET;}
"]"	                  {currPos += yyleng; return R_SQUARE_BRACKET;}
":="	                  {currPos += yyleng; return ASSIGN;}



[ \t]+         {/* ignores spaces */ currPos += yyleng;}
"\n"           {/* ignores newlines */ currLine++; currPos = 1;}
##.*         {/*ignores comments*/ currLine++; currPos = 1;}


         /*    ERROR CATCHES    */
{ERROR_START_ID}       { printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos-1, yytext); exit(0); }
{ERROR_END_ID}       { printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos-1, yytext); exit(0); }


.              {printf("Error at line %d, column %d: unrecognized symbol \"\%s\"\n", currLine, currPos-1, yytext); exit(0);}

%%


	/* C functions used in lexer */

// int main(int argc, char ** argv)
// {
//    if(argc >= 2) {
//       yyin = fopen(argv[1], "r");
//       if(yyin == NULL) {
//          yyin = stdin;
//       }
//    }
//    else{
//       yyin = stdin;
//    }
//    yylex();
// }
