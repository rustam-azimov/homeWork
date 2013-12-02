#ifndef ZEROSINARRAY_H
#define ZEROSINARRAY_H

inline int countOfZerosInArray(const int* array, const int& size)
{
	int res = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] == 0)
		{
			res++;
		}
	}

	return res;
}
#endif // ZEROSINARRAY_H
