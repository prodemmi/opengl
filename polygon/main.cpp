///////////////////////PROGRAM BY MOHAMMAD ALI GHADERI ----------->>>>>>>>>>>>>>>>> M.A.G <<<<<<<<<<<<<<
#include <GL/glut.h>
#include <math.h>

char ch;
void init()
{
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

void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1, 0, 0);
	glColor3d(1, 0, 0);

	for (float r = 1; r < 500; r++)
	{
		float xp = r / 2.0f;
		float yp = r * 0.866025f;
		line(r, 0, xp, yp);
		line(xp, yp, -xp, yp);
		line(-xp, yp, -r, 0);

		line(-r, 0, -xp, -yp);
		line(-xp, -yp, xp, -yp);
		line(xp, -yp, r, 0);
	}

	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	ch = key;
	glutPostRedisplay();
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}