/*This is a lex program to idetify +ve and -ve numbers*/

%{
%}

/*These are the rules for identifying the given numbers*/

%%
[0] {
printf("This is neither positive nor negative\n");
}

^[-][0] {
printf("This is nwither positive nor negative\n");
}

[1-9]+ {
printf("This is a positive number = %s\n",yytext);
}

^[-][1-9]+ {
printf("This is a negative number = %s\n",yytext);
}

\n {return -1;}

%%

int yywrap(){}

int main()
{

yylex();
return 0;

}
