#include<graphics.h>
#include<stdio.h> 
#include<stdlib.h> 


int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);


//setcolor(YELLOW); 

////circle centre x, centre y, radius
//circle(350,200,50);

//setfillstyle(SOLID_FILL, YELLOW); 
//ellipse: x,y, start angle,end angle, radius x,radius y
    setcolor(YELLOW); 
	circle(300, 300, 50); 
    //setfillstyle(SOLID_FILL, YELLOW); 
    floodfill(300, 300, YELLOW); 
  
    // Set color of background to black 
    setcolor(BLACK); 
    //setfillstyle(SOLID_FILL, BLACK); 
  
    // Use fill ellipse for creating eyes 
    fillellipse(310, 285, 4, 9); 
    fillellipse(290, 285, 4, 9); 
  
    // Use ellipse for creating mouth 
    	line(270, 320, 330,320); 
   	line(270, 321, 330,321); 
   	line(270, 322, 330,322); 
   	line(270, 323, 330,323); 
   	line(270, 324, 330,324); 
   	line(270, 325, 330,325); 


delay(50000);
closegraph(); 
return 0;

}
