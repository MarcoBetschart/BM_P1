#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define codelen 5

void NormalGame();

/*
* Creates a Random Code
*/
void CreateRandomCode(char* code);
uint8_t RandomCodeOk(const char* code);

void ReadInput(char* input);
void CheckCorrectNumbers(char* userInput, const char* code);
void CheckNumbers(char* userInput, const char* code);
void ChangeNotExisting(char* userInput);
int CheckIfSuccessful(const char* codeCopy);

int main(int nrOfArgs, const char* args[], const char* env[]) 
{
	printf("Nr of arguments %i\n", nrOfArgs);
	if (nrOfArgs > 1)
	{
		if (strcmp(args[1], "sum" == 0))
		{
			printf("got sum");
		}
		else if (strcmp(args[1], "fill") == 0)
		{
			printf("got fill");
		}
	}
	else
	{
		NormalGame();
	}
}


void NormalGame()
{
	//Initialisierung des Zufallsgenerators 
	srand(time(NULL));


	// Erzeugung einer Zufallszahl 
	char code[codelen] = "";
	char userCode[codelen] = "";
	CreateRandomCode(code);
	int versuche = 0;
	do
	{
		versuche++;
		printf("--> Geben sie ihren Tipp ab:\n");
		ReadInput(userCode);
		CheckCorrectNumbers(userCode, code);
		CheckNumbers(userCode, code);
		ChangeNotExisting(userCode, code);
		printf("Resultat: %s\n", userCode);
	} while (versuche <= 7 && CheckIfSuccessful(userCode) == 0);

	if (CheckIfSuccessful(userCode) == 1)
	{
		printf("HERZLICHE GRATULATION");
	}
}

void CreateRandomCode(char* code)
{
	for (size_t i = 0; i < sizeof code; i++)
	{
		code[i] = (rand() % 6) + 1 + 48; // sechs verschiedene Symbole
	}
}

uint8_t RandomCodeOk(const char* code)
{
	uint8_t len = strnlen(code, 6);
	if (len == 5)
	{
		uint8_t i = 0;
		for (; i < len; i++)
		{
			if (code[i] < '1' || code[i] > '6')
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

void ReadInput(char* input)
{
	scanf_s("%c,%c,%c,%c", input, 1, input + 1, 1, input + 2, 1, input + 3, 1);
	while (getchar() != '\n');
}

void CheckCorrectNumbers(char* userInputCopy, const char* randomNumbers)
{
	for (size_t i = 0; i < sizeof randomNumbers; i++)
	{
		if (userInputCopy[i] == randomNumbers[i])
		{
			userInputCopy[i] = 'x';
		}
	}
}

void CheckNumbers(char* userInputCopy, const char* randomNumbers)
{
	for (size_t i = 0; i < sizeof randomNumbers; i++)
	{
		if (userInputCopy[i] != 'x')
		{
			for (size_t j = 0; j < sizeof randomNumbers; j++)	
			{
				if (userInputCopy[j] == randomNumbers[i])
				{
					userInputCopy[j] = 'o';
					continue;
				}
			}
		}
	}
}

void ChangeNotExisting(char* userInput)
{
	for (size_t i = 0; i < sizeof userInput; i++)
	{
		if (userInput[i] != 'o' && userInput[i] != 'x')
		{
			userInput[i] = '_';
		}
	}
}

int CheckIfSuccessful(const char* codeCopy)
{
	for (size_t i = 0; i < sizeof codeCopy; i++)
	{
		if (codeCopy[i] != 'x')
		{
			return 0;
		}
	}
	return 1;
}
