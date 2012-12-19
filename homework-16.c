/*--------------------homework-16-1.c-----------------------*/

/*请用指针实现对一个数组的调整，要求奇数在左边，偶数在右边。 要求： 尽可能不占用额外的存储空间
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

void sort(int num, int buf[])
{
	int *begin = buf;
	int *end = buf + num -1;

	while (begin < end)
	{
		if (*begin % 2 != 0 )
		{
			begin++;
			continue;
		}

		if (*end % 2 == 0)
		{
			end--;
			continue;
		}

		*begin = *begin + *end;
		*end   = *begin - *end;
		*begin = *begin - *end;
		
		begin++;
		end--;
	}
}

int main(void)
{
	int input_num[MAX_NUM];
	int i;

	srand(time(NULL));
	printf("Please input ten number\n");

	for (i = 0; i < MAX_NUM; i++)
	{
		input_num[i] = rand() % 100;
		printf("%d ", input_num[i]);
	}

	printf("\n");

	sort(MAX_NUM, input_num);

	for (i = 0; i < MAX_NUM; i++)
	{
		printf("%d ", input_num[i]);
	}

	return 0;
}

/*--------------------homework-16-2.c-----------------------*/

/*请结合 strcpy 的实现，给出 strlen 的实现。要求：考虑内存对齐和算法执行效率
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

int strlen(const char *buf)
{

}

int main(void)
{
	

	return 0;
}