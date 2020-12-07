// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

float xx1,yy1,xx2,yy2;
int mx,my,z=0;


void mouse(int button, int state, int mousex, int mousey)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		z=1;
		mx = mousex;
		my = 768-mousey;
		printf("inside z== %d   %d   %d \n", z,mx-780,my-768);
	}
	glutPostRedisplay();
}
void newer(int x,int y)
{	
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	gluOrtho2D(-780, 780, -420, 420);
	unsigned char pixel[4];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
	printf("26 line %d %d %d       %d  %d \n",pixel[0],pixel[1],pixel[2],x,y);
	if(((int)pixel[0]==1 &&(int)pixel[1]==0 && (int)pixel[2]==0) || ((int)pixel[0]==253 &&(int)pixel[1]==127 && (int)pixel[2]==0))
	{
		printf("jdwaojda\n");
		if(x>=2 && x <=100 && y<= 250 && y>=20)
		{	
			printf("in 38\n");
			glColor3f(0.0, 0.0, 1.0);
			glVertex2f(x, y);
			newer(x+1,y);
			newer(x,y+1);
			newer(x-1,y);
			newer(x,y-1);
			newer(x-1,y-1);
			newer(x-1,y+1);
			newer(x+1,y-1);
			newer(x+1,y+1);
		}
	}
}
void display (void) 
{ 

	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);

    glColor3f(1.0, 0.0, 0.0); 
    int xx, yy;
    float t1,t2; 
    int d1, d2;
    glBegin(GL_POINTS); 
    glVertex2f(0, 0);
      glColor3f(1.0, 1.0, 0.0); 
////////////////////////////////////////////////////////rectangle//////////////////////////////////////////////////        
	if(xx1>xx2)							//boundary//
	{
		t1=xx2;
		t2=xx1;
	}
	else
	{
		t1=xx1;
		t2=xx2;
	}
	for(int i=t1;i<t2;i++)
	{
		glVertex2f(i, yy1);
		glVertex2f(i, yy2);
	}
	if(yy1>yy2)
	{
		t1=yy2;
		t2=yy1;
	}
	else
	{
		t1=yy1;
		t2=yy2;
	}
	for(int i=t1;i<t2;i=i+1)
	{
		glVertex2f(xx1,i);
		glVertex2f(xx2,i);
	}
	glutMouseFunc(mouse);
	
	if(z==1)
	{
		glColor3f(1.0, 1.0, 0.0); 
		glVertex2i(mx,my);
		printf("z== %d   %d   %d \n", z,mx,my);
	}
	newer(mx-780,my);	

    glEnd(); 
    glFlush();
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	xx1=atoi(argv[1]);
	yy1=atoi(argv[1]);
	xx2=atoi(argv[2]);
	yy2=atoi(argv[3]);
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	// Giving name to window 
	glutCreateWindow("boundary dill algo"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	//
	glutMainLoop(); 
} 

