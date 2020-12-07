//To Compile: gcc filename.c -lGL -lGLU -lglut -lm 
// C Program to illustrate  
// OpenGL animation for revolution 
  
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
  
// global declaration 
int x, y; 
int X, Y;
float i, j, k; 
  
// Initialization function 
void myInit (void) 
{ 
    // Reset background color with black (since all three argument is 0.0) 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // Set picture color to green (in RGB model) 
    // as only argument corresponding to G (Green) is 1.0 and rest are 0.0 
    glColor3f(0.0, 1.0, 0.0); 
      
    // Set width of point to one unit 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
      
    // Set window size in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 
} 
  
// Function to display animation 
void display (void) 
{ 
    // Outer loop to make figure moving 
    // loop variable j iterated up to 10000, 
    // indicating that figure will be in motion for large amount of time 
    // around 10000/6.29 = 1590 time it will revolve 
    // j is incremented by small value to make motion smoother 
    for (j = 0; j < 10000; j += 0.01) 
    { 
        glClear(GL_COLOR_BUFFER_BIT); 
        glBegin(GL_POINTS); 
          
        for (i = 0;i < 6.29;i += 0.001) 
        { 
            x = 200 * cos(i); 
            y = 200 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 
        
            X=x / 2 - 600 * cos(j);
            Y=y / 2 - 100 * sin(j);
		glColor3f(0.0, 0.0, 1.0);
            glVertex2i(X,Y); 
            
		
		glColor3f(0.5, 0.5, 0.5); 		 
            glVertex2i(x/4 - 200*cos(2*j) - 600*cos(j), y/4 - 150*sin(2*j) - 100*sin(j)); 

            
        } 
         
        // 7 loops to draw parallel latitude 
        for (i = 1.17; i < 1.97; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -150 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y);
            glColor3f(0.0, 0.0, 1.0);  
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
            
        } 
          
        for (i = 1.07; i < 2.07; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -200 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 
             glColor3f(0.0, 0.0, 1.0); 
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j)); 
            
        } 
          
        for (i = 1.05; i < 2.09; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -250 + 300 * sin(i);
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
            
        } 
          
        for (i = 1.06; i < 2.08; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -300 + 300 * sin(i);
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j)); 
            
        } 
          
        for (i = 1.10; i < 2.04; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -350 + 300 * sin(i);
            glColor3f(1.0, 1.0, 0.0);  
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
            
        } 
          
        for (i = 1.16; i < 1.98; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -400 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));
          
        } 
          
        for (i = 1.27; i < 1.87; i += 0.001) 
        { 
            x = 400 * cos(i); 
            y = -450 + 300 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 
            glColor3f(0.0, 0.0, 1.0); 
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j)); 
            
        } 
        
        // Loop is to draw vertical line 
        for (i = 200; i >=- 200; i--) 
        { 
		glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(0, i); 

        } 
          
        // 3 loops to draw vertical ellipse (similar to longitude) 
        for (i = 0;i < 6.29; i += 0.001) 
        { 
            x = 70 * cos(i); 
            y = 200 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0);  
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j)); 
           // glVertex2i(x/4 - 200*cos(2*j) - 600*cos(j), y/4 - 150*sin(2*j) - 100*sin(j)); 
        } 
          
        for (i = 0; i < 6.29; i += 0.001) 
        { 
            x = 120 * cos(i); 
            y = 200 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0);  
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j));

        } 
          
        for (i = 0; i < 6.29; i += 0.001) 
        { 
            x = 160 * cos(i); 
            y = 200 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 
            glColor3f(0.0, 1.0, 0.0);  
            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j)); 

        } 
        //Loop to make orbit of revolution 
        for (i = 0; i < 6.29; i += 0.001) 
        { 
            x = 600 * cos(i); 
            y = 100 * sin(i); 
            glColor3f(1.0, 1.0, 0.0); 
            glVertex2i(x, y); 

            x = 200 * cos(i); 
            y = 150 * sin(i);
            glColor3f(0.0, 1.0, 0.0);  
            glVertex2i(x - 600*cos(j), y - 100*sin(j)); 

        } 
        
        glEnd(); 
        glFlush(); 
  }
} 
  
// Driver Program 
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
      
    // Display mode which is of RGB (Red Green Blue) type 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // Declares window size 
    glutInitWindowSize(1360, 768); 
      
    // Declares window position which is (0, 0) 
    // means lower left corner will indicate position (0, 0) 
    glutInitWindowPosition(0, 0); 
  
    // Name to window 
    glutCreateWindow("sun_moon"); 
  
    // Call to myInit() 
    myInit(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 
