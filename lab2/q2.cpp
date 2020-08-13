#include<graphics.h>
#include<stdio.h> 
#include<stdlib.h> 


int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);




//circle centre x, centre y, radius
circle(250,171,29);

//ellipse: x,y, start angle,end angle, radius x,radius y


//triangle
int tri[]={200,200,250,113,300,200,200,200};
drawpoly(4,tri);


circle(250,171,58);
//rectangle




delay(50000);
closegraph(); 
return 0;

}
