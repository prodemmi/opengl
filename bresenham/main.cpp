#include <GL/glut.h>

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

void bresenham(float x1, float y1, float x2, float y2)
{
	float DX = (x2 - x1);
	float DY = (y2 - y1);
	float x = x1, y = y1;

	if (DX == 0)
	{
		while (y < y2)
		{
			setpixel(x1, y);
			y++;
		}
		return;
	}
	if (DY == 0)
	{
		while (x < x2)
		{
			setpixel(x, y1);
			x++;
		}
		return;
	}

	float m = DY / DX;
	if (m == 0)
	{
		while (x < x2)
		{
			setpixel(x, y1);
		}
	}
	else if (m > 0 && m < 1)
	{
		float p = 2 * DY - DX;
		setpixel(x, y);
		while (x < x2)
		{
			if (p < 0)
			{
				p += 2 * DY;
				x++;
			}
			else
			{
				p += 2 * DY - 2 * DX;
				x++;
				y++;
			}
			setpixel(x, y);
		}
	}
	else if (m < 0 && m > -1)
	{
		float p = 2 * abs(DY) - DX;
		setpixel(x, y);
		while (x < x2)
		{
			if (p < 0)
			{
				p += 2 * abs(DY);
				x++;
			}
			else
			{
				p += 2 * abs(DY) - 2 * DX;
				x++;
				y--;
			}
			setpixel(x, y);
		}
	}
	else if (m == 1)
	{
		while (x < x2)
		{
			y++;
			x++;
			setpixel(x, y);
		}
	}
	else if (m == -1)
	{
		while (x < x2)
		{
			y--;
			x++;
			setpixel(x, y);
		}
	}
	else if (m > 1)
	{

		float p = 2 * DX - DY;
		setpixel(x, y);
		while (y < y2)
		{

			if (p < 0)
			{
				p += 2 * DX;
				y++;
			}
			else
			{
				p += 2 * DX - 2 * DY;
				x++;
				y++;
			}
			setpixel(x, y);
		}
	}
	else if (m < -1)
	{

		float p = 2 * DX - abs(DY);
		setpixel(x, y);
		while (y > y2)
		{

			if (p < 0)
			{
				p += 2 * DX;
				y--;
			}
			else
			{
				p += 2 * DX - 2 * abs(DY);
				x++;
				y--;
			}
			setpixel(x, y);
		}
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3d(1, 0, 0);
	bresenham(-400.0, -400.0, 400.0, 400.0);

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