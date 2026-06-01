#include "hashopen.h"
#include <iostream>

HashOpen::HOinsert(int k)
{
	int i = 0;
	do
	{
		int q = HOhash(k, i);
		if (T[q] == nullptr)
		{
			T[q] = K;
			return q;
		}

		i++;
	}
	while (i != m)
	printf("Overflow.\n");
}

HashOpen::HOsearch(int k)
{
	int i = 0;

	do
	{
		int q = HOhash(k, i);
		if (T[q] == k)
		{
			return q;
		}
		i++;

	}
	while (i != m && T[q] != nullptr)
}
