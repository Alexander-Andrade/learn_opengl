#include <GL/glut.h>
#include <iostream>
#include <string>
#include <functional>

#include "Point.h"
using namespace std;

//singleton
class Application {
private:
	static Application* pApplication;
	Application() {
	}
	Application(const Application&);
	Application& operator=(Application&);

public:
	static Application* getApplication() {
		if (!pApplication) 
			pApplication = new Application();
		return pApplication;
	}

	void display() {
		glClear(GL_COLOR_BUFFER_BIT);	//clear color buffer
		//draw white poligon
		//glRotatef(60, 1.0, 0.0, 1.0);
		/*glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);*/
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0.1, 0.25, 0.0);
		glVertex3f(0.3, 0.9, 0.0);
		glEnd();

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POLYGON);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
		glEnd();

		glFlush();	//
	}
};
Application* Application::pApplication = nullptr;

void display() {
	Application::getApplication()->display();
} 

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);	//clear color buffer
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();

	glFlush();	//
}


class Window {
private:
	GLsizei windWidth;
	GLsizei windHeight;
	GLsizei windPosX;
	GLsizei windPosY;
	GLuint mode;
	std::string title;

	void init() {
		glutInitDisplayMode(mode);
		glutInitWindowSize(windWidth, windHeight);
		glutInitWindowPosition(windPosX, windPosY);
		glutCreateWindow(title.c_str());
	}
public:
	Window(GLsizei windWidth, GLsizei windHeight, GLsizei windPosX, GLsizei windPosY, GLuint mode,const char* title) :
	windWidth(windWidth), windHeight(windHeight), windPosX(windPosX), windPosY(windPosY), mode(mode), title(title) {
		init();
	}

	void setDisplayFunc(void (*func)()) {
		glutDisplayFunc(func);
	}

	void mainLoop() {
		glutMainLoop();
	}

	GLsizei getWindHeight() const { return windHeight; }
	GLsizei getWindWidth() const { return windWidth; }
};

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	
	/*Window window(300, 300, 100, 100, GLUT_SINGLE | GLUT_RGB, "myWindow");
	window.setDisplayFunc(display);
	window.mainLoop();
*/
	
	system("pause");
	return 0;
}