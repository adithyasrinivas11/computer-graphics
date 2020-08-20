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
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POLYGON); 
	
	glVertex2f(-150.0,-100.0);
	glVertex2f(-150.0, 50.0);
	glVertex2f(300.0, 50.0);				//lower part
	glVertex2f(300.0,-100.0);
	glEnd(); 
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON); 
	
	glVertex2f(0.0,50.0);
	glVertex2f(50.0, 200.0);
	glVertex2f(250.0, 200.0);				//upper part
	glVertex2f(300.0,50.0);
	glEnd(); 
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(10, 60);
	glVertex2f(53,190 );
	glVertex2f(10, 60);
	glVertex2f(140,60 );
	glVertex2f(140,60 );
	glVertex2f(140,190 );
	glVertex2f(140,190 );
	glVertex2f(53,190 );
	
	glVertex2f(160,60 );
	glVertex2f(290, 60);
	glVertex2f(290,60 );
	glVertex2f(245,190);
	glVertex2f(245,190);
	glVertex2f(160,190 );				//window part
	glVertex2f(160,190 );
	glVertex2f(160,60 );
	
	glVertex2f(0,50);
	glVertex2f(300,50 );
	glEnd();

	
	
        glBegin(GL_TRIANGLE_FAN);
        float i;
       glColor3f(0.7, 0.7, 0.7);
        glVertex2f(0, -100); // Center
        for(i = 0.0f; i <= 360; i++)
                glVertex2f(50*cos(pi * i / 180.0) + 0, 50*sin(pi * i / 180.0) + -100);
        
        glEnd();
	
	glBegin(GL_TRIANGLE_FAN);
	//float i;
	glColor3f(0.7, 0.7, 0.7);
	glVertex2f(225, -100); // Center
	for(i = 0.0f; i <= 360; i++)
		glVertex2f(50*cos(pi * i / 180.0) + 225,50*sin(pi * i / 180.0) + -100);

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

