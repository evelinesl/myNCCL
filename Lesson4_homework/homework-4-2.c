#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int num_computer;
	int num_user;
	
	srand((unsigned)time(NULL));
	num_computer = rand()%100; //rand() RAND_MAX(2147483647) is too large, so limit to 0~100
	printf("num_computer %d\n",num_computer);

	printf("Computer has generated a random number\n");
	do
	{
		printf("Please user guess: ");	
		scanf("%d",&num_user);
		if (num_user == num_computer)
		{
			printf("Congratulations, you got it!\n");
			break;		
		}
		else if (num_user > num_computer)
		{
			printf("Large, continue,please\n");
		}
		else if (num_user < num_computer)
		{
			printf("Small, continue,please\n");
		}
		
	}while(1);	

	return 0;
}
