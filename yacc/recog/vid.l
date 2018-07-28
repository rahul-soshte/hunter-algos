%{
#include"y.tab.h"
%}

%%
[_] {return UND;}
if|else|while|int|switch|for|char {return BUILTIN;}
[a-zA-Z] {return LETTER;}
[0-9] {return DIGIT;}
[\n] {return NL;}
. {return yytext[0];}
%%
