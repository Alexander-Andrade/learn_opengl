#include <GL/glut.h>
#include <iostream>

using namespace std;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0, 0, 1);
	//glutSolidSphere(0.5, 45, 15);
	/*glRotatef(60, 1.0, 0.0, 1.0);
	glutWireSphere(0.5, 45, 15);
	glColor3f(0, 1, 1);
	glutWireCube(0.5);*/
	glRotatef(60, 1.0, 0.0, 1.0);
	glutWireTetrahedron();;
	glFlush();
} 

void init() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 143);
	glutCreateWindow("Circle");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	init();
	glutDisplayFunc(display);
	glutMainLoop(); 

}