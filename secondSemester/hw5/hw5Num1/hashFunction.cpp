#include "hashFunction.h"

int abs(int value)
{
    if (value < 0)
        value = -value;
    return value;
}

int modBySize(int value, int hashSize)
{
    value = value % hashSize;
    while (value < 0)
    {
        value += hashSize;
    }
    return value;
}

int HashFunction::hashByModSize(int value)
{
    return (modBySize(value, hashSize));
}

int HashFunction::hashByFunctionFamily(int value)
{
    return (modBySize((37 * value + 41), hashSize));
}

int HashFunction::hashByNumSum(int value)
{
    int result = 0;
    value = abs(value);
    while (value != 0)
    {
        result += value % 10;
        value /= 10;
    }
    return (result % hashSize);
}
