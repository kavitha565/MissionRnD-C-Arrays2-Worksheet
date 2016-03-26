/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int checkdate2(int day, int month, int year)
{
	if (day == 0 || month == 0 || year == 0)
		return(-1);
	else if (month>12 || day>31)
		return(-1);
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day>29)
				return(-1);
		}
		else
		{
			if (day>28)
				return(-1);
		}

	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day>30)
			return(-1);
	}
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen <= 0 || A == NULL || BLen <= 0 || B == NULL)
		return NULL;
	else if (A == B)//if both arrays are same
		return(A);
	else{
		int i, j, day1, day2, month1, month2, year1, year2, flag1, flag2, count = 0;
		struct transaction *result = (struct transaction*)malloc((1)*sizeof(struct transaction));
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				day1 = (A[i].date[0] - '0') * 10 + (A[i].date[1] - '0');
				day2 = (B[j].date[0] - '0') * 10 + (B[j].date[1] - '0');
				month1 = (A[i].date[3] - '0') * 10 + (A[i].date[4] - '0');
				month2 = (B[j].date[3] - '0') * 10 + (B[j].date[4] - '0');
				year1 = (A[i].date[6] - '0') * 1000 + (A[i].date[7] - '0') * 100 + (A[i].date[8] - '0') * 10 + (A[i].date[9] - '0');
				year2 = (B[j].date[6] - '0') * 1000 + (B[j].date[7] - '0') * 100 + (B[j].date[8] - '0') * 10 + (B[j].date[9] - '0');
				flag1 = checkdate2(day1, month1, year1);
				flag2 = checkdate2(day2, month2, year2);
				if (flag1 != -1 && flag2 != -1)
				{
					if (year1 == year2&&month1 == month2&&day1 == day2)
					{
						count++;
						result = &A[i];

					}
				}
				else
					return NULL;

			}
		}
		if (count == 0)
			return NULL;
		else
			return(result);
	}
}