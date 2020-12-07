  #include <GL/glut.h>  
  #include<stdio.h>
  int ww = 600, wh = 500;  
  float prevCol[3] = {1.0,0.0,0.0};  
  float newCol[3] = {0.0,1.0,0.0};
    
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
      /* glColor3f(1.0,0.0,0.0);  
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
      */
     	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON); 
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	//glVertex2f(x2,y1);
	glVertex2f(x2, y2);
	glVertex2f(x1,y2);
	//glVertex2f(x1,y1);
	glEnd();
	/*glDisable(GL_DEPTH_TEST);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);  
	glVertex2i(x1, y1);  
	glVertex2i(x1, y2);
	glVertex2i(x2, y1);  
	glVertex2i(x2, y2); 
	glVertex2i(x1, y1);  
	glVertex2i(x2, y1); 
	glVertex2i(x1, y2);  
	glVertex2i(x2, y2);  
       glEnd();  
	glEnable(GL_DEPTH_TEST);*/
	 glFlush();
  }  
  void display()  
  {  
       glClearColor(0.0,0.0,0.0, 1.0);  
       glClear(GL_COLOR_BUFFER_BIT);  
       drawPolygon(150,250,200,300);  
       glFlush();  
  }  
  void FloodFill4(int x,int y,float prevColor[3],float newColor[3])  
  {  
       float interiorColor[3];  
       getPixel(x,y,interiorColor);
       if((interiorColor[0]==prevColor[0] && (interiorColor[1])==prevColor[1] && (interiorColor[2])==prevColor[2]) )  
       {  
            if(x>150 && x<200 && y>250 && y<300)
           { 
            setPixel(x,y,newColor);  
            FloodFill4(x+1,y,prevColor,newColor);  
            FloodFill4(x-1,y,prevColor,newColor);  
           	FloodFill4(x,y+1,prevColor,newColor);  
            FloodFill4(x,y-1,prevColor,newColor); 
            FloodFill4(x+1,y+1,prevColor,newColor);  
            FloodFill4(x-1,y+1,prevColor,newColor);  
            FloodFill4(x+1,y-1,prevColor,newColor);  
            FloodFill4(x-1,y-1,prevColor,newColor);  
            }
       }  
  }  
  void mouse(int btn, int state, int x, int y)  
  {  
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)   
       {  
            int xi = x;  
            int yi = (wh-y);  
            FloodFill4(xi,yi,prevCol,newCol);  
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
