  #include <GL/glut.h>  
  #include<stdio.h>
  int ww = 600, wh = 500;  
  float fillCol[3] = {0.0,0.0,1.0};  
  float borderCol[3] = {1.0,0.0,0.0};
  
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
  void setPixel(int pointx, int pointy, float f[3])  
  {  
       glBegin(GL_POINTS);  
            glColor3fv(f);  
            glVertex2i(pointx,pointy);  
       glEnd();  
       glFlush();  
  }  
  void getPixel(int x, int y, float pixels[3])  
  {  
       glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
  }  
  void drawPolygon(int x1, int y1, int x2, int y2)  
  {       
       glColor3f(1.0,0.0,0.0);  
       glBegin(GL_LINES);  
            glVertex2i(x1, y1);  
            glVertex2i(x1, y2);   
       glEnd();  
       glBegin(GL_LINES);  
            glVertex2i(x2, y1);  
            glVertex2i(x2, y2);  
       glEnd();  
       glBegin(GL_LINES);  
            glVertex2i(x1, y1);  
            glVertex2i(x2, y1);  
       glEnd();  
       glBegin(GL_LINES);  
            glVertex2i(x1, y2);  
            glVertex2i(x2, y2);  
       glEnd();  
       glFlush();  
  }  
  void display()  
  {  
       glClearColor(0.0,0.0,0.0, 1.0);  
       glClear(GL_COLOR_BUFFER_BIT);  
       //drawPolygon(150,250,200,300);
        glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(200,50);
	glVertex2f(200,50);
	glVertex2f(50,300);
	glVertex2f(50,300);
	glVertex2f(0,0);
       glFlush();  
  }  
  void boundaryFill4(int x,int y,float fillColor[3],float borderColor[3])  
  {  
       float interiorColor[3];
       float a[3],b[3];
      a[0]=0;
	a[1]=200;
	a[2]=50;
	b[0]=0;
	b[1]=50;
	b[2]=300;
       getPixel(x,y,interiorColor);
       if((interiorColor[0]!=borderColor[0] || (interiorColor[1])!=borderColor[1] || (interiorColor[2])!=borderColor[2]) && (interiorColor[0]!=fillColor[0] || (interiorColor[1])!=fillColor[1] || (interiorColor[2])!=fillColor[2]) )  
       {  
            if(tri_check(a,b,x,y)!=0)
            {
            setPixel(x,y,fillColor);  
            boundaryFill4(x+1,y,fillColor,borderColor);  
            boundaryFill4(x-1,y,fillColor,borderColor);  
            boundaryFill4(x,y+1,fillColor,borderColor);  
            boundaryFill4(x,y-1,fillColor,borderColor);
            boundaryFill4(x+1,y+1,fillColor,borderColor);  
            boundaryFill4(x-1,y+1,fillColor,borderColor);  
            boundaryFill4(x+1,y-1,fillColor,borderColor);  
            boundaryFill4(x-1,y-1,fillColor,borderColor); 
            }
       }  
  }  
  void mouse(int btn, int state, int x, int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
       {  
            int xi = x;  
            int yi = (wh-y);  
            
            
            boundaryFill4(xi,yi,fillCol,borderCol);  
       }  
  }  
  void myinit()  
  {        
       glViewport(0,0,ww,wh);  
       glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();  
       gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);  
       glMatrixMode(GL_MODELVIEW);  
  }  
  int main(int argc, char** argv)  
  {  
	    glutInit(&argc,argv);  
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(ww,wh);  
       glutCreateWindow("Bountry-Fill-Recursive");  
       glutDisplayFunc(display);  
       myinit();  
       glutMouseFunc(mouse);  
       glutMainLoop();  
       return 0;  
  }  
