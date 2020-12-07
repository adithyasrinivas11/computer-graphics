
#include <stdio.h> 
#include <math.h> 
#include <GL/glut.h> 
#define maxHt 800 
#define maxWd 600 
#define maxVer 10000 

FILE *fp; 


typedef struct edgebucket 
{ 
	int ymax; 
	float xofymin;
	float slp_inv; 
}EdgeBucket; 

typedef struct edgetabletup 
{ 

	int countEdgeBucket;
	EdgeBucket buckets[maxVer]; 
}EdgeTableTuple; 

EdgeTableTuple EdgeTable[maxHt], ActiveEdgeTuple; 


void initEdgeTable() 
{ 
	int i; 
	for (i=0; i<maxHt; i++) 
	{ 
		EdgeTable[i].countEdgeBucket = 0; 
	} 
	
	ActiveEdgeTuple.countEdgeBucket = 0; 
} 


void insertionSort(EdgeTableTuple *ett) 
{ 
	int i,j; 
	EdgeBucket temp; 

	for (i = 1; i < ett->countEdgeBucket; i++) 
	{ 
		temp.ymax = ett->buckets[i].ymax; 
		temp.xofymin = ett->buckets[i].xofymin; 
		temp.slp_inv = ett->buckets[i].slp_inv; 
		j = i - 1; 

	while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0)) 
	{ 
		ett->buckets[j + 1].ymax = ett->buckets[j].ymax; 
		ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin; 
		ett->buckets[j + 1].slp_inv = ett->buckets[j].slp_inv; 
		j = j - 1; 
	} 
	ett->buckets[j + 1].ymax = temp.ymax; 
	ett->buckets[j + 1].xofymin = temp.xofymin; 
	ett->buckets[j + 1].slp_inv = temp.slp_inv; 
	} 
} 


void str_edge_tup (EdgeTableTuple *receiver,int ym,int xm,float slopInv) 
{ 
	
	(receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym; 
	(receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm; 
	(receiver->buckets[(receiver)->countEdgeBucket]).slp_inv = slopInv; 
			
	// sort the buckets 
	insertionSort(receiver); 
		
	(receiver->countEdgeBucket)++; 
	
	
} 

void str_ed_tab (int x1,int y1, int x2, int y2) 
{ 
	float m,minv; 
	int ymaxTS,xwithyminTS, scanline; 
	
	if (x2==x1) 
	{ 
		minv=0.000000; 
	} 
	else
	{ 
	m = ((float)(y2-y1))/((float)(x2-x1)); 
	

	if (y2==y1) 
		return; 
		
	minv = (float)1.0/m; 
	
	} 
	
	if (y1>y2) 
	{ 
		scanline=y2; 
		ymaxTS=y1; 
		xwithyminTS=x2; 
	} 
	else
	{ 
		scanline=y1; 
		ymaxTS=y2; 
		xwithyminTS=x1;	 
	} 

	str_edge_tup(&EdgeTable[scanline],ymaxTS,xwithyminTS,minv); 
	
	
} 

void removeEdgeByYmax(EdgeTableTuple *Tup,int yy) 
{ 
	int i,j; 
	for (i=0; i< Tup->countEdgeBucket; i++) 
	{ 
		if (Tup->buckets[i].ymax == yy) 
		{ 
			//printf("\nRemoved at %d",yy); 
			
			for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ ) 
				{ 
				Tup->buckets[j].ymax =Tup->buckets[j+1].ymax; 
				Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin; 
				Tup->buckets[j].slp_inv = Tup->buckets[j+1].slp_inv; 
				} 
				Tup->countEdgeBucket--; 
			i--; 
		} 
	} 
}	 


void upd_slop_inv(EdgeTableTuple *Tup) 
{ 
	int i; 
	
	for (i=0; i<Tup->countEdgeBucket; i++) 
	{ 
		(Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slp_inv; 
	} 
} 


void ScanlineFill() 
{ 
	


	int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount; 
	
	
	for (i=0; i<maxHt; i++)
	{ 
		for (j=0; j<EdgeTable[i].countEdgeBucket; j++) 
		{ 
	str_edge_tup(&ActiveEdgeTuple,EdgeTable[i].buckets[j].ymax,EdgeTable[i].buckets[j].xofymin,EdgeTable[i].buckets[j].slp_inv); 
		} 
		//printTuple(&ActiveEdgeTuple); 
		
		removeEdgeByYmax(&ActiveEdgeTuple, i); 
		
		//sort AET (remember: ET is presorted) 
		insertionSort(&ActiveEdgeTuple); 
		
		//printTuple(&ActiveEdgeTuple); 
		
	
		j = 0; 
		FillFlag = 0; 
		coordCount = 0; 
		x1 = 0; 
		x2 = 0; 
		ymax1 = 0; 
		ymax2 = 0; 
		while (j<ActiveEdgeTuple.countEdgeBucket) 
		{ 
			if (coordCount%2==0) 
			{ 
				x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin); 
				ymax1 = ActiveEdgeTuple.buckets[j].ymax; 
				if (x1==x2) 
				{ 
				
					if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))) 
					{ 
						x2 = x1; 
						ymax2 = ymax1; 
					} 
				
					else
					{ 
						coordCount++; 
					} 
				} 
				
				else
				{ 
						coordCount++; 
				} 
			} 
			else
			{ 
				x2 = (int)ActiveEdgeTuple.buckets[j].xofymin; 
				ymax2 = ActiveEdgeTuple.buckets[j].ymax; 
			
				FillFlag = 0; 
				
				if (x1==x2) 
				{ 
				
					if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2))) 
					{ 
						x1 = x2; 
						ymax1 = ymax2; 
					} 
					else
					{ 
						coordCount++; 
						FillFlag = 1; 
					} 
				} 
				else
				{ 
						coordCount++; 
						FillFlag = 1; 
				} 
			
			
			if(FillFlag) 
			{ 
				
				glColor3f(0.0f,0.7f,0.0f); 
				
				glBegin(GL_LINES); 
				glVertex2i(x1,i); 
				glVertex2i(x2,i); 
				glEnd(); 
				glFlush();		 
				

			} 
			
		} 
			
		j++; 
	} 
			
	upd_slop_inv(&ActiveEdgeTuple); 
} 


