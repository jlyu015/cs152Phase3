    /* cs152-miniL phase3 */
%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <map>
 #include <set>
 #include <vector>


 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;


 std::map<std::string, std::string> varTemps;
 std::map<std::string, int> arrSize;

 std::set<std::string> reserveWords {"IDENT" , "NUMBER" , "FUNCTION" , "BEGIN_PARAMS" , "END_PARAMS" , "BEGIN_LOCALS" , "END_LOCALS" , "BEGIN_BODY" , "END_BODY" , "INTEGER" , "ARRAY" , "ENUM" , "OF" , "IF" , "THEN" , "ENDIF" , "ELSE" , "FOR" , "WHILE" , "DO" , "BEGINLOOP" , "ENDLOOP" , "CONTINUE" , "READ" , "WRITE" , "AND" , "OR" , "NOT" , "TRUE" , "FALSE" , "RETURN" , "SUB" , "ADD" , "MULT" , "DIV" , "MOD" , "EQ" , "NEQ" , "LT" , "GT" , "LTE" , "GTE" , "SEMICOLON" , "COLON" , "COMMA" , "L_PAREN" , "R_PAREN" , "L_SQUARE_BRACKET" , "R_SQUARE_BRACKET" , "ASSIGN" ,
  "prog_start" , "ident" , "idents_plus" , "declaration" , "declarations" , "function" , "functions" , "var" , "vars_plus" , "expression" , "bool_expr" , "mult_expr" , "relation_and_expr" , "term" , "relation_expr" , "comp" , "prog_start" , "statement" , "statements_plus", "FuncIdent"};
 std::set<std::string> func;
 bool mainFunc = false;
 int tempCount = 0;
 int labelCount = 0;
 int yylex();
 std::string new_temp();
 std::string new_label();

  extern FILE * yyin;
%}

%union{
  /* put your types here */
  char* strVal;
  int iVal;

  // structs
  struct Stmnt {
      char* code;
  }statement;


  struct Exprsn {
      char* place;
      char* code;
      bool arr;
  }expression;
}

%error-verbose
%locations
%start prog_start
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY INTEGER ARRAY ENUM OF IF THEN ENDIF ELSE FOR WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
%token <strVal> IDENT
%token <iVal> NUMBER



%type <expression> ident idents_plus FuncIdent declaration declarations function functions var vars_plus expression bool_expr mult_expr relation_and_expr term relation_expr comp prog_start 
%type <statement> statement statements_plus
%right ASSIGN //9
%left OR 
%left AND 
%right NOT 
%left EQ NEQ LT GT LTE GTE 
%left SUB ADD 
%left DIV MOD MULT //3

/*NOTE:associativity (%left or %right) and precedent (bottom most is highest precedence)
   dont have to write the first 3 precedences (0-2) */
/* %start program */

%% 

  /* write your rules here */
   /* {printf("\n");} */

prog_start: %empty 
            {
               printf("Main function is not delcared\n");
               // exit(1);
            }
            | functions {printf("prog_start -> functions\n");}
                
            ;

functions: /*epsilon*/%empty {printf("functions -> epsilon\n");}
         | function functions {printf("functions -> function functions\n");}
         ;

function: FUNCTION FuncIdent SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements_plus END_BODY {
      std::string temp = "func ";
      temp.append($2.place);
      temp.append("\n");
      
      if($2.place == "main") {
         mainFunc == true;
      }
      temp.append($5.code);
      //identifies function parameters to be used
      std::string decs = $5.code;
      int decNum = 0;
      //set assignment for every param
      while(decs.find(".") != std::string::npos) {
         int pos = decs.find(".");
         decs.replace(pos, 1, "=");
         std::string set = ", $" + std::to_string(decNum) + "\n";
         decNum++;
         decs.replace(decs.find("\n", pos), 1, set);
      }
      temp.append(decs);
      temp.append($8.code);

      std::string statements = $11.code;
      if(statements.find("continue") != std::string::npos) {
         printf("error: continue found outside loop in function %s\n", $2.place);
      }

      temp.append(statements);
      temp.append("endfunc\n");
      printf(temp.c_str());

      }
      ; 

