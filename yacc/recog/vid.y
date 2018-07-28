%{
#include<stdio.h>
#include<stdlib.h>
%}

%token DIGIT LETTER UND NL BUILTIN

%%
stmt: variable {printf("valid identifiers\n"); exit(0);}
;
stmt2: builtin {printf("invalid identifiers\n"); exit(0);}
;
variable: LETTER alphanumeric | UND alphanumeric
;
alphanumeric: LETTER alphanumeric | DIGIT alphanumeric | UND alphanumeric | LETTER | DIGIT | UND | NL
;
builtin : BUILTIN
;
%%

int yyerror(char *msg)
{
 printf("Invalid variable\n");
 exit(0);
}

main()
{
 printf("enter the variable: \n");
 yyparse();
}
