/*---------------homework-5-1------------------------------*/

#include <stdio.h>

#define MAX_NUM 5

int main(void)
{
    int input_num, sum = 0;
    int i;

     printf("Please input %d numbers: ", MAX_NUM);
     for (i = 0; i < MAX_NUM; i++ )
     {
        scanf("%d", &input_num);
        sum += input_num;
     }
     printf("\n");
     printf("Average of %d numbers is %f\n", MAX_NUM, sum*1.0/MAX_NUM);

	 return 0;
}

/*---------------homework-5-2------------------------------*/
#include <stdio.h>

#define MAX_NUM 5

int main(void)
{
    int input_num, max;
    int i;

     printf("Please input %d numbers: ", MAX_NUM);

     for (i = 0; i < MAX_NUM; i++ )
     {
        scanf("%d", &input_num);
        if (i == 0)
		{
			max = input_num;
			continue;
		}
		else
		{
			if (max < input_num)
			{
				max = input_num;
			}
		}
     }

     printf("\n");
     printf("Maximum of %d numbers is %d\n", MAX_NUM, max);
    
	 return 0;
}

/*------------------homework-5-3------------------------*/
#include <stdio.h>

#define MONTH_DAY 30

int main(void)
{	
     enum{Sun, Mon, Tue, Wed, Thu, Fri, Sat};
     int first_day = Thu;	
     int day_amount = MONTH_DAY;	
     int i;	
     
     printf (" Sun\tMon\tTue\tWed\tThu\tFri\tSat");	
     for (i = 0; i < day_amount+first_day; i++)
     {		
          if (i%7 == 0)			
              printf("\n");		
          if (i < first_day)			
              printf("\t");		
          else 			
              printf(" %2d\t", i - first_day + 1);	
     }	

     printf ("\n");	
     return 0;
}
