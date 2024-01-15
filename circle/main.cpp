#include<GL/glut.h>
#include<iostream>
#include<random>

void init() {
	glClearColor(0.7, 0.7, 0.7, 1.0);
	glEnable(GL_DEPTH_TEST);
}


void line(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);

	glVertex2d(x2, y2);
	glVertex2d(x1, y1);
	glEnd();
}


void setpixel(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2d(x, y);
	glEnd();
}

void drawCircle(int r)
{
	int centerx = 3;
	int centery = 3;
	int p = 1 - r;
	int x = 0;
	int y = r;

	setpixel(x, y);

	while (x <= y)
	{
		if (p < 0) {
			p = p + (2 * x) + 1;
			x = x + 1;
		}
		else {
			p = p + (2 * x) - (2 * y) + 1;
			x = x + 1;
			y = y - 1;
		}

		setpixel(x + centerx, y + centery);
		setpixel(y + centerx, x + centery);

		setpixel(-x + centerx, y + centery);
		setpixel(-y + centerx, x + centery);
		setpixel(x + centerx, -y + centery);
		setpixel(y + centerx, -x + centery);
		setpixel(-x + centerx, -y + centery);
		setpixel(-y + centerx, -x + centery);
	}
}

void drawFilledCircle(int r) {
	for (int i = r;i >=0; i--) {
		drawCircle(i);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3d(0, 1, 0.4);

	drawFilledCircle(800);
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