ident: IDENT 
   {
      std::string temp;
      std::string idnt = $1;
      if(func.find(idnt) == func.end() && varTemps.find(idnt) == varTemps.end()) {
         printf("Identifier %s is not declared\n", idnt.c_str());
      }
      $$.code = strdup(""); //not sure
      $$.place = strdup(idnt.c_str());
   }

FuncIdent: IDENT {
   if(func.find($1) != func.end()) {
      printf("function identifier %s already declared\n", $1);
   }
   else {
      func.insert($1);
   }
   $$.place = strdup($1);
   $$.code = strdup("");
};
 
declarations: /*epsilon*/%empty 
               {
                  $$.code = strdup("");
                  $$.place = strdup("");
               } 
            | declaration SEMICOLON declarations 
               {
                  std::string temp;
                  temp.append($1.code);
                  temp.append($3.code);

                  $$.code = strdup(temp.c_str());
                  $$.place = strdup("");
               }
 ;
 
declaration: idents_plus COLON INTEGER
            {
               std::string temp = $1.code;
               // varTemps.insert(std::pair<std::string, std::string>($1, ""));
               $$.code = strdup(temp.c_str());
               $$.place = strdup("");
            }
	          | idents_plus COLON ENUM L_PAREN idents_plus R_PAREN 
               {

               }
	          | idents_plus COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER 
                  {
                  if ($5 <= 0) {
                     char temp[128];
                     printf("Array size can't be less than 1");
                  }
                  
                  }
;

idents_plus: ident {
               $$.place = strdup($1.place);
               $$.code = strdup("");
            }
            | ident COMMA idents_plus 
            {
               std::string temp;
               temp.append($1.place);
               temp.append("|");
               temp.append($3.place);
               $$.place = strdup(temp.c_str());
               $$.code = strdup("");
            }
;
statements_plus:  statement SEMICOLON 
            {
               std::string temp;
               temp.append($1.code);

               $$.code = strdup(temp.c_str());
            }
            | statement SEMICOLON statements_plus 
            {
               std::string temp;
               // temp += $1.code + $3.code;
               temp.append($1.code);
               temp.append($3.code);

               $$.code = strdup(temp.c_str());
            }
;
statement: var ASSIGN expression {printf("statement -> var ASSIGN expression\n");}
         | IF bool_expr THEN statements_plus ENDIF {printf("statement -> IF bool_expr THEN statements_plus ENDIF\n");}
         | IF bool_expr THEN statements_plus ELSE statements_plus ENDIF {printf("statement -> IF bool_expr THEN statements_plus ELSE statements_plus ENDIF\n");}
	      | WHILE bool_expr BEGINLOOP statements_plus ENDLOOP {printf("statement -> WHILE bool_expr BEGINLOOP statements_plus ENDLOOP\n");}
	      | DO BEGINLOOP statements_plus ENDLOOP WHILE bool_expr {printf("statement -> DO BEGINLOOP statements_plus ENDLOOP\n");}
	      // dont have to do for loop
         | FOR vars_plus ASSIGN NUMBER SEMICOLON bool_expr SEMICOLON vars_plus ASSIGN expression BEGINLOOP statements_plus ENDLOOP {printf("statement -> FOR vars_plus ASSIGN %d SEMICOLON bool_expr SEMICOLON vars_plus ASSIGN expression BEGINLOOP statements_plus ENDLOOP\n", $4);}
	      | READ vars_plus 
            {
               std::string temp;
               temp.append($2.code);
               size_t pos = temp.find("|", 0);
               while(pos != std::string::npos) {
                  temp.replace(pos, 1, "<");
                  pos = temp.find("|", pos);
               }
               $$.code = strdup(temp.c_str());
            }
      	| WRITE vars_plus {
               std::string temp;
               temp.append($2.code);
               size_t pos = temp.find("|", 0);
               while(pos != std::string::npos) {
                  temp.replace(pos, 1, ">");
                  pos = temp.find("|", pos);
               }
               $$.code = strdup(temp.c_str());
         }
      	| CONTINUE  
         {
            $$.code = strdup("continue\n");
         }
      	| RETURN expression 
            {
               std::string temp;
               temp.append($2.code);
               temp.append("ret ");
               $$.code = strdup(temp.c_str());
            }
