// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h>
#include <stdlib.h> 
#define pi 3.142857 


int xmin,ymin,xmax,ymax;
// function to initialize 
/*void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	
	// making picture color green (in RGB mode), as middle argument is 1.0 
	glColor3f(0.0, 1.0, 0.0); 
	
	// breadth of picture boundary is 1 pixel 
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420); 
} */

void display (void) 
{ 
	int x[1000],y[1000];
	
	for(int i =0;i<1000;i++)
	{
	x[i] = rand()%300;
	y[i]= rand()%300;
	}
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POINTS); 
	for(int i =0;i<1000;i++)
	{
		if(x[i]>=xmin && x[i]<=xmax && y[i]>=ymin && y[i]<=ymax)
		{
			glColor3f(0.0, 0.0, 1.0);
			glVertex2f(x[i], y[i]);
		}
		else
		{
			glColor3f(1.0, 0.5, 0.0);
			glVertex2f(x[i], y[i]);			
		}
	}
	glEnd(); 
	
	glColor3f(1.0, 0.0, 1.0);
	//gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_LINES); 
	glVertex2f(xmin, ymin);
	glVertex2f(xmin, ymax);
	glVertex2f(xmin, ymax);
	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmin, ymin);
	glEnd(); 
	
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	xmin=atoi(argv[1]);
	ymin=atoi(argv[2]);
	
	xmax=atoi(argv[3]);
	ymax=atoi(argv[4]);
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	// Giving name to window 
	glutCreateWindow("Circle Drawing"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

