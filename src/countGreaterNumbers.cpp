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



int validate_date(int day, int month, int year)
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

	}
	void fun(char *date, int *day, int *mon, int *year)
	{
		*day = (date[0] - '0') * 10 + (date[1] - '0');
		*mon = (date[3] - '0') * 10 + (date[4] - '0');
		*year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	}
	int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
		int temp, count = 0;
		int i, day_date, month_date, year_date;
		int day, mon, year;
		day_date = (date[0] - '0') * 10 + (date[1] - '0');
		month_date = (date[3] - '0') * 10 + (date[4] - '0');
		year_date = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
		temp = (validate_date(day_date, month_date, year_date));
		if (len <= 0 || !Arr || temp == -1)
			return NULL;
		for (i = 0; i<len; i++)
		{
			fun(Arr[i].date, &day, &mon, &year);
			if (year_date<year || (year_date == year && month_date<mon) || (year_date == year && month_date == mon  && day_date<day))
				count++;
		}
		return count;
	}

