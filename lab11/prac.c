// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 

int xmin,ymin,xmax,ymax;
void display (void) 
{ 
	
	double x[1000],y[1000];
	int b1,b3,b2,b4;
	int a1,a3,a2,a4;
	for(int i =0;i<1000;i++)
	{
		x[i] = rand()%300;
		y[i]= rand()%300;
	}
	//x[0]=-20;
	//x[1]=500;
	//y[0]=500;
	//y[1]=-100;
	//printf("%lf %lf  %lf %lf",x[0],y[0],x[1],y[1]);
	int c1[4],c2[4];
	
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glColor3f(1.0, 0.0, 1.0);
	//gluOrtho2D(-780, 780, -420, 420);
	glBegin(GL_LINES); 
	//glVertex2f(x[0], y[0]);
	//glVertex2f(x[1], y[1]);
	glVertex2f(xmin, ymin);
	glVertex2f(xmin, ymax);
	glVertex2f(xmin, ymax);
	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmin, ymin);
	glEnd(); 
	
	glFlush(); 
	
	glBegin(GL_LINES); 
	for(int i =0;i<1000;i+=2)
	{
		if(i==64)
			printf("%lf %lf %lf %lf",x[i],y[i],x[i+1],y[i+1]);
		if(x[i]>=xmin)
			c1[3]=0;
		else
			c1[3]=1;

		if(x[i]<=xmax)
			c1[2]=0;
		else
			c1[2]=1;
		//printf("c3= %d xmax = %d \n",c1[2],xmax);	
		if(y[i]>=ymin)
			c1[1]=0;
		else
			c1[1]=1;
			
		if(y[i]<=ymax)
			c1[0]=0;
		else
			c1[0]=1;
		
		//////////////////////////////check point 2/////////////////////////////
		if(x[i+1]>=xmin)
			c2[3]=0;
		else
			c2[3]=1;
			
		if(x[i+1]<=xmax)
			c2[2]=0;
		else
			c2[2]=1;
			
		if(y[i+1]>=ymin)
			c2[1]=0;
		else
			c2[1]=1;
			
		if(y[i+1]<=ymax)
			c2[0]=0;
		else
			c2[0]=1;
			
		//printf(" code is %d  %d  %d  %d  ------ %d  %d  %d  %d \n ",c1[0],c1[1],c1[2],c1[3],c2[0],c2[1],c2[2],c2[3]);
		if(y[i]-ymax >0)
			b1=1;
		else
			b1=0;
			
		if(ymin-y[i] >0)
			b2=1;
		else
			b2=0;
		
		if(x[i]-xmax >0)
			b3=1;
		else
			b3=0;
			
		if(xmin-x[i] >0)
			b4=1;
		else
			b4=0;
		///////////////////////////////////////////////////////////////
		if(y[i+1]-ymax >0)
			a1=1;
		else
			a1=0;
			
		if(ymin-y[i+1] >0)
			a2=1;
		else
			a2=0;
		
		if(x[i+1]-xmax >0)
			a3=1;
		else
			a3=0;
			
		if(xmin-x[i+1] >0)
			a4=1;
		else
			a4=0;
		///////////////////////////////trivial check/////////////////////////////////////////
		if(c1[0] == 0 && c1[1] == 0 && c1[2] ==0 && c1[3] == 0 && (c2[0] == 0 && c2[1] == 0 && c2[2] ==0 && c2[3] == 0))
		{
			glColor3f(1.0, 0.4, 0.2);
			glVertex2f(x[i], y[i]);
			glVertex2f(x[i+1], y[i+1]);
		}
		
		else
		{
			double slope =(double)(y[i+1]-y[i])/(x[i+1]-x[i]);
			double Z1,Z2,W1,W2;
			Z1=x[i];
			W1=y[i];	
			if(b1 == 1)
			{
				Z1=x[i]+((ymax-y[i])/slope);
				W1=ymax;
				if(Z1>xmin)
					b4=0;
				
		//		printf("151\n");
				
			}
			if(b2 == 1)	
			{	
				Z1=x[i]+((ymin-y[i])/slope);
				W1=ymin;
				if(Z1<xmax)
					b3=0;
		//		printf("160\n");
			}
			if(b3 == 1)
			{
				W1=slope*(xmax-x[i])+y[i];
				Z1=xmax;
				if(W1>ymax)
					W1=ymax;
		//						printf("166\n");
			}
			if(b4 == 1)
			{
				W1=slope*(xmin-x[i])+y[i];
				Z1=xmin;
				if(W1<ymin)
					W1=ymin;
		//						printf("172\n");
			}
			Z2=x[i+1];
			W2=y[i+1];	
			if(a1 == 1)
			{
				Z2=x[i]+((ymax-y[i])/slope);
				W2=ymax;
				if(Z2>xmin)
					a4=0;
				//printf("184\n");
			}
			if(a2 == 1)	
			{	
				Z2=x[i]+((ymin-y[i])/slope);
				W2=ymin;
				if(Z2<xmax)
					a3=0;
				//printf("192\n");
			}
			if(a3 == 1)
			{
				W2=slope*(xmax-x[i])+y[i];
				if(W2>ymax)
					W2=ymax;
				Z2=xmax;
				
				
				//printf("198\n");
			}
			if(a4 == 1)
			{
				W2=slope*(xmin-x[i])+y[i];
				Z2=xmin;
				if(W2<ymin)
					W2=ymin;
				//printf("203\n");
			}
			
			
			
			//Z1=x[i];
			//Z2=x[i+1];
			//printf("%lf %lf %lf %lf \n",y[i+1],y[i],x[i+1],x[i]);

			//printf("slope =%lf \n",slope);
			
			
			
			printf("W1 = %lf W2= %lf   i= %d \n ",W1,W2,i);
			//printf("else case\n");
			if((c1[0]!=1 || c2[0]!=1) && (c1[1]!=1 || c2[1]!=1) && (c1[2]!=1 || c2[2]!=1) && (c1[3]!=1 || c2[3]!=1) )
			{
				glColor3f(0.0, 0.8, 0.5);
				glVertex2f(Z1, W1);
				glVertex2f(Z2, W2);
				
			}
						
		}
		
	}
	glEnd(); 
	

	glFlush(); 
} 

