/*--------------------homework-22.c-----------------------*/

/*
 * main.c ��������Ϸ�������������4λ����Ȼ���û�����4λ�������Ը�������?A?B
 *�������³����Ե�4λ���Ƕ��٣�
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