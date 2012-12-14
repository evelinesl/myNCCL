/*---------------homework-14------------------------------*/

/*
 * main.c - 打印打印杨辉三角形的前10行
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define LINE 10

int main(void)
{
    int i, j, k;
	int num[LINE][LINE];

	for (i = 0; i < LINE; i++)
	{
		num[i][0] = 1;
		num[i][i] = 1;
	}

	for (i = 0; i < LINE; i++)
	{
		for (k = LINE; k > i; k--)
		{
			printf("\t");
		}

		for (j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				printf("%d\t\t", num[i][j]);
				continue;
			}
			else if (j == i)
			{
				printf("%d", num[i][j]);
			}
			else
			{
				num[i][j] = num[i-1][j-1] + num[i-1][j];
				printf("%d\t\t", num[i][j]);
			}
		}

		printf("\n");
	}

	return 0;
}