printf("\nScanline poly fill completed"); 

} 


void myInit(void) 
{ 

	glClearColor(1.0,1.0,1.0,0.0); 
	glMatrixMode(GL_PROJECTION); 
	
	glLoadIdentity(); 
	gluOrtho2D(0,maxHt,0,maxWd); 
	glClear(GL_COLOR_BUFFER_BIT); 
} 

void draw_display() 
{ 

	glColor3f(0.0f,0.0f,1.0f); 
	int count = 0,x1,y1,x2,y2; 
	rewind(fp); 
	while(!feof(fp) ) 
	{ 
		count++; 
		if (count>2) 
		{ 
			x1 = x2; 
			y1 = y2; 
			count=2; 
		} 
		if (count==1) 
		{ 
			fscanf(fp, "%d,%d", &x1, &y1); 
		} 
		else
		{ 
			fscanf(fp, "%d,%d", &x2, &y2); 
			printf("\n%d,%d", x2, y2); 
			glBegin(GL_LINES); 
				glVertex2i( x1, y1); 
				glVertex2i( x2, y2); 
			glEnd(); 
			str_ed_tab(x1, y1, x2, y2);//storage of edges in edge table. 
			
			
			glFlush(); 
		} 
	} 
		
		
} 

void draw(void) 
{ 
	initEdgeTable(); 
	draw_display(); 
	printf("\nTable"); 
	
	ScanlineFill();
} 

void main(int argc, char** argv) 
{ 
	fp=fopen ("input.txt","r"); 
	if ( fp == NULL ) 
	{ 
		printf( "Could not open file" ) ; 
		return; 
	} 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(maxHt,maxWd); 
	glutInitWindowPosition(100, 150); 
	glutCreateWindow("Scanline filled "); 
	myInit(); 
	glutDisplayFunc(draw); 
	
	glutMainLoop(); 
	fclose(fp); 
} 

