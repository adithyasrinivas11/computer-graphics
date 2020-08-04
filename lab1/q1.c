#include<stdio.h>

int main()
{
int x[4],y[4]; // coordinates od recatangle
int a,b,c;	//point to be determined
printf("enter  the coordinates od the point");
scanf("%d %d", &a, &b);
int max_x,min_x,max_y,min_y;
c=0;// outside the rectangle
for (int i =0;i<4;i++)
{
	printf("enter 4 points as coordinates o");
	scanf("%d %d", &x[i],&y[i]);
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
int c1=0,c2=0;
if(a<max_x && a>min_x)
	c1=1;
if(b<max_y && b>min_y)
	c2=1;

c=c1*c2;

if(c==0)
	printf("outside the rectagle");
else
	printf("inside the rectagle");






return 0;
}
