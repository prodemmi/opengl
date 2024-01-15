#include<GL/glut.h>
#include<iostream>
#include<random>

void init() {
	glClearColor(0.7, 0.7, 0.7, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void setpixel(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}

void oval(int rx, int ry)
{
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3d(0, 1, 0.4);

	oval(20, 40);
	glFlush();
}


int main(int argc, char** argv) {
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