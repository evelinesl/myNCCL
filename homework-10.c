/*--------------------homework-10-1.c-----------------------*/

/*
 * main.c -Count the total number of comparisons for this program
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define ALL_NUM     100
#define COUNT_NUM   3
#define OUT_NUM     3

int people[ALL_NUM];

int main(void)
{
	int left;
	int pos;
	int step;
	int i;
	int counter = 0;

	counter += ALL_NUM + 1;
	for (i = 0; i < ALL_NUM; i++)
	{
		people[i] = i + 1;
	}

    left = ALL_NUM;
	pos = 0;
	step = 0;

	counter++;
	while (left > 0)
	{
		counter++;

		counter++;
		if (people[pos] > 0)
		{
			step++;
		}

		if (step < COUNT_NUM) //这次比较不属于程序本身，不记录
		{
			counter++;
		}
		else
		{
			counter += 2;
		}

		if (step == COUNT_NUM && people[pos] != 0)
		{
			printf("%d out\n", people[pos]);
			people[pos] = 0;
			left--;
		}

		pos = (1 + pos) % ALL_NUM;
		step %= OUT_NUM;
	}

	printf("The total number of comparisons for this program is %d\n", counter);
	return 0;
}       

/*--------------------homework-10-2.c-----------------------*/

/*
 * main.c -Print the calendar for 2012 year 
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define YEAR_FIRST_DAY 0
#define MONTH_NUM      12


int year_2012_month[12] = {31, 29, 31,30, 31, 30, 31, 31, 30, 31, 30, 31};

char month[][20] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};



void print(int day_num, int first_day)
{
	 int i;	   

	 printf (" Sun\tMon\tTue\tWed\tThu\tFri\tSat");	     
	 for (i = 0; i < day_num + first_day; i++)     
	 {		         
		 if (i%7 == 0)
		 {
			 printf("\n");
		 }

		 if (i < first_day)	
		 {
			 printf("\t");
		 }
		 else
		 {
			 printf(" %2d\t", i - first_day + 1);	
		 }
	 }	     

	 printf ("\n");
}


int main(void)
{
	int i;
	int first_day;

	for (i = 0; i < MONTH_NUM; i++)
	{
		if (i == 0)
		{
			first_day = YEAR_FIRST_DAY;
		}
		else
		{
			first_day = (year_2012_month[i - 1] % 7 + first_day) % 7;
		}

		printf("\n\n%s\t\t\t\t\t\t2012\n", month[i]);
		print(year_2012_month[i], first_day);
	}
	return 0;
}  

/*--------------------homework-10-3.c-----------------------*/

/*
 * main.c -Sort
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#define MAX_NUM 10

void sort(int num, int buf[])
{
	int i, j;

	i = 0;
	j = num - 1;
	while (i < j)
	{
		while (buf[i] % 2 != 0 && i < j)
		{
			i++;
		}

		while (buf[j] % 2 == 0 && i < j)
		{
			j--;
		}

		if (buf[i] % 2 == 0 && buf[j] % 2 != 0)
		{
			buf[i] = buf[i] + buf[j];
			buf[j] = buf[i] - buf[j];
			buf[i] = buf[i] - buf[j];

			i++;
			j--;
		}

	}
}

int main(void)
{
	int input_num[MAX_NUM];
	int i;

	printf("Please input ten number\n");

	for (i = 0; i < MAX_NUM; i++)
	{
		scanf("%d", &input_num[i]);
	}

	sort(MAX_NUM, input_num);

	printf("\n");
	for (i = 0; i < MAX_NUM; i++)
	{
		printf("%d\t", input_num[i]);
	}

	return 0;
}       