;

var: ident 
   {
      std::string temp;
      std::string idnt = $1.place;
      if(func.find(idnt) == func.end() && varTemps.find(idnt) == varTemps.end()){
         printf("Identifier %s not yet declared.\n",idnt.c_str());
      }
      else if (arrSize[idnt] > 1) {
         printf("Index was not provided for array identifier %s.\n", idnt.c_str());
      }
      $$.place = strdup(idnt.c_str());
      $$.arr = false;

   }
   | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET 
   {
      std::string temp;
      std::string idnt = $1.place;
      if(func.find(idnt) == func.end() && varTemps.find(idnt) == varTemps.end()){
         printf("Identifier %s not yet declared.\n",idnt.c_str());
      }
      else if (arrSize[idnt] == 1) {
         printf("Index was provided for non-array identifier %s.\n", idnt.c_str());
      }
      temp.append($1.place);
      temp.append(", ");
      temp.append($3.place);
      $$.code = strdup($3.code);
      $$.place = strdup(temp.c_str());
      $$.arr = true;
   }
;

expression: mult_expr 
   {
      $$.code = strdup($1.code);
      $$.place = strdup($1.place);
   }
	| expression ADD mult_expr 
   {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      // temp.append($1.code);
      // temp.append($3.code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");

      // temp += "+ " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("+ ");
      temp.append(dst);
      temp.append(", ");
      temp.append($1.place);
      temp.append(", ");
      temp.append($3.place);
      temp.append("\n");

      $$.code = strdup(temp.c_str());
      $$.place = strdup(dst.c_str());
   }
	| expression SUB mult_expr 
   {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      // temp.append($1.code);
      // temp.append($3.code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");
      //temp += "- " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("- ");
      temp.append(dst);
      temp.append(", ");
      temp.append($1.place);
      // temp.append(", ");
      temp.append($3.place);
      temp.append("\n");
      $$.code = strdup(temp.c_str());
      $$.place = strdup(dst.c_str());
   }

;

bool_expr: relation_and_expr 
            {
               // std::string 
            }
         | bool_expr OR relation_and_expr 
            {
               std::string temp;
               std::string dst = new_temp();
               temp.append($1.code);
               temp.append($3.code);
               temp += ". " + dst + "\n";
               temp += "|| " + dst + ", ";
               temp.append($1.place);
               temp.append(", ");
               temp.append($3.place);
               }
;

vars_plus: var COMMA vars_plus 
      {
         std::string temp;
         temp.append($1.code);
         if($1.arr) {
            temp.append(".[]| ");
         }
         else {
            temp.append(".| ");
         }
         temp.append($1.place);
         temp.append("\n");
         temp.append($3.code);
         $$.code = strdup(temp.c_str());
         $$.place = strdup("");
      }
      | var 
      {
         std::string temp;
         temp.append($1.code);
         if($1.arr) {
            temp.append(".[]| ");
         }
         else {
            temp.append(".| ");
         }
         temp.append($1.place);
         temp.append("\n");

         $$.code = strdup(temp.c_str());
         $$.place = strdup("");

      }
;

