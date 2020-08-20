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
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POLYGON); 
	
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 200.0);
	glVertex2f(200.0, 200.0);
	glVertex2f(200.0, 0.0);
	glEnd(); 
	
	glColor3f(1.0, 0.0, 1.0);
	//gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_TRIANGLES); 
	glVertex2f(200.0, 200.0);
	glVertex2f(0.0, 200.0);
	glVertex2f(100.0, 300.0);
	glEnd(); 
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON); 
	
	glVertex2f(40.0, 90.0);
	glVertex2f(40.0, 110.0);
	glVertex2f(60.0, 110.0);
	glVertex2f(60.0, 90.0);
	glEnd();
	glBegin(GL_POLYGON); 
	glVertex2f(140.0, 90.0);
	glVertex2f(140.0, 110.0);
	glVertex2f(160.0, 110.0);
	glVertex2f(160.0, 90.0);
	glEnd();
	
	glBegin(GL_POLYGON); 
	glVertex2f(85.0, 45.0);
	glVertex2f(85.0, 0.0);
	glVertex2f(115.0, 0.0);
	glVertex2f(115.0, 45.0);
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

