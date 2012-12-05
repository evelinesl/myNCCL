/*---------------homework-6-1------------------------------*/

#include <stdio.h>

#define ROW    5
#define COLUM  5

int main(void)
{
    int i, j;
	int input_x, input_y;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUM; j++)
		{
			printf("0\t");
		}

		printf("\n");
	}

	printf("Please input X, Y: ");

	scanf("%d %d", &input_x, &input_y);

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUM; j++)
		{
			if (input_x == i && input_y == j )
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

	return 0;
}

/*---------------homework-6-2------------------------------*/
#include <stdio.h>

#define MAX_NUM 1000

int main(void)
{	
    int i, j, sum;
     
    for (i = 1; i < MAX_NUM; i++)
    {
       sum = 0;
       for(j = 1; j < i; j++)
       {
          if (i % j == 0)
          {
              sum += j;
          }
       }
       if (sum == i)
       {
           printf("%d\t", i);
       }
    }
    return 0;
}


/*------------------homework-6-3------------------------*/
#include <stdio.h>

int main(void)
{	
	int i, sum, tmp, tmp1;
	
	for (i = 100; i < 999; i++)
	{
		sum = 0;
		tmp = i;

		while (tmp != 0)
		{
			tmp1 = tmp % 10;
			sum += tmp1 * tmp1 * tmp1;
			tmp /=10;
		}

		if (sum == i)
		{
			printf("%d\t", i);
		}
	}

	printf("\n");
    
	return 0;
}
