#include <stdio.h>

int global_1;
int global_2;
int global_3;

int   global_int;
short global_short;
char  global_char;
float global_float;

int main(void)
{
    int local_1;
    int local_2;
    int local_3;
   printf("------question1------\n");
    printf("---Global----\n");
	/*连续的三个全局变量的地址前两个全局变量会从高到低，最后一个地址最小，小于前面两个*/
    printf("global_1 = %p\n",&global_1);
    printf("global_2 = %p\n",&global_2);
    printf("global_3 = %p\n",&global_3);

    printf("---Local----\n");
	/*连续的三个局部变量的地址根据定义的的先后顺序，地址依次从高到低，*/
    printf("local_1 = %p\n",&local_1);
    printf("local_2 = %p\n",&local_2);
    printf("local_3 = %p\n",&local_3);

    printf("-----question2-----\n");
	/*int类型全局变量地址加1的值相当于在原来地址的基础上加了4*/
    printf("global_int=%d &global_int+1=%d\n",(int)&global_int,(int)(&global_int+1));

    printf("-----question3-----\n");
		/*char类型全局变量地址加1的值相当于在原来地址的基础上加了1*/
    printf("global_char=%d   &global_char+1=%d\n",(int)&global_char,(int)(&global_char+1));
		/*short形全局变量地址加1的值相当于在原来地址的基础上加了2*/
    printf("global_short=%d  &global_short+1=%d\n",(int)&global_short,(int)(&global_short+1));
		/*float类型全局变量地址加1的值相当于在原来地址的基础上加了4*/
    printf("global_float=%d  &global_float+1=%d\n",(int)&global_float,(int)(&global_float+1));
    

 return 0;
}   