mult_expr: term 
   {
      $$.code = strdup($1.code);
      $$.place = strdup($1.place);
   }
	| term MULT mult_expr 
   {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append($1.code);
      temp.append($3.code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");


      //temp += "* " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("* ");
      temp.append(dst);
      temp.append(", ");
      temp.append($1.place);
      temp.append(", ");
      temp.append($3.place);
      temp.append("\n");

      $$.code = strdup(temp.c_str());
      $$.place = strdup(dst.c_str());
   }
	| term DIV mult_expr
   {
      std::string temp;
      std::string dst = new_temp();
      //temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append($1.code);
      temp.append($3.code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");

      // temp += "/ " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("/ ");
      temp.append(dst);
      temp.append(", ");
      temp.append($1.place);
      temp.append(", ");
      temp.append($3.place);
      temp.append("\n");
      $$.code = strdup(temp.c_str());
      $$.place = strdup(dst.c_str());
   }
	| term MOD mult_expr
   {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append($1.code);
      temp.append($3.code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");

      // temp += "% " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("% ");
      temp.append(dst);
      temp.append(", ");
      temp.append($1.place);
      temp.append(", ");
      temp.append($3.place);
      temp.append("\n");
      $$.code = strdup(temp.c_str());
      $$.place = strdup(dst.c_str());
   }

;

relation_and_expr: relation_expr 
   {
      $$.code = strdup($1.code);
      $$.place = strdup($1.place);
   }
   | relation_expr AND relation_and_expr
   {
      std::string temp;
      std::string dst = new_temp();
      // temp += $1.code + $3.code + ". " + dst + "\n";
      temp.append($1.code);
      temp.append($3.code);
      temp.append(". ");
      temp.append(dst);
      temp.append("\n");


      // temp += "&& " + dst + ", " + $1.place + ", " + $3.place + "\n";
      temp.append("&& ");
      temp.append(dst);
      temp.append(", ");
      temp.append($1.place);
      temp.append(", ");
      temp.append($3.place);
      temp.append("\n");

      $$.code = strdup(temp.c_str());
      $$.place = strdup(dst.c_str());
   }

;

term: var 
      {
         std::string dst = new_temp();
         std::string temp;
         if($1.arr) {
            temp.append($1.code);
            temp += ". " + dst + "\n";

            temp += "[]" + dst + ", ";
            temp.append($1.place);
            temp.append("\n");
         }
         else { 
            temp += ". " + dst + "\n";
            temp += "= " + dst + ", ";
            temp.append($1.place);
            temp.append("\n");
            temp.append($1.code);
         }

         if(varTemps.find($1.place) != varTemps.end()) {
            varTemps[$1.place] = dst;
         }

         $$.code = strdup(temp.c_str());
         $$.place = strdup(dst.c_str());
      }
    | SUB var 
      {
         std::string dst = new_temp();
         std::string temp;
         if($2.arr) {
            temp.append($2.code);
            temp += ". " + dst + "\n";

            temp += "[]" + dst + ", ";
            temp.append($2.place);
            temp.append("\n");
         }
         else { 
            temp += ". " + dst + "\n";
            temp += "= " + dst + ", ";
            temp.append($2.place);
            temp.append("\n");
            temp.append($2.code);
         }
         

         if(varTemps.find($2.place) != varTemps.end()) {
            varTemps[$2.place] = dst;
         }
         temp += "* " + dst + ", " + dst + ",-1\n";

         $$.code = strdup(temp.c_str());
         $$.place = strdup(dst.c_str());  
      }
	 | NUMBER 
      {
         std::string dst = new_temp();
         std::string temp;
         temp.append(", ");
         temp.append(dst);
         temp.append("\n");

         temp += "= " + dst + ", " + std::to_string($1) + "\n";
         $$.code = strdup(temp.c_str());
         $$.place = strdup(temp.c_str());
      }
	 | SUB NUMBER 
      {
         std::string dst = new_temp();
         std::string temp;
         
         temp += ". " + dst + "\n";
         temp += "= " + dst + ", -" + std::to_string($2) + "\n";

         $$.code = strdup(temp.c_str());
         $$.place = strdup(dst.c_str());
      }
	 | L_PAREN expression R_PAREN 
      {
         $$.code = strdup($2.code);
         $$.place = strdup($2.place);
      }

    | ident L_PAREN expression R_PAREN 
      {
         std::string temp;
         std::string funcName = $1.place;
         if(func.find(funcName) == func.end()) {
            printf("function identifier %s not declared", funcName.c_str());
         }
         std::string dst = new_temp();
         temp.append($3.code);
         temp+= ". " + dst + "\n";
         
         temp.append("call");
         temp.append($1.place);
         temp+= ". " + dst + "\n";
         
         $$.code = strdup(temp.c_str());
         $$.place = strdup(temp.c_str());
      }
    | ident L_PAREN R_PAREN {printf("term -> ident L_PAREN R_PAREN\n");}
;

relation_expr: expression comp expression 
               {
                  std::string dst = new_temp();
                  std::string temp;
                  // temp += $1.code + $2.code + ", " + dst + "\n";
                  temp.append($1.code);
                  temp.append($2.code);
                  temp.append(", ");
                  temp.append(dst);
                  temp.append("\n");

                  // temp += $2.place + dst + ", " $3.place + "\n";
                  temp.append($2.place);
                  temp.append(dst);
                  temp.append(", ");
                  temp.append($3.place);
                  temp.append("\n");
                  $$.code = strdup(temp.c_str());
                  $$.place = strdup(dst.c_str());
               }
		       | NOT expression comp expression 
               {printf("relation_expr -> NOT expression comp expression\n");}
		       | TRUE 
               {
                  std::string temp = "1";
                  $$.code = strdup("");
                  $$.place = strdup(temp.c_str());
               }
      		 | NOT TRUE 
               {  
                  std::string temp = "0";
                  $$.code = strdup("");
                  $$.place = strdup(temp.c_str());}
      		 | FALSE 
               {
                  std::string temp = "0";
                  $$.code = strdup("");
                  $$.place = strdup(temp.c_str());
               }
	      	 | NOT FALSE 
               {  
                  std::string temp = "1";
                  $$.code = strdup("");
                  $$.place = strdup(temp.c_str());}
	      	 | L_PAREN bool_expr R_PAREN 
               {
                  $$.code = $2.code;
                  $$.place = $2.place;
               }
		       | NOT L_PAREN bool_expr R_PAREN 
               {printf("relation_expr -> NOT L_PAREN bool_expr R_PAREN\n");}
;  

comp: EQ 
      {
         $$.code = strdup("");
         $$.place =strdup("== ");
      }
	 | NEQ 
      {
         $$.code = strdup("");
         $$.place =strdup("!= ");
      }
	 | LT 
      {
         $$.code = strdup("");
         $$.place =strdup("< ");
      }
	 | GT 
      {
         $$.code = strdup("");
         $$.place =strdup("> ");
      }
	 | LTE 
      {
         $$.code = strdup("");
         $$.place =strdup("<= ");
      }
	 | GTE 
      {
         $$.code = strdup("");
         $$.place =strdup(">= ");
      }
;

 
%% 

int main(int argc, char ** argv)
{
   if(argc >= 2) {
      yyin = fopen(argv[1], "r");
      if(yyin == NULL) {
         yyin = stdin;
      }
   }
   else{
      yyin = stdin;
   }
   yyparse();
   
   return 0;
}

void yyerror(const char *msg) {
   printf("Syntax error: Line %d, position %d: %s \n", currLine, currPos, msg);

   
    /* implement your error handling */
}


std::string new_temp() {
   std::string tempString = "T" + std::to_string(tempCount);
   tempCount++;

   return tempString;
}

std::string new_label() {
   std::string labelString = "L" + std::to_string(labelCount);
   labelCount++;

   return labelString;
}