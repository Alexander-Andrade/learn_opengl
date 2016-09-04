#include <GL/glut.h>
#include <iostream>

using namespace std;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);	//clear color buffer
	//draw white poligon
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	glFlush();	//
} 

void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("WindowTitle");
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}