/*--------------------homework-15-1.c-----------------------*/

/*请写出可以进行位操作的 set_bit, get_bit 接口 set_bit(int num, int pos, int v); get_bit(int num, int pos);
 * 
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */


int set_bit(int num, int pos, int v)
{
	if (v == 1)
	{
		num |= 1 << pos;
	}
	else if (v == 0)
	{
		num &= ~(1 << pos);
	}
	return num;
}

int get_bit(int num, int pos)
{
	return (num >> pos) & 1; 
}


/*--------------------homework-15-2.c-----------------------*/

/*•用位运算实现字符的大小写转换
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

char transit_alphabet_1(char c)
{
	c ^= 1 << 5;
	return c;
}

char transit_alphabet_2(char c)
{
	if ( c & (1 << 5))
	{
		c &= ~(1 << 5);
	}
	else
	{
		c |= 1 << 5;
	}
	return c;
}

int main(void)
{
	char c;

	printf("Please input an alphabet: ");
	c = getchar();
	
	printf("%c is transited to %c\n", c, transit_alphabet_1(c));
	printf("%c is transited to %c\n", c, transit_alphabet_2(c));

	return 0;
}

/*--------------------homework-15-3.c-----------------------*/

/*••用位运算实现对一个无符号整型的二进制打印，八进制打印，十六进制打印
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

void print_bin(unsigned num)
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		if (num & (1 << i))
		{
			printf("1");;
		}
		else
		{
			printf("0");
		}
	}

	printf("\n");
}

void print_oct(unsigned num)
{
	char *oct = "01234567";
	int i;
	
	for (i = 30; i >= 0; i -= 3)
	{
		printf("%d", (num >> i) & 7);
	}

	printf("\n");
}

void print_hex(unsigned num)
{
	char *hex = "0123456789ABCDEF";
	int i;

	for (i = 28; i >= 0; i -= 4)
	{
		int k;
		k = (num >> i) & 0xF;
		printf("%c", hex[k]);
	}

	printf("\n");
}

int main(void)
{
	unsigned num;

	printf("Please input a number: ");
	scanf("%u", &num);
	
	printf("%d\' binary is  : ", num);
	print_bin(num);

	printf("%d\' oct is  : ", num);
	print_oct(num);

	printf("%d\' hex is  : ", num);
	print_hex(num);

	return 0;
}

/*--------------------homework-15-4.c-----------------------*/

/*••用位域操作实现随机生成无重复的10个数字，要求不允许使用数组
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void)
{
	int rand_digit;
	int i;
	int num = 0;
	srand((unsigned)time(NULL));
	
	i = 0;
	while (i < N)
	{
		rand_digit = rand() % 10;
		if ( num & (1 << rand_digit))
		{
			continue;
		}
		else
		{
			num |= 1 << rand_digit;
			printf("%d ", rand_digit);	
			i++;
		}
	}
	
	printf("\n");

	return 0;
}