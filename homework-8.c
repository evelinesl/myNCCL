/*---------------homework-8-1------------------------------*/

/*
 * main.c - Find the max prime between 1 and 100
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <math.h>

#define MAX_NUM   100

#define TRUE  1
#define FALSE 0


/*
 * is_prime - Judge whether num is prime or not
 * @num:    the number we want to judge
 *
 * Return value: TRUE　or FALSE
 *
 */
int is_prime(int num)
{
	int i;
	int tmp;

    tmp = (int)sqrt(num);

     for (i = 2; i <= tmp; i++)
     {
            if (num % i == 0)
                break;
      }

	  if (i == tmp + 1)
	  {
		  return TRUE;
	  }
	  else
	  {
		  return FALSE;
	  }


}

int main(void)
{
    int i;
    int max = 0;

    for (i = 1; i <= MAX_NUM; i++)
    {
        if (is_prime(i))
		{
			max = i;
		}
    }

    printf("max = %d\n", max);

    return 0;
}

/*---------------homework-8-2------------------------------*/

/*
 * main.c - 找出这2个数在相同位置处数字也相同的个数
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

/*
 * statistic - statistic the number of digit that has the same size and the same position among two numbers 
 * @number1:  
 * @number2:
 *
 * Return value: the total number of digit that has the same size and the same position among two numbers 
 *
 */
int statistic(int number1, int number2)
{
	int tmp1 = number1;
	int tmp2 = number2;
	int counter = 0;

	do
	{
		if (tmp1 % 10 == tmp2 % 10)
		{
			counter++;
		}

		tmp1 /= 10;
		tmp2 /= 10;

	}while (tmp1 != 0 && tmp2 != 0);

	return counter;
}

int main(void)
{
	int number1, number2;

	printf("Please input two integer numbers: ");
	scanf("%d  %d", &number1, &number2);

	printf("The number of the same digits between %d and %d is %d\n",number1, number2, statistic(number1,number2));

	return 0;
}