void display2 (void) 
{ 
	int x[1000],y[1000];
	for(int i =0;i<1000;i++)
	{
		x[i] = rand()%300;
		y[i]= rand()%300;
	}
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 		//clear buffers to preset values
	
	glColor3f(0.0, 0.0, 1.0);
	gluOrtho2D(-780, 780, -420, 420);
	glColor3f(1.0, 0.0, 1.0);
	//gluOrtho2D(-780, 780, -420, 420);
	
	glColor3f(1.0, 0.8, 0.4);
	glBegin(GL_LINES); 
	for(int i =0;i<1000;i+=2)
	{	
		
		glVertex2f(x[i], y[i]);
		glVertex2f(x[i+1], y[i+1]);
	}
	glEnd(); 
	glFlush(); 
}

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 						 //glutInit is used to initialize the GLUT library. 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 		// glutInitDisplayMode sets the initial display mode.  Bit mask to select a single buffered window.|Bit mask to select an RGBA mode window
	
	xmin=atoi(argv[1]);
	ymin=atoi(argv[2]);
	
	xmax=atoi(argv[3]);
	ymax=atoi(argv[4]);
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768);  // size od window
	glutInitWindowPosition(0, 0); 	
	
	// Giving name to window 
	glutCreateWindow("2 Drawing 1"); 			//name
	//myInit(); 
	
	glutDisplayFunc(display); 
	
	glutCreateWindow(" Drawing2"); 			//name
	glutDisplayFunc(display2); 
	glutMainLoop();
	
	
} 

