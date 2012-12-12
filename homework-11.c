/*--------------------homework-11-1.c-----------------------*/

/*
 * main.c -Compute the max distance
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NUM 5

typedef struct point
{
	double x;
	double y;
}point_t;

int main(void)
{
	point_t  point[TOTAL_NUM];
	int i;
	double max_distance = 0.0;
	int max;
     
	/*-------------Generate the point coordination automatically-----------------*/
	srand((unsigned)time(NULL));
	for (i = 0; i < TOTAL_NUM; i++)
	{
		point[i].x = rand() % 100 * 1.0;
		point[i].y = rand() % 100 * 1.0;
	}

	for (i = 0; i < TOTAL_NUM; i++)
	{
		double distance = sqrt(point[i].x * point[i].x + point[i].y * point[i].y);

		if (max_distance < distance)
		{
			max_distance = distance;
			max = i;
		}
	}

	printf("The farthest point is at (%.2f, %.2f) and the max distance is %.2f\n", point[max].x, point[max].y, max_distance);

	return 0;
}       

/*--------------------homework-10-2.c-----------------------*/

/*
 * main.c -Find the two point that have the max distance between them 
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NUM 5
typedef struct point
{
	double x;
	double y;
}point_t;

int main(void)
{
	point_t  point[TOTAL_NUM];
	int i, j;
	double max_distance = 0.0;
	int point_1;
	int point_2;
     
	/*-------------Generate the point coordination automatically-----------------*/
	srand((unsigned)time(NULL));
	for (i = 0; i < TOTAL_NUM; i++)
	{
		point[i].x = rand() % 100 * 1.0;
		point[i].y = rand() % 100 * 1.0;
	}

	/*---------------------------Compute the max distance-------------------------*/
	for (i = 0; i < TOTAL_NUM; i++)
	{
		for (j = i + 1; j < TOTAL_NUM; j++)
		{
			double tmp1 = point[i].x - point[j].x;
			double tmp2 = point[i].y - point[j].y;
			double distance = sqrt(tmp1 * tmp1 + tmp2 * tmp2);

			 if (max_distance < distance)
			{
				max_distance = distance;
				point_1 = i;
				point_2 = j;
			}
		}
	}

	printf("The max distance is %.2f between (%.2f, %.2f) and (%.2f, %.2f)\n", 
		max_distance, point[point_1].x, point[point_1].y, point[point_2].x, point[point_2].y);

	return 0;
}  

/*--------------------homework-10-3.c-----------------------*/

/*
 * main.c -Student information management system
 *
 * Copyright (C) Shi Lei <shilei791207@vip.163.com>
 * 
 */

#include <stdio.h>

#include <string.h>

#define STUDENT_NUM 5

typedef struct score
{
	float math;
	float chemistry;
	float physics;
}score_t;

typedef struct student
{
	int student_id;
	char name[10];
	score_t course_score;
}student_t;

void score_entry(int num, student_t student[])
{
	int i;

	printf("Please input %d students information and their scores: \n", num);
	for (i = 0; i < num; i++)
	{
		printf("%d student \n", i + 1);
		printf("\t ID: ");
		scanf("%d", &student[i].student_id);
		printf("\t Name: ");
		scanf("%s", student[i].name);
		printf("\t Score: Math   Chemistry   Physics\n\t");
		scanf("%f %f %f", &student[i].course_score.math, &student[i].course_score.chemistry, &student[i].course_score.physics);
	}

	return;
}

void print(int num, student_t student[])
{
	int i;

	printf("  Student ID\tName\tMath\tChemistry\tPhysics\tTotal\tAverage\n");
	for (i = 0; i < num; i++)
	{
		float math = student[i].course_score.math;
		float chemistry = student[i].course_score.chemistry;
		float physics = student[i].course_score.physics;
		float total = math + chemistry + physics;
		float average = total / 3.0;

		printf("%d  %d       \t%s\t%.2f \t%.2f      \t%.2f\t%.2f\t%.2f\n", 
			i + 1, student[i].student_id, student[i].name, 
			math, chemistry, physics, total, average);
	}

	return;
}

void score_query(int num, student_t student[])
{
	int student_id;
	char student_name[10];
	int i;
	int query_type;

	printf("Please select the type for query: 1: Student ID  2: Student:  ");
	scanf("%d", &query_type);

	switch (query_type)
	{
		case 1: 
			printf("Please inupt student ID: ");
			scanf("%d", &student_id);
			break;
		case 2:
			printf("Please input student name: ");
			scanf("%s", student_name);
			break;
		default:
			break;
	}

	for (i = 0; i < num; i++)
	{
		if (query_type == 1)
		{
			if (query_type == 1 ? student_id == student[i].student_id : strcmp(student_name, student[i].name) == 0)
			{
				float math = student[i].course_score.math;
				float chemistry = student[i].course_score.chemistry;
				float physics = student[i].course_score.physics;
				float total = math + chemistry + physics;
				float average = total / 3.0;
				
				printf("Student ID\tName\tMath\tChemistry\tPhysics\tTotal\tAverage\n");
				printf("%d        \t%s\t%.2f \t%.2f    \t%.2f\t%.2f\t%.2f\n", 
					student[i].student_id, student[i].name, 
					math, chemistry, physics, total, average);
				break;
			}
		}
	}
	
	if (i == num)
	{
		printf("Query Fail!\n");
	}

	return;
}

int main(void)
{
	student_t student[STUDENT_NUM];
	int i;
    
	while (1)
	{
		printf("\n**************Student Information Management System***************\n");
		printf("*               1. Student Score Entry                           *\n");
		printf("*               2. Student Score Print                           *\n");
		printf("*               3. Student Score Query                           *\n");
		printf("*               4. Exit                                          *\n");

		printf("Please input (1-4): ");
		scanf("%d", &i);
		switch(i)
		{
			case 1: 
				score_entry(STUDENT_NUM, student);
				break;
			case 2: 
				print(STUDENT_NUM, student);
				break;
			case 3: 
				score_query(STUDENT_NUM, student);
				break;
			case 4: 
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}       

