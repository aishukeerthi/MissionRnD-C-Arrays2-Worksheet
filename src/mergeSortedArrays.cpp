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
*/#include <iostream>
#include<stdio.h>
#include<stdlib.h>
			  int isOlder(char *dob1, char *dob2);
			  int validate_date2(int day, int month, int year)
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
			  int validate_length2(char *dob1)
			  {
				  int i;
				  for (i = 0; dob1[i] != '\0'; ++i);
				  return i;
			  }
			  int isOlder(char *dob1, char *dob2)
			  {
				  int i, j, day_1, day_2, month_1, month_2, year_1, year_2, temp, temp1;
				  i = validate_length2(dob1);
				  j = validate_length2(dob2);
				  //printf("values of i and j are %d %d\n",i,j);
				  day_1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
				  day_2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
				  month_1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
				  month_2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
				  year_1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
				  year_2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
				  temp = (validate_date2(day_1, month_1, year_1));
				  temp1 = (validate_date2(day_2, month_2, year_2));
				  if (temp != -1 && temp1 != -1 && i == 10 && j == 10)
				  {
					  if (year_1<year_2)
						  return 1;
					  else if (year_1>year_2)
						  return 2;
					  else
					  {
						  if (month_1<month_2)
							  return 1;
						  else if (month_1>month_2)
							  return 2;
						  else
						  {
							  if (day_1<day_2)
								  return 1;
							  else if (day_1>day_2)
								  return 2;
							  else
								  return 0;
						  }
					  }
				  }
				  else return -1;
			  }
			  struct transaction {
				  int amount;
				  char date[11];
				  char description[20];
			  };
			  struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
				  if (ALen <= 0 || BLen <= 0 || A == NULL || B == NULL)
					  return NULL;
				  int i = 0, j = 0, k = 0, len;
				  len = ALen + BLen;
				  struct transaction *Result = (struct transaction *)malloc(sizeof(struct transaction)*len);
				  while (i<ALen && j<BLen){
					  int res = isOlder(A[i].date, B[j].date);
					  if (res == -1)
						  return NULL;
					  else if (res == 0)
					  {
						  Result[k++] = A[i++];
						  Result[k++] = B[j++];
					  }
					  else if (res == 1)
						  Result[k++] = A[i++];
					  else
						  Result[k++] = B[j++];
				  }
				  while (i<ALen)
					  Result[k++] = A[i++];
				  while (j<BLen)
					  Result[k++] = B[j++];
				  return Result;

			  }

