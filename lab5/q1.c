#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<time.h>
#define pi 3.142857 

float xx1,xx2,yy1,yy2;

void display (void) 
{ 
	//int x1,x2,y1,y2;
	clock_t tt1,tt2;
	tt1=clock(); 
	float slope,c,q,j;
	float ii,jj;
	
	if(xx1!=xx2)
	{
		slope = (yy2-yy1)/(xx2-xx1);
		c=yy2-(slope*xx2);
		printf("slope = %f\n",slope);
	}
	
	//q=round(slope);
	
	//printf("%f",q);
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	

	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		//printf("inside id");
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+5)
	     		{
	     			j=yy1;
				ii=round(i);
				jj=round(j);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
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
	     		for(int i=t1;i<t2;i=i+5)
	     		{
	     			j=xx1;
				ii=round(j);
				jj=round(i);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		
     	}
     	else
     	{
		//printf("inside else");
		
			
		if(slope<=1 && slope>=-1)
		{
			if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(slope*i)+c;
				ii=round(i);
				jj=round(j);
			
				glVertex2f(ii,jj);
			}
		}
		else
		{
			//printf("*112*\n");
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
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(i-c)/slope;
				//j=(slope*i)+c;
				ii=round(j);
				jj=round(i);
				
				glVertex2f(ii,jj);
			}
		}
		
 	}
      glEnd();
      tt2=clock();
      double timetaken= (double)(tt2-tt1)/CLOCKS_PER_SEC;
	printf("Time taken = %lf",timetaken);
	glFlush(); 
} 



void display1 (void) 
{ 
	//int x1,x2,y1,y2;
	float slope,c,q,j;
	float ii,jj;
	
	if(xx1!=xx2)
	{
		slope = (yy2-yy1)/(xx2-xx1);
		c=yy2-(slope*xx2);
	}
	
	//q=round(slope);
	
	//printf("%f",q);
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	//printf("%d  %d\n",xx1,xx2);
	//printf("%d  %d\n",yy1,yy2);
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		//printf("inside id",yy1,yy2);
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+4)
	     		{
	     			j=yy1;
				ii=round(i);
				jj=round(j);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
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
	     		for(int i=t1;i<t2;i=i+4)
	     		{
	     			j=xx1;
				ii=round(j);
				jj=round(i);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		
     	}
     	else
     	{
			
		if(slope<=1 && slope>=-1)
		{
			if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
			
			for(int i=t1;i<t2;i=i+4)
			{
				j=(slope*i)+c;
				ii=round(i);
				jj=round(j);
			
				glVertex2f(ii,jj);
			}
		}
		else
		{
			//printf("*112*\n");
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
			
			for(int i=t1;i<t2;i=i+4)
			{
				j=(i-c)/slope;
				//j=(slope*i)+c;
				ii=round(j);
				jj=round(i);
				
				glVertex2f(ii,jj);
			}
		}
 	}
      glEnd();
      glFlush(); 
}

void display2 (void) 
{ 
	//int x1,x2,y1,y2;
	float slope,c,q,j;
	float ii,jj;
	
	if(xx1!=xx2)
	{
		slope = (yy2-yy1)/(xx2-xx1);
		c=yy2-(slope*xx2);
	}
	
	//q=round(slope);
	
	//printf("%f",q);
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	//printf("%d  %d",xx1,xx2);
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+3)
	     		{
	     			j=yy1;
				ii=round(i);
				jj=round(j);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
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
	     		for(int i=t1;i<t2;i=i+3)
	     		{
	     			j=xx1;
				ii=round(j);
				jj=round(i);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		
     	}
     	else
     	{
			
		if(slope<=1 && slope>=-1)
		{
			if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(slope*i)+c;
				ii=round(i);
				jj=round(j);
			
				glVertex2f(ii,jj);
			}
		}
		else
		{
			//printf("*112*\n");
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
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(i-c)/slope;
				//j=(slope*i)+c;
				ii=round(j);
				jj=round(i);
				
				glVertex2f(ii,jj);
			}
		}
 	}
      glEnd(); 
               glFlush(); 
}


