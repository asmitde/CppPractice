// Hospital Database.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct donors
{
	char name[20], address[40];
	int age, bt;
}donors;

void main()
{
	 FILE *fp;
	 donors hdb;
	 int n,i;
/*
	 fp=fopen("Donors.Txt","w");
	 if(fp==NULL)
	 {
		 printf("\nFile Cannot be opened.");
		 getch();
		 exit(1);
	 }

	 printf("Enter the number of records: "); scanf("%d",&n);

	 for(i=1;i<=n;i++)
	 {
		 fflush(stdin);
		 printf("\nRecord #%d: ",i);
		 printf("\nEnter name: "); gets(hdb.name);
		 printf("Enter address: "); gets(hdb.address);
		 printf("Enter age: "); scanf("%d",&hdb.age);
		 printf("Enter bloodtype: "); scanf("%d",&hdb.bt);

		 fprintf(fp,"%-20s%-40s%2d %1d\n",hdb.name,hdb.address,hdb.age,hdb.bt);
	 }
	 printf("\nRecords entered successfully..."); getch();
	 fclose(fp);
*/
	 fp=fopen("Donors.Txt","r");
	 if(fp==NULL)
	 {
		 printf("\nFile Cannot be opened.");
		 getch();
		 exit(1);
	 }

	 puts("\n\nList of donors below age 25 and of blood type 2:\nName\t\tAddress");

	 while(!feof(fp))
	{
		fscanf(fp,"%40s%20s%2d%1d",hdb.name,hdb.address,&hdb.age,&hdb.bt);
		if(hdb.age<25 && hdb.bt==2)
			 printf("%s\t\t%s\n",hdb.name,hdb.address);
	 }

	 fclose(fp);

	 getch();
}

