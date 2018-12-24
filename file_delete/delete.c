#include <stdio.h>
#include "stdlib.h"

int main()
{
	char c;
	FILE *f1, *f2;
	fopen_s(&f1, "one.txt", "r"); 
	fopen_s(&f2, "two.txt", "w"); 
	while ((c = fgetc(f1)) != EOF) 
	{
		if (c != '/')
		{
			fputc(c, f2);
		}
		else
			if ((c = fgetc(f1)) == '/')
			{
				while (c != '\n')
				{
					fputc(' ', f2);
					c = fgetc(f1);
				}
				fputc('\n', f2);
			}
			else
			{
				fputc('/', f2);
				fputc(c, f2);
			}
		printf("%c", c);
	}
	fclose(f1);
	fclose(f2);
	
	return 0;
}

