#include "cls_game.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <texture_loader.h>
#include <iostream>
#include "defines.h"

using namespace std;

game::game(int argc, char ** argv)
{
	//set the startup variables used by glut/glew init
	this->argc = argc;
	this->argv = argv;
}

void game::set_screensize(int size_x, int size_y, bool fullscreen)
{
	set_screensize(glm::vec2(size_x, size_y), fullscreen);
}

void game::set_screensize(glm::vec2 size, bool fullscreen)
{
	this->fullscreen = fullscreen;
	this->screeSize = size;
}

void game::init(void)
{
	init_glut();
	init_glew();
}

void game::mainloop()
{
	while (true)
	{
		//Enter glut events and display
		glutMainLoopEvent();
		glutPostRedisplay();
	}

	shutdownCOM();

}

void game::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void game::event_mouseMove(int x, int y)
{
#ifdef DEBUG_MOUSE_LOC
	cout << "Mouse Loc {" << x << ",\t" << y << "}" << endl;
#endif
}

void game::event_mouseClick(int button, int state, int x, int y)
{
}

void game::event_keyPress(int key, int state)
{
}

void game::init_glut()
{
	initCOM();
	glutInit(&argc, argv);

	glutInitContextVersion(3, 1);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize((int)screeSize.x, (int)screeSize.y);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Teen Week Interactive Demo by Jamie Newbon and Matthew Potter");

	if (fullscreen)
		glutFullScreenToggle();

	// display callback
	glutDisplayFunc(game::display);
	glutMouseFunc(game::event_mouseClick);
	glutPassiveMotionFunc(game::event_mouseMove);


	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
}

void game::init_glew()
{	// initialise glew library
	GLenum err = glewInit();

	// ensure glew was initialised successfully before proceeding
	if (err == GLEW_OK)
		cout << "GLEW initialised okay\n";
	else
		throw "Unable to initilize GLEW";

	glClearColor(0.0, 0.0, 0.0, 0.0);

	// report maximum number of vertex attributes
	GLint numAttributeSlots;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &numAttributeSlots);
	cout << "GL_MAX_VERTEX_ATTRIBS = " << numAttributeSlots << endl;
}
