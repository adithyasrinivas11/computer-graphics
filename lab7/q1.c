// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

float r,a,b;


void display (void) 
{ 
	float h,x,y,slope,c,q,j,islope;
	float ii,jj,t1,t2,yy,xx,d,dy,dx,de,dse;
	float tx1,tx2,ty1,ty2,t11;
	h=1-r;
	x=0,y=r;
	de=3;
	dse=-2*r+5;
	ii=r/2;
	jj=b+ii;
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POINTS);
	while(y>x)
	{
		if(h<0)
		{
			h+=de;
			de+=2;
			dse+=2;
		}
		else
		{
			h+=dse;
			de+=2;
			dse+=4;
			y--;
		}
		x++;
		glVertex2f(round(a+y),round(b+x));		//1st
		glVertex2f(round(a+x),round(b+y));		//2nd
		glVertex2f(round(a-x),round(b+y));		//3th
		glVertex2f(round(a-y),round(b+x));		//4th
		glVertex2f(round(a-y),round(b-x));		//5th
		glVertex2f(round(a-x),round(b-y));		//6th
		glVertex2f(round(a+x),round(b-y));		//7th
		glVertex2f(round(a+y),round(b-x));		//8th
	}
		
	glEnd();
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	r=atoi(argv[1]);
	a=atoi(argv[2]);
	b=atoi(argv[3]);
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	// Giving name to window 
	glutCreateWindow("midpoint"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

