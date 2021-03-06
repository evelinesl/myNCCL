/*--------------------homework-17-1.c-----------------------*/

/*把发现的单词进行保存和输出
 * 
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define MAX_NUM   100

int get_input_type(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 1;

    return 0;
}

int main(void)
{
	char  str[] = "Don't ask what your country can do for you, but ask what you can do for your country.";
	char *str_tmp = str;
    char c;
	char *words[MAX_NUM];

    int state = 0;  // init state
    int input = 0;  // 0: space     1: alpha
    int counter = 0;

    printf("hello, count how many words in string:\n");
    printf("<%s>\n", str);

	while ((c = *str_tmp++) != '\0')
    {
        input = get_input_type(c);          

        if (state == 0 && input == 1)
		{
            state = 1;
			words[counter] = str_tmp - 1;
			printf("%c", c);
		}
		else if (state == 1 && input == 1)
		{
			printf("%c", c);
		}
        else if (state == 1 && input == 0)
        {
            *(str_tmp - 1) = '\0';
			counter++;
            state = 0;
			printf("\n");
        } 
    }

    printf("find %d words.\n", counter);

	return 0;
}


/*--------------------homework-17-2.c-----------------------*/

/*改用 switch-case实现单词统计程序
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#define MAX_NUM   100
#define MAX_LEN   50

int get_input_type(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        return 1;

    return 0;
}

int main(void)
{
	char * str = "Don't ask what your country can do for you, but ask what you can do for your country.";
    char c;
	char words[MAX_NUM][MAX_LEN];

    int state = 0;  // init state
    int input = 0;  // 0: space     1: alpha
    int counter = 0;
	int len = 0;

    printf("hello, count how many words in string:\n");
    printf("<%s>\n", str);

	while ((c = *str++) != '\0')
    {
        input = get_input_type(c);          

        switch (input)
		{
			case 1: 
				switch (state)
				{
					case 0: 
						state = 1;
						words[counter][len++] = c;
						printf("%c", c);
						break;
					case 1:
						words[counter][len++] = c;
						printf("%c", c);
						break;
					default:
						break;
				}
				break;
			case 0: 
				switch (state)
				{
					case 0: 
						break;
					case 1:
						words[counter][len++] = '\0';
						len = 0;
						counter++;
						state = 0;
						printf("\n");
						break;
				}
				break;
			default:
				break;
		}
    }

    printf("find %d words.\n", counter);

	return 0;
}

/*--------------------homework-17-3.c-----------------------*/

/*统计字符串中数字的个数
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

int get_input_type(char c)
{
    if (c >= '0' && c <= '9')
        return 1;

    return 0;
}

int main(void)
{
    char * str = "Don't as987k wh87at yo456ur coun32try ca557n do for you, but ask wha9t you88 can d674o for y90our country.";
    char c;

    int state = 0;  // init state
    int input = 0;  // 0: space     1: alpha
    int counter = 0;

    printf("hello, count how many words in string:\n");
    printf("<%s>\n", str);

    while ((c = *str++) != '\0')
    {
        input = get_input_type(c);          

        if (state == 0 && input == 1)
		{
            state = 1;
		}
        else if (state == 1 && input == 0)
        {
            counter++;
            state = 0;
        } 
    }

    printf("find %d numbers.\n", counter);

    return 0;
}