void display3 (void) 
{ 
	float slope,c,q,j;
	float ii,jj;
	
	if(xx1!=xx2)
	{
		slope = (yy2-yy1)/(xx2-xx1);
		c=yy2-(slope*xx2);
	}
	
	//q=round(slope);
	
	//printf("%f",q);
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	//printf("%d  %d",xx1,xx2);
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+2)
	     		{
	     			j=yy1;
				ii=round(i);
				jj=round(j);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
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
	     		for(int i=t1;i<t2;i=i+2)
	     		{
	     			j=xx1;
				ii=round(j);
				jj=round(i);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		
     	}
     	else
     	{
			
		if(slope<=1 && slope>=-1)
		{
			if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(slope*i)+c;
				ii=round(i);
				jj=round(j);
			
				glVertex2f(ii,jj);
			}
		}
		else
		{
			//printf("*112*\n");
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
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(i-c)/slope;
				//j=(slope*i)+c;
				ii=round(j);
				jj=round(i);
				
				glVertex2f(ii,jj);
			}
		}
 	}
      glEnd();
      glFlush(); 
}

void display4 (void) 
{ 
	float slope,c,q,j;
	float ii,jj;
	
	if(xx1!=xx2)
	{
		slope = (yy2-yy1)/(xx2-xx1);
		c=yy2-(slope*xx2);
	}
	
	//q=round(slope);
	
	//printf("%f",q);
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	
	//printf("%d  %d",xx1,xx2);
	int t1,t2;
	glBegin(GL_POINTS);
     	if((yy1==yy2) || (xx1==xx2))
     	{
     		if(yy1==yy2)
     		{	
	     		if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
	     		for(int i=t1;i<t2;i=i+1)
	     		{
	     			j=yy1;
				ii=round(i);
				jj=round(j);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		else if(xx1==xx2)
     		{	
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
	     			j=xx1;
				ii=round(j);
				jj=round(i);
      
				glVertex2f(ii,jj);
	     		}
     		
     		}
     		
     	}
     	else
     	{
			
		if(slope<=1 && slope>=-1)
		{
			if(xx1>xx2)
			{
				t1=xx2;
				t2=xx1;
			}
			else
			{
				t1=xx1;
				t2=xx2;
			}
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(slope*i)+c;
				ii=round(i);
				jj=round(j);
			
				glVertex2f(ii,jj);
			}
		}
		else
		{
			//printf("*112*\n");
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
			
			for(int i=t1;i<t2;i=i+5)
			{
				j=(i-c)/slope;
				//j=(slope*i)+c;
				ii=round(j);
				jj=round(i);
				
				glVertex2f(ii,jj);
			}
		}
 	}
      glEnd();
      glFlush(); 
}

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	//printf("%d",argc);
	xx1=atoi(argv[1]);
	yy1=atoi(argv[2]);
	xx2=atoi(argv[3]);
	yy2=atoi(argv[4]);
	
	//printf("## %f  %f\n",xx1,yy1);
	
	float slope,c,q,j;
	
	//printf("%d,%d,%d,%d",xx1,xx2,yy1,yy2);
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	
	// Giving name to window 
	glutCreateWindow("line"); 			//stepsize=5
	glutDisplayFunc(display); 
	
	glutCreateWindow("line1"); 			//stepsize=4	
	glutDisplayFunc(display1); 
	
	glutCreateWindow("line2"); 			//stepsize=3
	glutDisplayFunc(display2); 
	
	glutCreateWindow("line3"); 			//stepsize=2
	glutDisplayFunc(display3);
	
	glutCreateWindow("line4"); 			//stepsize=1
	glutDisplayFunc(display4);  
	
	
	glutMainLoop(); 
} 

