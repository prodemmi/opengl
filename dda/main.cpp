#include <GL/glut.h>
#include <math.h>

void init()
{
	glClearColor(0.7, 0.7, 0.7, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void setpixel(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}

void dda(int x1, int y1, int x2, int y2) 
{ 
    int dx = x2 - x1; 
    int dy = y2 - y1; 
  
    int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    float Xinc = dx / (float)step; 
    float Yinc = dy / (float)step; 
  
    float X = x1; 
    float Y = y1; 
    for (int i = 0; i <= step; i++) { 
        setpixel(round(X), round(Y)); 
        X += Xinc; 
        Y += Yinc; 
    } 
} 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3d(1, 0, 0);
	dda(-400.0, -400.0, 400.0, 400.0);

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL");
	init();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1000, 1000, -1000, 1000);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutDisplayFunc(display);
	glutMainLoop();
}