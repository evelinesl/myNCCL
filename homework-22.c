/*--------------------homework-22.c-----------------------*/

/*
 * main.c —猜数游戏：电脑随机产生4位数，然后用户输入4位数，电脑告诉你是?A?B
 *请你最后猜出电脑的4位数是多少？
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */
enum {UP, DOWN, LEFT, RIGHT, LEFT_UP, LEFT_DOWN, RIGHT_UP, RIGHT_DOWN};

struct point
{
	int i;
	int j;
}dir[8];