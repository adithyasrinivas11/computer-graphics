// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

struct
{ 
GLubyte red, green, blue; 
}pixel,pix1;

float xx1,yy1,xx2,yy2,xx3,yy3;
int mx,my,z=0;
float col[3] = {0.0,0.0,1.0};  //Blue inside Rectangle

int tri_check(float x[3],float y[3],float a,float b)
{

float c,c1=0,c2=0,c0=0;

float max_x,min_x,max_y,min_y;

//printf("enter the points to be checked as coordinates x,y:  ");
//	scanf("%f %f", &a,&b);

float slope[3],intercept[3];


slope[0]= (y[1]-y[0])/(x[1]-x[0]);
intercept[0]=y[1]-(slope[0]*x[1]);

slope[1]= (y[2]-y[1])/(x[2]-x[1]);
intercept[1]=y[2]-(slope[1]*x[2]);

slope[2]= (y[2]-y[0])/(x[2]-x[0]);
intercept[2]=y[2]-(slope[2]*x[2]);

//printf("%fx+%f     %fx+%f        %fx+%f	\n",slope[0],intercept[0],slope[1],intercept[1],slope[2],intercept[2]);

float y2,y1,y0,y22,y11,y00;
y2= slope[0]*a+intercept[0];
y22=slope[0]*x[2]+intercept[0];

y1= slope[1]*a+intercept[1];
y11=slope[1]*x[0]+intercept[1];

y0= slope[2]*a+intercept[2];
y00=slope[2]*x[1]+intercept[2];

//printf("%f---%f     %f---%f        %f---%f",y2,y22,y1,y11,y0,y00);

// check id the point to be checked and the 3rd point are both in same side wrt the line got by joining 1st and 2nd points
if((y2>b && y22>y[2]) || (y2<b && y22<y[2]))
	c2=1;
if((y1>b && y11>y[0]) || (y1<b && y11<y[0]))
	c1=1;
if((y0>b && y00>y[1]) || (y0<b && y00<y[1]))
	c0=1;
	
c=c0*c1*c2;

return c;
/*if(c==0)
	printf("outside the triangle\n");
else
	printf("inside the triangle\n");
*/
}


void newer(int x,int y)
{	
	printf("x,y in dunction = %d%d\n",x,y);
	int q=x;
	int w=y;
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	gluOrtho2D(-780, 780, -420, 420);
	//int pixel[4];
	
	glReadPixels(q, w, 1, 1, GL_RGB, GL_UNSIGNED_BYTE,&pixel);
	printf("26 line %d %d %d       %d  %d \n",pixel.red,pixel.green,pixel.blue,q,w);
	glBegin(GL_POINTS); 
	if((pixel.red==1 && pixel.green ==0 && pixel.blue ==0) ||(pixel.red==0 && pixel.green ==0 && pixel.blue ==1))
	{
		printf("jdwaojda\n");
		
	}
	else
	{
		if(x>2 && x <100 && y<250 && y>20)
		{	
			printf("in 38\n");
			glColor3ub(255,255,255);
			glVertex2i(x, y);
			glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE,&pix1);
			printf("color displayed ==  %d %d %d  -----    %d %d  \n",pix1.red,pix1.green,pix1.blue,x,y);
			newer(x+1,y);
			newer(x,y+1);
			newer(x-1,y);
			newer(x,y-1);

		}
	}
	 glEnd(); 
    glFlush();
}

void new_triangle(int x, int y)
{
	printf("x,y in dunction = %d%d\n",x,y);
	int q=x;
	int w=y;
	float a[3],b[3];
	a[0]=xx1;
	a[1]=xx2;
	a[2]=xx3;
	b[0]=yy1;
	b[1]=yy2;
	b[2]=yy3;
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	gluOrtho2D(-780, 780, -420, 420);
	//int pixel[4];
	
	//glReadPixels(q, w, 1, 1, GL_RGB, GL_UNSIGNED_BYTE,&pixel);
	//getpixel
	printf("26 line %d %d %d       %d  %d \n",pixel.red,pixel.green,pixel.blue,q,w);
	glBegin(GL_POINTS); 
	if((pixel.red==1 && pixel.green ==0 && pixel.blue ==0) ||(pixel.red==0 && pixel.green ==0 && pixel.blue ==1))
	{
		printf("jdwaojda\n");
		
	}
	else
	{
		int h=tri_check(a,b,x,y);
		if(h!=0)
		{	
			printf("in 38\n");
			glColor3fv(col);
			glVertex2i(x, y);
			glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE,&pix1);
			printf("color displayed ==  %d %d %d  -----    %d %d  \n",pix1.red,pix1.green,pix1.blue,x,y);
			newer(x+1,y);
			newer(x,y+1);
			newer(x-1,y);
			newer(x,y-1);

		}
	}
	 glEnd(); 
    glFlush();
}

void mouse(int button, int state, int mousex, int mousey)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		z=1;
		mx = mousex;
		my = 768-mousey;
		printf("inside z== %d   %d   %d \n", z,780-mx,my-420);
		//newer(780-mx,my-420);
		new_triangle(780-mx,my-420);
	}
	//glutPostRedisplay();
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
	/*if(xx1>xx2)							//boundary//
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
	}*/
	
	
	
	if(z==1)
	{
		glColor3f(1.0, 1.0, 0.0); 
		glVertex2i(mx,my);
		printf("z== %d   %d   %d \n", z,mx,my);
	}
	
	
    glEnd();
    
     glBegin(GL_LINES);
	glVertex2f(xx1,yy1);
	glVertex2f(xx2,yy2);
	glVertex2f(xx3,yy3);
      glEnd();
    glutMouseFunc(mouse);
    
    
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

