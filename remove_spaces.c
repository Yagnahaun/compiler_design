#include <stdio.h>
#include <stdlib.h>

FILE *fp, *fp1;

int main(int argc, char *argv[])
{
	char c;

	fp = fopen(argv[1],"r");
	fp1 = fopen(argv[2],"w");

	if ( fp == NULL )
	{
		printf("Problem opening the file\n");
		exit(0);

	}
	else
	{
		while( (c = fgetc(fp)) != EOF )
		{
			if ( c == ' ' || c == '\t' || c =='\n' )
			{
			}
			else
			{
				fprintf(fp1, "%c", c);
			}
		}
	}
	fclose(fp);

	return 0;

}
