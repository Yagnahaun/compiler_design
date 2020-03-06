#include <stdio.h>
#include <stdlib.h>

FILE *fp, *fp1;

void check_file(char c);

int main(int argc , char *argv[])
{
	char c;

	if ( argc != 3 )
	{
		printf("Usage: %s <input-filename> <output-filename>\n",argv[0]);
	}

	fp = fopen(argv[1], "r");
	fp1 = fopen(argv[2], "w");

	while ( (c = fgetc(fp))!= EOF )
	{
		check_file(c);
	}

	fclose(fp);
	fclose(fp1);

	return 0;
}

void check_file(char c)
{
	char d, e;

	if ( c == '/' )
	{
		d = fgetc(fp);
		
		if ( d == '*' )
		{
			while( (d = fgetc(fp)) != EOF  )
			{
				if ( d == '*' )
				{
					e = fgetc(fp);
			
					if ( e == '/' )
					{
						return;
					}
				}

			}
		}
		else if ( d == '/' )
		{
			while ( (d = fgetc(fp)) != EOF )
			{
				if ( d == '\n' )
				{
					return;
				}
			}
		}
		else
		{
			fputc(c,fp1);
			fputc(d,fp1);
		}
	}
	else
	{
		fputc(c,fp1);
	}
}





			
			
