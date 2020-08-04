#include<stdio.h>

int main()
{
float x[3],y[3];
float a,b,c,c1=0,c2=0;

float max_x,min_x,max_y,min_y;

printf("enter the points to be checked as coordinates x,y:  ");
	scanf("%f %f", &a,&b);

float slope,intercept;
for (int i =0;i<3;i++)
{
	printf("enter 2 points as coordinates x y:  ");
	scanf("%f %f", &x[i],&y[i]);
	
	if(i==0)
	{
		max_x=x[0];
		min_x=x[0];
		max_y=y[0];
		min_y=y[0];
	}
	else if(max_x < x[i])
		max_x =x[i];
	else if(min_x > x[i])
		min_x =x[i];
	else if(max_y < y[i])
		max_y =y[i];
	else if(min_y > y[i])
		min_y =y[i];
}

if(a< max_x && a> min_x)
	c1=1;
if(b< max_y && b> min_y)
	c2=1;
c=c1*c2;

if(c==0)
	printf("outside the triangle\n");
else
	printf("inside the triangle\n");

}
