/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int checkdate(int day, int month, int year)
{
	if (day == 0 || month == 0 || year == 0)
		return(-1);
	else if (month>12 || day>31)
		return(-1);
	else if (month == 2)
	{
		if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, day1, day2, month1, month2, year1, year2, flag1, flag2, count = 0;
	day2 = (date[0] - '0') * 10 + (date[1] - '0');
	month2 = (date[3] - '0') * 10 + (date[4] - '0');
	year2 = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	for (i = 0; i < len; i++)
	{
		day1 = (Arr[i].date[0] - '0') * 10 + (Arr[i].date[1] - '0');
		month1 = (Arr[i].date[3] - '0') * 10 + (Arr[i].date[4] - '0');
		year1 = (Arr[i].date[6] - '0') * 1000 + (Arr[i].date[7] - '0') * 100 + (Arr[i].date[8] - '0') * 10 + (Arr[i].date[9] - '0');
		flag1 = checkdate(day1, month1, year1);
		flag2 = checkdate(day2, month2, year2);
		if (flag1 != -1 && flag2 != -1)
		{
			if (year1 > year2 || year1 == year2&&month1 > month2 || year1 == year2&&month1 == month2&&day1 > day2)
			{
				count++;
			}

		}
		else
			return NULL;
		

	}
	return count;
}