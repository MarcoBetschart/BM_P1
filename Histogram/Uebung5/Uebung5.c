#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

uint8_t CheckIfPalindrom(const char* str);
int32_t FirstIndexOf1(const char* text, char ch);
char* ToLowerCase(char* text);
char* ToCamelCase(char* text);
char* Reverse(char* text);
int32_t GetIndexFromString(const char* text, const char* search);
char* ReverseNewString(const char* text);

int main()
{
	if (CheckIfPalindrom("sugus") == 1)
	{
		printf("Es ist ein Palindrom");
	}
	else
	{
		printf("Es ist kein Palindrom");
	}
	printf("\n");

	int32_t index1 = FirstIndexOf1("hello", 'l');

	printf("\n");

	char a[1024] = "tEsT";
	printf(ToLowerCase(a));

	printf("\n");

	char b[1024] = "byte_order";
	printf(ToCamelCase(b));
	printf("\n");

	char c[1024] = "morgen";
	printf(Reverse(c));
	printf("\n");

	char d[1024] = "Hello-World";
	printf("Index: %i", GetIndexFromString(d, "World"));
	printf("\n");

	char e[1024] = "morgen";
	char* p = ReverseNewString(e);
	char test = &p;
	printf("%s", test);
}

//Aufgabe 2a
uint8_t CheckIfPalindrom(const char* palindrom)
{
	uint32_t low = 0;
	uint32_t height = strnlen_s(palindrom, 128) - 1;

	while (palindrom[low] == palindrom[height] && low < height)
	{
		low++;
		height--;
	}
	return low >= height;
}

//Aufgabe 2b
int32_t FirstIndexOf1(const char* text, char ch)
{
	int32_t i = 0;
	char curChar = text[i];
	while (curChar != '\0')
	{
		if (curChar == ch) return i;
		i++;
		curChar = text[i];
	}
	return -1;
}

//Aufgabe 2c
char* ToLowerCase(char* text)
{
	uint32_t i = 0;
	for (; text[i] != '\0'; i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z')
		{
			text[i] += 32;
		}
	}
	return text;
}

//Aufgabe 2d
char* ToCamelCase(char* text)
{
	for (uint32_t i = 0; text[i]; i++) // text[i] ist das gleiche wie text[i] != '\0'
	{
		if (text[i] == '_')
		{
			text[i] = text[i + 1];
			for (uint32_t y = i; text[y]; y++)
			{
				text[y] = text[y + 1];
			}
			if (text[i] >= 'a' && text[i] <= 'z')
			{
				text[i] -= 32;
			}
			i++;
		}
	}
	return text;
}

//Aufgabe 2e
char* Reverse(char* text)
{
	uint32_t y = strnlen_s(text, 128) - 1;
	for (uint32_t i = 0; i <= y; i++) // text[i] ist das gleiche wie text[i] != '\0'
	{
		char swap = text[y];
		text[y] = text[i];
		text[i] = swap;
		y--;
	}
	return text;
}

//Aufgabe 2f
int32_t GetIndexFromString(const char* text, const char* search)
{
	uint32_t j = 0;
	for (size_t i = 0; i <= strnlen_s(text, 128); i++)
	{
		if (search[j] == '\0')
		{
			return i - j;
		}
		if (text[i] == search[j])
		{
			j++;
		}
		else 
		{
			j = 0;
		}
	}
	return -1;
}

char* ReverseNewString(const char* text)
{
	char* reversedText;
	reversedText = malloc(strnlen_s(text, 128));
	uint32_t y = strnlen_s(text, 128) - 1;
	for (size_t i = 0; text[i]; i++)
	{
		reversedText[i] = text[y];
		y--;
	}
	return &reversedText;
}
