#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <stdint.h>

int CalculateChecksum(int const zahl);

int CalculateArraySum(int intergerArray[]);

int main()
{
    printf("%i", CalculateChecksum(654));
    int arrayIntegers[5] = { 23, 55, 22, 3, 40 };
    printf("%i", CalculateChecksum(arrayIntegers));
}

int CalculateChecksum(int const zahl)
{
    int calcInteger = zahl;
    int result = 0;
    while (calcInteger > 0)
    {
        result = result + calcInteger % 10;
        calcInteger = calcInteger / 10;
    }
    return result;
}

int CalculateArraySum(int integerArray[])
{
    int sum = 0;
    for (int i = 0; i < sizeof integerArray; i++)
    {
        sum = sum + integerArray[i];
    }
    return sum;
}
