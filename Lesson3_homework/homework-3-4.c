#include <stdio.h>

int main(void)
{
	int counter;
	int sum;

	printf("Add from 1 to 10\n");
	
	counter = 0;
	sum =0;
	
	do
	{
		counter++;
		sum += counter;
	}while (counter < 10);

	printf("sum = %d\n", sum);
	
   	return 0;
}
