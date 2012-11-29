#include <stdio.h>

void fenjie(int num);

int main(void)
{
	int num;
	printf("Please input a number: ");
	scanf("%d",&num);
	fenjie(num);
	return 0;
}

void fenjie(int num)
{
	if (num < 0)
	{
		num = -num;
	}

	while (num != 0)
	{
		printf("\t%d\t",num%10);
		num /= 10;
	}
	printf("\n");	
}









