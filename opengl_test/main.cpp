#include <GL/glut.h>
#include <iostream>
#include <string>
#include <functional>
#include <memory>

#include "Painter.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"
#include "GlutTimerWrapper.h" 
#include <list>
#include "SOIL.h"

using namespace std;

//singleton
class Application {
private:
	static Application* pApplication;
	Application() {
		glClearColor(0.0, 0.0, 0.0, 1.0);
		/*figures.push_back(make_unique<Point>(Point(0.2, 0.4, 0.0)));
		figures.push_back(make_unique<Line>(Line(Point(0.1, 0.6, 0.0), Point(0.04, 0.4, 0.0))));*/
		//figures.push_back(make_unique<Circle>( Circle(Point(0.4, 0.1, 0.3), 60)));
		//figures.push_back(make_unique<Triangle>(Point(0.3, 0.23, 0.5), Point(0.6, 0.2, 0.45), Point(0.23, 0.45, 0.76)));
		Circle circ(Point(0.2, 0.5, 0.23), 0.2);
		circ.setPainter(new CircleFromTriangles(&circ));
		figures.push_back(make_unique<Circle>(circ));
	}
	Application(const Application&);
	Application& operator=(Application&);


	std::list<unique_ptr<Shape>> figures;

public:
	static Application* getApplication() {
		if (!pApplication) 
			pApplication = new Application();
		return pApplication;
	}

	void display() {
		glClear(GL_COLOR_BUFFER_BIT);	//clear color buffer
		glColor3f(0.0, 0.3, 0.0);
		for (unique_ptr<Shape>& figure : figures)
			figure->draw();


		glutSwapBuffers();
	}
};
Application* Application::pApplication = nullptr;

void display() {
	Application::getApplication()->display();
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
	Window window(300, 300, 100, 100, GLUT_DOUBLE | GLUT_RGBA, "myWindow");
	window.setDisplayFunc(display);
	
	GLuint tex_2d = SOIL_load_OGL_texture
	(
		"Space.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);


	window.mainLoop();
	system("pause");
	return 0;
}