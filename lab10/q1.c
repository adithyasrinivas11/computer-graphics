#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
void display (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_POLYGON); 
	
	glVertex2f(50.0, 50.0);
	glVertex2f(50.0, 200.0);
	glVertex2f(200.0, 200.0);
	glVertex2f(250.0, 125.0);
	glVertex2f(200.0, 50.0);

	glEnd(); 
	glFlush(); 
}

void displayt (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glTranslatef( 100, 120, 0.0);
	glBegin(GL_POLYGON); 
	
	glVertex2f(50.0, 50.0);
	glVertex2f(50.0, 200.0);
	glVertex2f(200.0, 200.0);
	glVertex2f(250.0, 125.0);
	glVertex2f(200.0, 50.0);
	
	glEnd(); 

	glFlush(); 
}

void displayr (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	glRotatef (45.0, 0.0, 0.0, 1.0);
	//glTranslatef( 0, 0, 0.0);
	glBegin(GL_POLYGON); 
	
	glVertex2f(50.0, 50.0);
	glVertex2f(50.0, 200.0);
	glVertex2f(200.0, 200.0);
	glVertex2f(250.0, 125.0);
	glVertex2f(200.0, 50.0);

	glEnd(); 
	glFlush(); 
}

void displays (void) 
{ 
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	glScalef(2, 2, 0);

	//glTranslatef( 0, 0, 0.0);
	glBegin(GL_POLYGON); 
	
	glVertex2f(50.0, 50.0);
	glVertex2f(50.0, 200.0);
	glVertex2f(200.0, 200.0);
	glVertex2f(250.0, 125.0);
	glVertex2f(200.0, 50.0);

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
	glutCreateWindow(" Drawing"); 			//name
	glutDisplayFunc(display);
	
	glutCreateWindow(" Drawing 2"); 			//name
	glutDisplayFunc(displayt); 
	
	glutCreateWindow(" Drawing 3"); 			//name
	glutDisplayFunc(displayr); 
	
	glutCreateWindow(" Drawing 4"); 			//name
	glutDisplayFunc(displays); 
	glutMainLoop(); 
} 

