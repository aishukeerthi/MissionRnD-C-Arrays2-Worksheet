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
int validate_date1(int day, int month, int year)
{
	if (month == 0 || day == 0 || year == 0 || month>12)
		return -1;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day >31)
			return -1;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day>30)
			return -1;
	}
	else
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day>29)
				return -1;
		}
		else
		{
			if (day>28)
				return -1;
		}
	}
	return 1;

}
void fun1(char *date, int *day, int *mon, int *year)
{
	*day = (date[0] - '0') * 10 + (date[1] - '0');
	*mon = (date[3] - '0') * 10 + (date[4] - '0');
	*year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (ALen <= 0 || BLen <= 0 || A == NULL || B == NULL)
		return NULL;
	int temp = 0, temp1 = 0, i, j, len,k=0,count=0;
	if (ALen >= BLen)
		len = ALen;
	else
		len = BLen;
	struct transaction *Result = (struct transaction *)malloc(sizeof(struct transaction)*len);
	int day, mon, year;
	int Aday, Amon, Ayear, Bday, Bmon, Byear;
	for (i = 0; i<ALen; i++)
	{
		fun1(A[i].date, &day, &mon, &year);
		temp = (validate_date1(day, mon, year));
		if (temp == -1)
			return NULL;
	}
	for (i = 0; i<BLen; i++)
	{
		fun1(B[i].date, &day, &mon, &year);
		temp1 = (validate_date1(day, mon, year));
		if (temp1 == -1)
			return NULL;
	}
	
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < BLen; j++)
			{
				fun1(A[i].date, &Aday, &Amon, &Ayear);
				fun1(B[j].date, &Bday, &Bmon, &Byear);
				if (Aday == Bday && Amon == Bmon && Ayear == Byear)
				{
					count++;
					Result[k++] = A[i];
				}
			}
		}
		if (count > 0)
			return Result;
		return NULL;
}