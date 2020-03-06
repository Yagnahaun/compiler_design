/*Lex program to count number of tokens*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0,j = 0;

%}

%%

[0] {i++;
}

[1] {j++;
}

\n {return -1;}
%%

int yywrap() {}

int main()
{

yylex();

if(i%2==0)
printf("There are even number of 0's in the binary number\n");
else 
printf("There are odd number of 0's in the binary number\n");

if(j%2==0)
printf("There are even number of 1's in the binary number\n");
else
printf("There are odd number of 1's in the binary number\n");

return 0;

}
