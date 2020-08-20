// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

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
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 1.0, 0.0);
	gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POINTS); 
	float x, y, i; 
	// iterate y up to 2*pi, i.e., 360 degree 
	// with small increment in angle as 
	// glVertex2i just draws a point on specified co-ordinate 
	for ( i = 0; i < (2 * pi); i += 0.001) 
	{ 
		// let 200 is radius of circle and as, 
		// circle is defined as x=r*cos(i) and y=r*sin(i) 
		x = 200 * cos(i); 
		y = 200 * sin(i); 
		
		glVertex2i(x, y); 
	} 
	glEnd(); 
	
	glColor3f(0.0, 1.0, 0.0);
	//gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POINTS); 
	float x1, y1, i1; 
	// iterate y up to 2*pi, i.e., 360 degree 
	// with small increment in angle as 
	// glVertex2i just draws a point on specified co-ordinate 
	for ( i1 = 0; i1 < 1000; i1 += 0.001) 
	{ 
		// let 200 is radius of circle and as, 
		// circle is defined as x=r*cos(i) and y=r*sin(i) 
		x1 = 400 ; 
		y1 = i1; 
		
		glVertex2i(x1, y1); 
	} 
	glEnd(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	// Giving name to window 
	glutCreateWindow("Circle Drawing"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

