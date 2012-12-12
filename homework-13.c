/*--------------------homework-13-1.c-----------------------*/

/*
 * main.c -Statistic the character
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */


#include <stdio.h>

void statistic(char buf[])
{
	int digit[10] = {0};
	int space = 0;
	int other_char = 0;
	int line = 1;
	int i;

	for (i = 0; buf[i]; i++)
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			digit[buf[i] - '0']++;
			continue;
		}
		if (buf[i] == ' ')
		{
			space++;
			continue;
		}
		if (buf[i] == '\n')
		{
			line++;
			continue;
		}

		other_char++;
	}
	
	for (i = 0; i < 10; i++)
	{
		printf("Digit %d : %d\n", i, digit[i]);
	}
	printf("Space : %d\n", space);
	printf("Other_char : %d\n", other_char);
	printf("Line : %d\n", line);

	return;
}

int main(void)
{
	char buf[] = "sass  asf32f33rdewe f fassaf\nsa3rgykk;.,/er3efb4t5k\njr[]fv./xlfg3rj45e30398\ni32cmf,.d.em3wk";

	statistic(buf);
	return 0;
}  

/*--------------------homework-13-2.c-----------------------*/

/*
 * main.c -Statistic the number of format of a piece of printf statement
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */


#include <stdio.h>


void statistic(char buf[])
{
	int num_d = 0;
	int num_c = 0;
	int num_s = 0;
	int num_p = 0;
	int i;
	int start_flag;

	for (i = 0; buf[i]; i++)
	{
		if (buf[i] == '%')
		{
			switch (buf[i + 1])
			{
				case 'd':
					num_d++;
					break;
				case 'c':
					num_c++;
					break;
				case 's':
					num_s++;
					break;
				case 'p':
					num_p++;
					break;
				default:
					break;
			}
		}
	}
	
	printf("%%d : %d\n", num_d);
	printf("%%c : %d\n", num_c);
	printf("%%s : %d\n", num_s);
	printf("%%p : %d\n", num_p);

	return;
}

int main(void)
{
	char buf[] = "printf(\" Test %d 123 %c address %p %s %p %f %s \", 123, \"sdfsd\", &p, 3.0)";

	statistic(buf);
	return 0;
}  