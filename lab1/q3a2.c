#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float findArea(float a, float b, float c) 
{ 
    // Length of sides must be positive and sum of any two sides 
    // must be smaller than third side. 
    if (a < 0 || b < 0 || c <0 || (a+b <= c) || a+c <=b || b+c <=a) 
    { 
        printf("Not a valid triangle"); 
        exit(0); 
    } 
    float s = (a+b+c)/2; 
    return sqrt(s*(s-a)*(s-b)*(s-c)); 
} 


int main()
{
float x[3],y[3];
float a,b,c,c1=0,c2=0;

float max_x,min_x,max_y,min_y;

float side1,side2,side3,s1,s2,s3;
float q,w;

float area_of_triangle,area_small_triangle1,area_small_triangle2,area_small_triangle3;
printf("enter the points to be checked as coordinates x,y:  ");
	scanf("%f %f", &a,&b);

float slope,intercept;
for (int i =0;i<3;i++)
{
	printf("enter 2 points as coordinates x y:  ");
	scanf("%f %f", &x[i],&y[i]);
	
}

q=x[2]-x[1];
w=y[2]-y[1];
q*=q;
w*=w;
side1 =sqrt(q+w);

q=x[2]-x[0];
w=y[2]-y[0];
q*=q;
w*=w;
side2 =sqrt(q+w);

q=x[0]-x[1];
w=y[0]-y[1];
q*=q;
w*=w;
side3 =sqrt(q+w);

q=x[2]-a;
w=y[2]-b;
q*=q;
w*=w;
s1 =sqrt(q+w);

q=x[1]-a;
w=y[1]-b;
q*=q;
w*=w;
s2 =sqrt(q+w);

q=x[0]-a;
w=y[0]-b;
q*=q;
w*=w;
s3 =sqrt(q+w);

area_of_triangle=findArea(side1,side2,side3);

area_small_triangle1= findArea(side1,s1,s2);
area_small_triangle2= findArea(side2,s1,s3);
area_small_triangle3= findArea(side3,s3,s2);

if (area_of_triangle = area_small_triangle1+ area_small_triangle2+ area_small_triangle3)
	printf("inside the triangle");
else
	printf("outside the triangle");

return 0;
}


