#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

/**
* @file hashFunction.h
*
* @section DESCRIPTION
*
* Implementation of HashFunction class that contains various hash functions.
*/


enum HashType {
    byMod = 0,
    byFam,
    bySum
};

class HashFunction
{
public:
    HashFunction(int size):
        hashSize(size)
    {}

    int hashByModSize(int value);
    int hashByFunctionFamily(int value);
    int hashByNumSum(int value);

private:
    int const hashSize;
};

#endif // HASHFUNCTION_H
