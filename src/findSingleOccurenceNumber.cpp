/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdio.h>
int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL)
		return -1;
	int result = 0;
	int shift, sum;
	for (int i = 0; i < 32; i++)
	{
		sum = 0;
		shift = (1 << i);
		for (int j = 0; j< len; j++)
		{
			if (A[j] & shift)
				sum++;
		}
		if (sum % 3)
			result |= shift;
	}

	return result;
}