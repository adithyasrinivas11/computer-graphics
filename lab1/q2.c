#include<stdio.h>

int main()
{
float x[2],y[2];
float a,b;

printf("enter the points to be checked as coordinates x,y:  ");
	scanf("%f %f", &a,&b);

float slope,intercept;
for (int i =0;i<2;i++)
{
	printf("enter 2 points as coordinates x y:  ");
	scanf("%f %f", &x[i],&y[i]);
}

slope= (y[1]-y[0])/(x[1]-x[0]);

//printf("-- %f%f    %f\n",(y[1]-y[0]),(x[1]-x[0]),(-2/-5));
intercept=y[1]-(slope*x[1]);

printf("equation of the line :: %fx+%f",slope,intercept);

float y3;
y3= slope*a+intercept;

if(y3>b)
	printf("\ninside the line");
else
	printf("\noutside the line");

}
