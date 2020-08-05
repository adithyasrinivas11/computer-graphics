#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float findArea(float a, float b, float c) 
{ 
    static int x=0;
    //printf("\n%d",++x);
    // Length of sides must be positive and sum of any two sides 
    // must be smaller than third side. 
    if (a < 0 || b < 0 || c <0 || (a+b <= c) || a+c <=b || b+c <=a) 
    { 
        return 0;
        //printf("Not a valid triangle"); 
        //exit(0); 
    } 
    float s = (a+b+c)/2; 
    return sqrt(s*(s-a)*(s-b)*(s-c)); 
} 

int main()
{

float x[3],y[3];
float a,b,c=0,c1=0,c2=0;
float max_x,min_x,max_y,min_y;
float area_of_triangle,area_small_triangle1,area_small_triangle2,area_small_triangle3;
float side1,side2,side3,s1,s2,s3;
float q,w;


for (int i =0;i<3;i++)
{
	printf("enter 3 points as coordinates x y:  ");
	scanf("%f %f", &x[i],&y[i]);
	
	if(i==0)
	{
		max_x=x[0];
		min_x=x[0];
		max_y=y[0];
		min_y=y[0];
	}
	else 
	{
		if(max_x < x[i])
			max_x =x[i];
		if(min_x > x[i])
			min_x =x[i];
		if(max_y < y[i])
			max_y =y[i];
		if(min_y > y[i])
			min_y =y[i];
			
	}
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

printf("%f   %f   %f",side1,side2,side3);
area_of_triangle=findArea(side1,side2,side3);

for(int i=min_x;i<= max_x;i++)
{
	for(int j=min_y;j<= max_y;j++)
	{
		a=i;
		b=j;
		
		//printf("==>%f   %f \n",min_y,max_y);
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
		
		area_small_triangle1= findArea(side1,s1,s2);
		area_small_triangle2= findArea(side2,s1,s3);
		area_small_triangle3= findArea(side3,s3,s2);


		printf("==>%f   %f     %f     %f\n",area_small_triangle1,area_small_triangle2,area_small_triangle3,area_of_triangle);
		
		if (area_of_triangle < area_small_triangle1+ area_small_triangle2+ area_small_triangle3)
			{
			printf("(%2.0f,%3.0f) is outside the triangle\n",a,b);
			}
		else
			{
			printf("(%2.0f,%3.0f) is inside the triangle\n",a,b);
			c++;
			}
		
			
	}
}
	

printf(" number od integer points inside triangle%2.0f",c);
return 0;
}
