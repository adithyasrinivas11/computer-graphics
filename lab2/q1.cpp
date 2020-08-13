#include<graphics.h>
#include<stdio.h> 
#include<stdlib.h> 
#include<iostream>
using namespace std;

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
int x;

cout<<"1.point 2.line 3.circle 4.ellipse 5.triangle 6.rectangle\n";
cin>>x;

switch(x)
{
	case 1:
		{
		putpixel(100,100,GREEN);
		putpixel(200,200,RED);
		putpixel(300,300,BLUE);
		break;
		}
	case 2:
		{
		line(0,0,200,200);
		break;}
	case 3:
		{//circle centre x, centre y, radius
		circle(300,200,50);
		break;
		}
	case 4:
		{//ellipse: x,y, start angle,end angle, radius x,radius y
		ellipse(200,400,0,360,25,75);
		break;
		}
		
	case 5:
		{
		//triangle
		int tri[]={400,300,420,450,370,300,400,300};
		drawpoly(4,tri);
		break;
		}
	case 6:
		{
		//rectangle
		rectangle(450,200,480,400);
		break;
		}
		
	default :
		break;

}





delay(50000);
closegraph(); 
return 0;

}
