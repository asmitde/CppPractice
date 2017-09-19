#include<stdio.h>
#include<conio.h>

void main()
{
	double a=0.01,b=0.005,c=0.00001,d=0.01,R=1,W=62.25,Rt,Wt;
	int i;
	
	for(i=1;i<=1000;i++)
	{
		Rt=(1+a)*R-c*R*W;
		Wt=(1-b)*W+c*d*R*W;

		R=Rt,W=Wt;
		
		if(i%25==0)
			printf("Day %d : Rabbits = %.0lf , Wolves = %.0lf\n",i,R,W);
	}
	
	getch();
}