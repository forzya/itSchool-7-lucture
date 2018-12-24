//ID3v2 
#define ID3_MAX_SIZE 128
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct IDv3Tag
{
	char signature[3];
	char name[30];
	char artist[30];
	char album[30];
	char year[4];
	char description[30];
	unsigned short ganre;
} ID3TAG;

long idv3_file_offset(FILE* fp)
{
	fseek(fp, 0L, SEEK_END);
	return ftell(fp) - ID3_MAX_SIZE;
}

int main()
{
	FILE* file = NULL;
	const char* filename = "dead_by_april.mp3";
	if ((file = fopen(filename, "r")) == NULL)
		printf("Unable to open file %s\n", filename);

	char* buf = new char[ID3_MAX_SIZE];
	memset((void*)buf, 0x00, ID3_MAX_SIZE);

	fseek(file, idv3_file_offset(file), SEEK_SET);
	fread(buf, 1, ID3_MAX_SIZE, file);

	ID3TAG* pId3Tag = NULL;
	if ((pId3Tag = reinterpret_cast<ID3TAG*>(buf)) != NULL)
	{
		printf("Name:        %s\n", pId3Tag->name);
		printf("Artist:      %s\n", pId3Tag->artist);
		printf("Album:       %s\n", pId3Tag->album);
		printf("Year:        %s\n", pId3Tag->year);
		printf("Description: %s\n", pId3Tag->description);
		printf("Ganre:       %d\n", pId3Tag->ganre);
	}

	fclose(file);
	_getch();

	return 0;
}