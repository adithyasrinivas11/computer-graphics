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
	float ii,jj,t1,t2,yy,xx;
	
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
	if(slope<=1 && slope>=-1)
	{
		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
				yy=yy2;
			}
			else
			{
				t1=xx1;
				t2=xx2;
				yy=yy1;
			}
			
			
			for(int i=t1;i<t2;i=i+1)
			{
				j=yy+slope;
				yy=round(j);
				ii=round(i);
				jj=round(j);
				printf("1points %d %d\n",ii,jj);
				glVertex2f(ii,jj);
			}
	}
	else
	{
		if(yy1>yy2)
			{
				t1=yy2;
				t2=yy1;
				xx=yy2;
			}
			else
			{
				t1=yy1;
				t2=yy2;
				xx=yy1;
			}
			
			for(int i=t1;i<t2;i=i+1)
			{
				j=i+islope;
				xx=round(j);
				//j=(slope*i)+c;
				ii=round(j);
				jj=round(i);
				printf("2points %d %d\n",ii,jj);
				glVertex2f(ii,jj);
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
	glutCreateWindow("Circle Drawing"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

