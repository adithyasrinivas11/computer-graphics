#include<stdio.h>

int main()
{
float x[3],y[3];
float a,b,c,c1=0,c2=0,c0=0;

float max_x,min_x,max_y,min_y;

printf("enter the points to be checked as coordinates x,y:  ");
	scanf("%f %f", &a,&b);

float slope[3],intercept[3];
for (int i =0;i<3;i++)
{
	printf("enter 2 points as coordinates x y:  ");
	scanf("%f %f", &x[i],&y[i]);
	
}

slope[0]= (y[1]-y[0])/(x[1]-x[0]);
intercept[0]=y[1]-(slope[0]*x[1]);

slope[1]= (y[2]-y[1])/(x[2]-x[1]);
intercept[1]=y[2]-(slope[1]*x[2]);

slope[2]= (y[2]-y[0])/(x[2]-x[0]);
intercept[2]=y[2]-(slope[2]*x[2]);

printf("%fx+%f     %fx+%f        %fx+%f	\n",slope[0],intercept[0],slope[1],intercept[1],slope[2],intercept[2]);

float y2,y1,y0,y22,y11,y00;
y2= slope[0]*a+intercept[0];
y22=slope[0]*x[2]+intercept[0];

y1= slope[1]*a+intercept[1];
y11=slope[1]*x[0]+intercept[1];

y0= slope[2]*a+intercept[2];
y00=slope[2]*x[1]+intercept[2];

//printf("%f---%f     %f---%f        %f---%f",y2,y22,y1,y11,y0,y00);

// check id the point to be checked and the 3rd point are both in same side wrt the line got by joining 1st and 2nd points
if((y2>b && y22>y[2]) || (y2<b && y22<y[2]))
	c2=1;
if((y1>b && y11>y[0]) || (y1<b && y11<y[0]))
	c1=1;
if((y0>b && y00>y[1]) || (y0<b && y00<y[1]))
	c0=1;
	
c=c0*c1*c2;

if(c==0)
	printf("outside the triangle\n");
else
	printf("inside the triangle\n");

}
