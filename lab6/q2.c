// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

float xx1,xx2,yy1,yy2;


void display (void) 
{ 
	float slope,c,q,j,islope;
	float ii,jj,t1,t2,yy,xx,d,dy,dx,de,dne;
	float tx1,tx2,ty1,ty2,t11;
	if(xx1!=xx2)
	{
		slope = (yy2-yy1)/(xx2-xx1);
		if(slope!=0)
			islope=1/slope;
		else
			islope=10000000000;
		c=yy2-(slope*xx2);
		printf("slope = %f\n",slope);
	}
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POINTS);
	if(xx1 >0 && xx2 >0 && yy1>0 && yy2>0)		//1st quadrant
	{	
		if(yy1<xx1 && yy2<xx2)				//1st octet
		{
			printf("case1");
			tx1=xx1;
			tx2=xx2;
			ty1=yy1;
			ty2=yy2;
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=2*dy-dx;
			de=2*dy;
			dne=2*(dy-dx);
			
			if(tx1>tx2)
			{
				t1=tx2;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t2=ty1;
			}
			while(t1<t11)
			{
				if(d<0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				glVertex2f(t1,t2);
			}
			
		}
		else if(yy1>xx1 && yy2>xx2)			//2nd octet
		{
			printf("case2");
			tx1=yy1;
			tx2=yy2;
			ty1=xx1;
			ty2=xx2;
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=2*dy-dx;
			de=2*dy;
			dne=2*(dy-dx);
			
			if(tx1>tx2)
			{
				t1=tx2;
				t11=tx1;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t11=tx2;
				t2=ty1;
			}
			
			while(t1<t11)
			{
				if(d<0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				glVertex2f(t2,t1);
			}
		}
	}
	else if(xx1 <0 && xx2<0 && yy1>0 && yy2>0)		//2nd quadrant
	{	
		if(yy1>(-1*xx1) && yy2>(-1*xx2))				//3rd octet
		{
			printf("case3");
			tx1=(yy1);
			tx2=(yy2);
			ty1=(-1*xx1);
			ty2=(-1*xx2);
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=(2*dy)-dx;
			de=2*dy;
			dne=2*(dy-dx);
			printf("de= %f\n",de);
			if(tx1>tx2)
			{
				t1=tx2;
				t11=tx1;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t11=tx2;
				t2=ty1;
			}
			
			while(t1<t11)
			{
				//printf("in while case");
				if(d<=0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				printf("d == %f\n",d);
				printf("%f %f\n",t1,t2);
				glVertex2f(-t2,t1);
			}
			
			
		}
		else if(yy1<(-1*xx1) && yy2<(-1*xx2))			//2nd octet
		{
			printf("case4");
			tx1=(-1*xx1);
			tx2=(-1*xx2);
			ty1=yy1;
			ty2=yy2;
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=2*dy-dx;
			de=2*dy;
			dne=2*(dy-dx);
			
			if(tx1>tx2)
			{
				t1=tx2;
				t11=tx1;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t11=tx2;
				t2=ty1;
			}
			//printf("d == %f\n",d);
			while(t1<t11)
			{
				if(d<0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				glVertex2f(-t1,t2);
			}
		}
	}
	else if(xx1 <0 && xx2<0 && yy1<0 && yy2<0)		//5rd quadrant
	{
		if((-1*yy1)<(-1*xx1) && (-1*yy2)<(-1*xx2))
		{
			printf("case5");
			tx1=(-1*xx1);
			tx2=(-1*xx2);
			ty1=(-1*yy1);
			ty2=(-1*yy2);
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=2*dy-dx;
			de=2*dy;
			dne=2*(dy-dx);
			
			if(tx1>tx2)
			{
				t1=tx2;
				t11=tx1;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t11=tx2;
				t2=ty1;
			}
			//printf("d == %f %f\n",t1,t11);
			while(t1<t11)
			{
				if(d<0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				glVertex2f(-t1,-t2);
			}
		}
		else if((-1*yy1)>(-1*xx1) && (-1*yy2)>(-1*xx2))	//6
		{
			tx1=(-1*yy1);
			tx2=(-1*yy2);
			ty1=(-1*xx1);
			ty2=(-1*xx2);
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=2*dy-dx;
			de=2*dy;
			dne=2*(dy-dx);
			
			if(tx1>tx2)
			{
				t1=tx2;
				t11=tx1;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t11=tx2;
				t2=ty1;
			}
			while(t1<t11)
			{
				if(d<0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				glVertex2f(-t2,-t1);
			}
		}
	}
	else if(xx1>0 && xx2>0 && yy1<0 && yy2<0)
	{
		if(xx1>(-1*yy1) && xx2>(-1*yy2))		//7
		{	tx1=(-1*yy1);
			tx2=(-1*yy2);
			ty1=xx1;
			ty2=xx2;
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=2*dy-dx;
			de=2*dy;
			dne=2*(dy-dx);
			
			if(tx1>tx2)
			{
				t1=tx2;
				t11=tx1;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t11=tx2;
				t2=ty1;
			}
			while(t1<t11)
			{
				if(d<0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				glVertex2f(t2,-t1);
			}
		}
		else if(xx1<(-1*yy1) && xx2<(-1*yy2))			//8
		{
			printf("case8");
			tx1=(xx1);
			tx2=(xx2);
			ty1=(-1*yy1);
			ty2=(-1*yy2);
			
			dy=ty2-ty1;
			dx=tx2-tx1;
			d=2*dy-dx;
			de=2*dy;
			dne=2*(dy-dx);
			
			if(tx1>tx2)
			{
				t1=tx2;
				t11=tx1;
				t2=ty2;
			}
			else
			{
				t1=tx1;
				t11=tx2;
				t2=ty1;
			}
			while(t1<t11)
			{
				if(d<0)
				{
					d=d+de;
				}
				else
				{
					d+=dne;
					t2+=1;
				}
				t1++;
				glVertex2f(t1,-t2);
			}
		}
	}
	
	
	glEnd();
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	xx1=atoi(argv[1]);
	yy1=atoi(argv[2]);
	xx2=atoi(argv[3]);
	yy2=atoi(argv[4]);
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	// Giving name to window 
	glutCreateWindow("midpoint"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

