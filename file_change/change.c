#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *str, char *ch1);
#define N 50

int main()
{
	char str[N] = "aosl";
	char ch1[N];
	char ch2[N];

	FILE*file;
	file = fopen("replaces.txt", "r");

	int j = 0;
	while (fscanf(file, "%c%c", &ch1[j], &ch2[j]) != EOF)
	{
		printf("%c %c", ch1[j], ch2[j]);
		j++;
	}
	fclose(file);

	swap(str, ch1);
	printf("\n %s\n", str);

	return 0;
}

void swap(char *str, char *ch1)
{
	for (int i = 0; str[i] != 0; i++)
		for (int j = 0; j < 12; j++)
		{
			if (j % 2 != 0)
				j++;

			if (str[i] == ch1[j])
			{
				str[i] = ch1[j + 1];
			}
		}
}
