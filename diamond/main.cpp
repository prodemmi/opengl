#include<GL/glut.h>

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

void drawDiamond1() {
	for (int i = 0; i <= 200; i++) {
		line(-100 + i, -100 - i, 100 + i, 100 - i);
	} 
}

void drawDiamond2() {
	for (int i = 0; i <= 200; i++) {
		line(0 - i, -i, i, - i);
	}

	for (int i = 0; i <= 200; i++) {
		line(-200 + i, -200 - i, 200 - i, -200 - i);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3d(1, 0, 0);

	// drawDiamond1();
	drawDiamond2();
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