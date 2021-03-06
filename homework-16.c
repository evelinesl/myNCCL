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
#include <assert.h>
#include <string.h>

int my_strlen(const char* str)
{
	unsigned v;   
	const char *p = str;  
	const unsigned *longword_ptr; 


    while (*p && ((unsigned)p & 3))   //对齐 32位
	{
        p++;
	}
    
	if (*p == 0)   
	{
        return (p - str);
	}

	longword_ptr = (unsigned *)p;

    for (v = 0; !v; longword_ptr++)  
    {   
        v = (*longword_ptr - 0x01010101) & 0x80808080;   
        
		if (v) 
		{
            const char *cp = (const char*)(longword_ptr);
			
			if (cp[0] == '\0')
			{
				return cp - str;
			}
            if (cp[1] == 0)
			{
                return cp - str + 1; 
			}
            if (cp[2] == 0) 
			{
                return cp - str + 2; 
			}
            if (cp[3] == 0)
			{
                return cp - str + 3;
			}
		}
    }     
}

int main(void)
{
	char *str = "sdfas3er fsffre";

	printf("strlen %d my_strlen %d \n", strlen(str), my_strlen(str));
	return 0;
}