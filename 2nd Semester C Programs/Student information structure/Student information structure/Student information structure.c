// Student information structure.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 450

typedef struct student
{
	int roll, year;
	char name[40],dept[4],course[10];
}student;

void studlist(int y,student list[],int n);
void studdata(int r,student list[],int n);

void main()
{
	int n, year, rollno, i; char ch; student list[MAX];

	printf("Enter the total number of entries: "); scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("\nStudent #%d:",i+1);
		printf("\nEnter roll no: "); scanf("%d",&list[i].roll);
		fflush(stdin);
		printf("Enter name: "); gets(list[i].name);
		printf("Enter course: "); gets(list[i].course);
		printf("Enter department: "); gets(list[i].dept);
		printf("Enter year of join: "); scanf("%d",&list[i].year);
		fflush(stdin);
	}

	while(1)
	{
		printf("\n\nEnter l to display list of students of a particular year\nEnter d to display information of a particular student\nEnter x to exit... "); ch=getche();

		switch(ch)
		{
		case 'l':
		case 'L':
			printf("\nEnter year of join: ");
			scanf("%d",&year);
			studlist(year,list,n);
			break;
		case 'd':
		case 'D':
			printf("\nEnter roll no: ");
			scanf("%d",&rollno);
			studdata(rollno,list,n);
			break;
		case 'x':
		case 'X':
			exit(EXIT_SUCCESS);
		default:
			printf("\nInvalid entry");
		}
	}

	getch();
}

void studlist(int y,student list[],int n)
{
	int i;
	printf("\nStudents of year %d:",y);
	for(i=0;i<=n-1;i++)
		if(list[i].year==y)
			printf("\n%s",list[i].name);
}

void studdata(int r,student list[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		if(list[i].roll==r)
		{
			printf("\nRoll no: %d",list[i].roll);
			printf("\nName: %s",list[i].name);
			printf("\nCourse: %s",list[i].course);
			printf("\nDepartment: %s",list[i].dept);
			printf("\nYear of join: %d",list[i].year);
			break;
		}
}