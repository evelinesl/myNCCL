#include <stdio.h>

int main(void)
{
	int counter;

	counter = 10;
	
	do
	{
		printf("counter = %d\n", counter);
		counter--;
	}while (counter > 0);
	
   	return 0;
}
