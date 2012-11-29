#include <stdio.h>

int main(void)
{
	int num_A;
	int num_B;

	printf("Please user A input a integer number: ");
	scanf("%d",&num_A);
	
	do
	{
		printf("Please user B guess: ");	
		scanf("%d",&num_B);
		if (num_B == num_A)
		{
			printf("Congratulations, you got it!\n");
			break;		
		}
		else if (num_B > num_A)
		{
			printf("Large, continue,please\n");
		}
		else if (num_B < num_A)
		{
			printf("Small, continue,please\n");
		}
		
	}while(1);	

	return 0;
}
