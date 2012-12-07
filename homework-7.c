/*---------------homework-7-1------------------------------*/

/*
 * main.c - 统计5x5棋盘中两个落子之间棋子的个数
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define ROW    5
#define COLUM  5

#define TRUE  1
#define FALSE 0

int main(void)
{
	int i, j, counter;
	int x_1, y_1;
	int x_2, y_2;
	int start_flag = FALSE, end_flag = FALSE;
   
	/*Check the two input coordinates*/

	while (1)
	{
		printf("Please input the first coordinate: ");
		scanf("%d %d", &x_1, &y_1);
		
		if (x_1 < 0 || x_1 > 4 || y_1 < 0 || y_1 > 4)
		{
			printf("The first coordinate is error!\n\n");
			continue;
		}

		printf("Please input the second coordinate: ");
		scanf("%d %d", &x_2, &y_2);

		if (x_2 < 0 || x_2 > 4 || y_2 < 0 || y_2 > 4)
		{
			printf("The second coordinate is error!\n\n");
			continue;
		}

		if (x_2 < x_1 || (x_2 == x_1 && y_1> y_2))
		{
			printf("Input error!\nPlease input again.\n");
		}
		else
		{
			break;
		}
	}
    
	/*Print the chessboard*/

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUM; j++)
		{
			if ((x_1 == i && y_1 == j) || (x_2 == i && y_2 == j))
			{
				printf("1\t");
			}
			else
			{
				printf("0\t");
			}
		}

		printf("\n");
	}

	/*Statistics*/

	counter = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUM; j++)
		{
			if (x_1 == i && y_1 == j )
			{
				start_flag = TRUE;
				continue;
			}
			else if (x_2 == i && y_2 == j)
			{
				end_flag = TRUE;
				break;
			}
			else if (start_flag == TRUE && end_flag == FALSE)
			{
				counter++;
			}
		}
		
		if (end_flag == TRUE)
		{
			break;
		}
	}
	

	printf("There are %d pieces between (%d, %d) and (%d, %d)", counter, x_1, y_1, x_2, y_2);
	
	return 0;
}

/*---------------homework-7-2------------------------------*/

/*
 * main.c - 打印5x5棋盘中能被皇后吃掉的坐标位置
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define ROW    5
#define COLUM  5

int main(void)
{
	int i, j;
	int coordinate_x, coordinate_y;
	
	/*Check the input coordinate*/

	while (1)
	{
		printf("Please input the coordinate: ");
		scanf("%d %d", &coordinate_x, &coordinate_y);
		
		if (coordinate_x < 0 || coordinate_x > 4 || coordinate_y < 0 || coordinate_y > 4)
		{
			printf("The coordinate inputs error!\n\n");
			continue;
		}
		else
		{
			break;
		}
	}

	/*Print the chessboard*/

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUM; j++)
		{
			if (coordinate_x == i && coordinate_y == j)
			{
				printf("1\t");
			}
			else
			{
				printf("0\t");
			}
		}

		printf("\n");
	}

	/*Print the coordinates that can be eaten by queen*/

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUM; j++)
		{
			if (i == coordinate_x && j == coordinate_y)
				continue;

			if (i  == coordinate_x || j == coordinate_y || (i - coordinate_x) == (j - coordinate_y))
			{
				printf("(%d, %d)  ", i, j);
				continue;
			}

		}
	}

	return 0;
}

/*---------------homework-7-3------------------------------*/

/*
 * main.c - 打印打印杨辉三角形的前10行
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define LINE    10

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
			printf("  ");

		for (j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				printf("%d    ", num[i][j]);
				continue;
			}
			else if (j == i)
			{
				printf("%d", num[i][j]);
			}
			else
			{
				num[i][j] = num[i-1][j-1] + num[i-1][j];
				printf("%d    ", num[i][j]);
			}
		}

		printf("\n");
	}

	return 0;
}
