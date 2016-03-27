/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int checkdate1(int day, int month, int year)
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
int createdate(char *date1, char *date2)
{
	int  day1, day2, month1, month2, year1, year2, flag1, flag2;
	day1 = (date1[0] - '0') * 10 + (date1[1] - '0');
	day2 = (date2[0] - '0') * 10 + (date2[1] - '0');
	month1 = (date1[3] - '0') * 10 + (date1[4] - '0');
	month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
	year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
	year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
	flag1 = checkdate1(day1, month1, year1);
	flag2 = checkdate1(day2, month2, year2);
	if (flag1 != -1 && flag2 != -1)
	{
		if (year1 < year2 || year1 == year2&&month1 < month2 || year1 == year2&&month1 == month2&&day1<day2)
			return 1;
		else if (year1>year2 || year1 == year2&&month1 > month2 || year1 == year2&&month1 == month2&&day1 > day2)
			return 2;
		else
			return 0;

	}
	else
		return -1;


}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen <= 0 || A == NULL || BLen <= 0 || B == NULL)
		return NULL;
	int i = 0, j = 0, k = 0;
	struct transaction *result = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	while (i<ALen&&j<BLen){
		int n = createdate(A[i].date, B[j].date);
		if (n == -1)//for invalid dates
			return NULL;
		else if (n == 0)
		{
			result[k++] = A[i++];
			result[k++] = B[j++];
		}
		else if (n == 1)
			result[k++] = A[i++];
		else
			result[k++] = B[j++];

	}
	while (i<ALen)
		result[k++] = A[i++];
	while (j<BLen)
		result[k++] = B[j++];
	return result;
}