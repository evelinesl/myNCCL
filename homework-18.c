/*--------------------homework-18-1.c-----------------------*/

/*实现一个可变长度参数的 max 函数，可以求出任意多传入参数中的最大值
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

int max(int n, ...)
{
	int i;
	int max;
	va_list p;

	va_start(p, n);
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			max = va_arg(p, int);
			continue;
		}
		else
		{
			int tmp = va_arg(p, int);
			if (max < tmp)
			{
				max = tmp;
			}
		}
	}

	va_end(p);
	return max;
}

int main(void)
{
	printf("MAX is %d\n", max(3, 100, 200, 300));
}

/*--------------------homework-18-2.c-----------------------*/

/*•在 myprintf 的基础上，实现一个 mysprintf 函数
 * 
 *main.c
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void putchar_hex(char c, char **str)
{
    const char * hex = "0123456789ABCDEF";

    **str = hex[(c & 0xf0)>>4];
	(*str)++;
    **str = hex[(c & 0x0f)>>0];
	(*str)++;
}

void putint_hex(int a, char **str)
{
    putchar_hex( (a>>24) & 0xFF, str);
    putchar_hex( (a>>16) & 0xFF, str);
    putchar_hex( (a>>8) & 0xFF, str );
    putchar_hex( (a>>0) & 0xFF, str );
}

char * itoa(int num, char * buf)
{   
    int i = 0;
    int len = 0;

    do 
    {
        buf[i++] = num % 10 + '0';
        num /= 10;      
    } while (num);
    buf[i] = '\0';

    len = i;
    for (i = 0; i < len/2; i++)
    {
        char tmp;
        tmp = buf[i];
        buf[i] = buf[len-i-1];
        buf[len-i-1] = tmp;
    }

    return buf; 
}

int mysprintf(char *str, const char *format, ...)
{
    char c;

    va_list ap;

    va_start(ap, format);

    while ((c = *format++) != '\0')
    {
        switch (c)
        {
            case '%':
                c = *format++;

                switch (c)
                {
                    char ch;
                    char * p;
                    int a;

                    case 'c':
                        ch = va_arg(ap, int);
                        *str = ch;
						str++;
                        break;
                    case 's':
                        p = va_arg(ap, char *);
                        strcpy(str, p);
						str += strlen(p);
                        break;                  
                    case 'x':
                        a = va_arg(ap, int);
                        putint_hex(a, &str);
                        break;      
                    case 'd':
                        a = va_arg(ap, int);
                        itoa(a, str);
						str += strlen(str);
                        break;  
                    default:
                        break;
                }               
                break;      

            default:
				*str = c;
				str++;
                break;
        }
    }

	*str = '\0';

    return 0;   
}

int main(void)
{
    char buf[100];
	mysprintf(buf, "test: %c, %s, %d, 0x%x\n", 'A', "abcdef", 11, 0x23);

	printf("%s\n", buf);
}