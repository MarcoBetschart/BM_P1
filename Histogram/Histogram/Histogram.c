// Histogram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

int main()
{
	// Aufgabe 1
	printf("Das Program wurde gestartet\n");





	// Aufgabe 2
	//FILE *stream;
	//errno_t err;
	//int count = 0, ch;
	//// Open for read (will fail if file "crt_fopen_s.c" does not exist)
	//err = fopen_s(&stream, "C:\\Users\\marco\\OneDrive\\Dokumente\\HFIE\\Strukturierte Progammierung\\Histogram\\Alice Adventure in Wonderland.txt", "r");
	//if (stream == NULL)
	//	exit(0);

	//while (1) {
	//	ch = fgetc(stream);
	//	if (ch == EOF)
	//		break;
	//	++count;
	//}
	//printf("Number of characters %i\n", count);

	//fclose(stream);




	// Aufgabe 3
	FILE* stream = NULL;
	_set_errno(0);

	errno_t err = fopen_s(&stream, "C:\\Users\\marco\\OneDrive\\Dokumente\\HFIE\\Strukturierte Progammierung\\Repo\\BM_P1\\Histogram\\Alice Adventure in Wonderland.txt", "r");
	if (err != 0) {
		printf("Error occured %i", err);
		return 1;
	}

	assert(stream != NULL);
	int ch = getc(stream);
	int histogram[256] = { 0 };
	int maxSizeLetter = 0;

	while (ch > EOF)
	{
		if (ch != EOF)
		{
			histogram[ch]++;
			if (histogram[ch] > histogram[maxSizeLetter])
			{
				maxSizeLetter = ch;
			}
		}
		ch = getc(stream);
	}

	for (int i = 0; i < 256; i++) {
		if (histogram[i] > 0)
		{
			printf("Zeichen \'%c\' = %d\n", i, histogram[i]);
		}
	}
	printf("Grösste Anzahl von Buchstabe \'%c\' = %d\n", maxSizeLetter, histogram[maxSizeLetter]);

	fclose(stream);
}