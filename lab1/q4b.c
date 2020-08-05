#include<stdio.h>
#include<math.h>
int main()
{
float x[3],y[3],x1[4],y1[4]; // x1 and y1 store the coordinates od the bounding rectangle!
float a,b;
float q,w;
float side1,side2,side3,s1,s2,s3,max;
float slope[3],intercept[3];

float n,m,k,j,distance,qq,l,h,kk,c,d,dd;
//float slope,intercept;
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


slope[0]= (y[1]-y[0])/(x[1]-x[0]);
intercept[0]=y[1]-(slope[0]*x[1]);

slope[1]= (y[2]-y[1])/(x[2]-x[1]);
intercept[1]=y[2]-(slope[1]*x[2]);

slope[2]= (y[2]-y[0])/(x[2]-x[0]);
intercept[2]=y[2]-(slope[2]*x[2]);

// dinding breadth od the rectangle.



if(side1>side2 && side1>side3)
	max =side1;
if(side1<side2 && side2>side3)
	max =side2;
if(side3>side2 && side1<side3)
	max =side3;
if(max == side1)
	{printf("side1");
	
	x1[0]=x[2];
	y1[0]=y[2];
	x1[1]=x[1];
	y1[1]=y[1];
	
	c=x[0];
	d=y[0];
	
	n=slope[1]*c-d+intercept[1];		//ax+by+c=0 dormat
	h=slope[1]*slope[1];
	j=1;
	if(n<0)
		n*=-1;
	m=sqrt(h+j);
	
	distance= n/m;
	
	dd=slope[1];
	k=1/dd;
	k*=-1;
	//kx+c..c?		c=y-kx
	l= y[1]-k*x[1];
	//kx+l 
	qq=1+(k*k);
	qq=1/qq;
	kk=sqrt(qq);
	x1[2]=x[1]+distance*kk;
	y1[2]=y[1]+k*distance*kk;
	
	
	//kx+c..c?		c=y-kx
	l= y[2]-k*x[2];
	//kx+l 
	qq=1+(k*k);
	qq=1/qq;
	kk=sqrt(qq);
	x1[3]=x[2]+distance*kk;
	y1[3]=y[2]+k*distance*kk;
	
	
	printf("(%4.2f,%4.2f) , (%4.2f,%4.2f) , (%4.2f,%4.2f) , (%4.2f,%4.2f) \n",x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
	}
if(max == side2)
	{
	
	printf("side2");
	x1[0]=x[2];
	y1[0]=y[2];
	x1[1]=x[0];
	y1[1]=y[0];
	
	c=x[1];
	d=y[1];
	
	n=slope[2]*c-d+intercept[2];		//ax+by+c=0 dormat
	h=slope[2]*slope[2];
	j=1;
	if(n<0)
		n*=-1;
	m=sqrt(h+j);
	
	distance= n/m;
	
	dd=slope[2];
	k=1/dd;
	k*=-1;
	//kx+c..c?		c=y-kx
	l= y[0]-k*x[0];
	//kx+l 
	qq=1+(k*k);
	qq=1/qq;
	kk=sqrt(qq);
	x1[2]=x[0]+distance*kk;
	y1[2]=y[0]+k*distance*kk;
	
	
	//kx+c..c?		c=y-kx
	l= y[2]-k*x[2];
	//kx+l 
	qq=1+(k*k);
	qq=1/qq;
	kk=sqrt(qq);
	x1[3]=x[2]+distance*kk;
	y1[3]=y[2]+k*distance*kk;
	
	
	printf("(%4.2f,%4.2f) , (%4.2f,%4.2f) , (%4.2f,%4.2f) , (%4.2f,%4.2f) \n",x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
	}
if(max == side3)
	{
	printf("side3");
	x1[0]=x[0];
	y1[0]=y[0];
	x1[1]=x[1];
	y1[1]=y[1];
	
	c=x[2];
	d=y[2];
	
	n=slope[0]*c-d+intercept[0];		//ax+by+c=0 dormat
	h=slope[0]*slope[0];
	j=1;
	if(n<0)
		n*=-1;
	m=sqrt(h+j);
	
	distance= n/m;
	
	dd=slope[0];
	k=1/dd;
	k*=-1;
	//kx+c..c?		c=y-kx
	l= y[0]-k*x[0];
	//kx+l 
	qq=1+(k*k);
	qq=1/qq;
	kk=sqrt(qq);
	x1[2]=x[0]+distance*kk;
	y1[2]=y[0]+k*distance*kk;
	
	
	//kx+c..c?		c=y-kx
	l= y[1]-k*x[1];
	//kx+l 
	qq=1+(k*k);
	qq=1/qq;
	kk=sqrt(qq);
	x1[3]=x[1]+distance*kk;
	y1[3]=y[1]+k*distance*kk;
	
	
	printf("(%4.2f,%4.2f) , (%4.2f,%4.2f) , (%4.2f,%4.2f) , (%4.2f,%4.2f) \n",x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
	//printf("%f**%f ^^^ %f**%f ^^^ %f**%f ^^^ %f**%f\n",x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
	}
	
	

	


/*


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



*/


return 0;
}
