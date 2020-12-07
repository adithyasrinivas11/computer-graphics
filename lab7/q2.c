// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

float x,y,a,b;


void display (void) 
{ 

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);

    glColor3f(1.0, 1.0, 0.0); 
    int xx, yy;
    float sa, sb; 
    int d1, d2;
    glBegin(GL_POINTS); 
        
        xx = 0;
        yy = round(b);
        
        sa = a*a;
        sb = b*b;

        glVertex2i(x+xx, y+yy);
        glVertex2i(x+xx, y-yy);
        glVertex2i(x-xx, y+yy);
        glVertex2i(x-xx, y-yy);


        d1 = sb - (sa*b) + (0.25*sa); 

        while ( (sa*(yy - 0.5)) > (sb*(xx + 1)) ) //R1
        {    
            if(d1 < 0) // E
            {
                d1 = d1 + sb * ((2*xx) + 3); // d + d_E
            }

            else //SE
            {
                d1 = d1 + ( sb * ((2*xx) + 3)) + (sa *((-2*yy) + 2)); // d + d_SE
                yy = yy - 1;  
            }

            xx++;

            glVertex2i(x+xx, y+yy);
            glVertex2i(x+xx, y-yy);
            glVertex2i(x-xx, y+yy);
            glVertex2i(x-xx, y-yy);
        }

        d2 = ((sb * (xx + 0.5)*(xx + 0.5)) + (sa*(yy - 1)*(yy - 1)) - (sa*sb)) ;

        while(yy > 0) //R2
        {   
            if(d2 < 0) // SE
            {
                d2 = d2 + sb*((2*xx) + 2) + sa*(-(2*yy) + 3); // d + d_SE
                xx = xx + 1;
            }

            else // S
            {
                d2 = d2 + sa *((-2*yy) + 3); // d + d_S
            }

            yy = yy - 1;  

            glVertex2i(x+xx, y+yy);
            glVertex2i(x+xx, y-yy);
            glVertex2i(x-xx, y+yy);
            glVertex2i(x-xx, y-yy);
        }

    glEnd(); 
    glFlush();
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	x=atoi(argv[1]);
	y=atoi(argv[1]);
	a=atoi(argv[2]);
	b=atoi(argv[3]);
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	// Giving name to window 
	glutCreateWindow("ellipse"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

