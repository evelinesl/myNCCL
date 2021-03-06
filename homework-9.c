/*---------------homework-9-1------------------------------*/

/*
 * main.c -Judge whether a string is a palindrome string  or not
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0

/*
 * is_palindrome - Judge whether a string is a palindrome string  or not
 * @len:    the length of the string
 * @buf[]:  the string
 *
 * Return value: TRUE　or FALSE
 *
 */

int is_palindrome(int len, char buf[])
{
	int i;

	for (i = 0; i < len/2; i++)
    {
        if (buf[i] != buf[len-i-1])
		{
			break;
		}
    }

	if (i == len/2)
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
	char str[100] ={'\0'};

	printf("Please input a string: ");
	scanf("%s", str);

	if (is_palindrome(strlen(str),str))
	{
		printf("\nSring %s is a palindrome string\n", str);
	}
	else
	{
		printf("\nSring %s is not a palindrome string\n", str);
	}

	return 0;
}

/*---------------homework-9-2------------------------------*/

/*
 * main.c - •使用字符数组实现基于数字字符串的加减法
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <string.h>

/*
 * string_add - Add two string
 * @len1:    the length of the string
 * @str1[]:  the string
 * @len2:    the length of the string
 * @str2[]:  the string
 * @result_str[]:  
 * Return value: void
 *
 */

void string_add(int len1, char str1[], int len2, char str2[], char result_str[])
{
	int i, j, k;
	int flag = 0;

	k = 0;
	for (i = len1, j = len2; i > 0 && j > 0; i--, j--)
	{
		if ((str1[i-1] - '0') + (str2[j-1] - '0') > 9)
		{
			result_str[k++] = (str1[i-1] - '0') + (str2[j-1] - '0') - 10 + '0' + flag;
			flag = 1;
		}
		else
		{
			result_str[k++] = (str1[i-1] - '0') + (str2[j-1] - '0') + '0' + flag;
			flag = 0;
		}
	}

	if (i != 0)
	{
		do
		{
			if (str1[i] - '0' + flag > 9)
			{
				result_str[k++] = (str1[i-1] - '0') - 10 + '0' + flag;
				flag = 1;
			}
			else
			{
				result_str[k++] = (str1[i-1] - '0') + '0' + flag;
				flag = 0;
			}

		}while (i--);
	}

	if (j != 0)
	{
		do
		{
			if (str2[j] - '0' + flag > 9)
			{
				result_str[k++] = (str2[j-1] - '0') - 10 + '0' + flag;
				flag = 1;
			}
			else
			{
				result_str[k++] = (str2[j-1] - '0') + '0' + flag;
				flag = 0;
			}

		}while (j--);
	}

	if (flag == 1)
	{
		result_str[k] = '0' + flag;
	}
	
	return;
}

/*
 * reverse_string - reverse a string
 * @len:    the length of the string
 * @buf[]:  the string  
 * Return value: void
 *
 */
void reverse_string(int len, char buf[])
{
	int i;

    for (i = 0; i < len/2; i++)
    {   
        buf[i] = buf[i] + buf[len-i-1];
        buf[len-i-1] = buf[i] - buf[len-i-1];
        buf[i] = buf[i] - buf[len-i-1];
    }
	
	return;
}


int main(void)
{
	char str1[100] = {'\0'};
	char str2[100] = {'\0'};
	char str_result[200] = {'\0'};

	int len1, len2, len3;
	
	printf("Please input the first string: ");
	scanf("%s", str1); 
	printf("Please input the second string: ");
	scanf("%s", str2); 
	
	len1 = strlen(str1);
	len2 = strlen(str2);
	string_add(len1, str1, len2, str2, str_result);

	len3 = strlen(str_result);
	reverse_string(len3, str_result);

	printf("\n %s add %s is equal to %s\n", str1, str2, str_result);

	return 0;
}


/*---------------homework-9-3------------------------------*/

/*
 * main.c -去字符串多余空格
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <string.h>

#define TRUE  1
#define FALSE 0
/*
 * remove_space - remove the excessive spaces
 * @len:    the length of the string
 * @buf[]:  the string  
 * Return value: void
 *
 */

void remove_space(int len, char buf[])
{
	int begin_flag = FALSE;
	int i, j;

	for (i = 0, j = 0; i < len; i++)
	{
		if (buf[i] != ' ')
		{
			buf[j++] = buf[i]; 
			begin_flag = FALSE;
			continue;
		}
		if (buf[i] == ' ' && begin_flag == FALSE)
		{
			buf[j++] = buf[i]; 
			begin_flag = TRUE;
			continue;
		}

		if (buf[i] == ' ' && begin_flag == TRUE)
		{
			continue;
		}
	}

	buf[j] = '\0';
	
	return;
}

int main(void)
{
	char str[100] = {'\0'};
	int len;
	
	printf("Please input the string: ");
	gets(str); 
	
	printf("Before removing the excessive spaces %s \n", str);

	len = strlen(str);
	remove_space(len, str);

	printf("After removing the excessive spaces %s \n", str);

	return 0;
}