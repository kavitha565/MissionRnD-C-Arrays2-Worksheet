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
	if (len <= 0||A == NULL)
		return -1;
	else
	{
		int i, count[20] = { 0 };
		for (i = 0; i < len; i++)
		{
			count[A[i]]++;
		}

		for (i = 0; i < len; i++)
		{
			if (count[A[i]] == 1)
				return A[i];
		}
	}
}