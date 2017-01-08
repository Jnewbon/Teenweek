#include "cls_game.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <texture_loader.h>
#include "Shader_Setup.h"
#include <iostream>
#include "defines.h"
#include "factory.h"

using namespace std;

GLuint game::default_shader = 0;

clock_t						game::last = 0;
std::list<display_object*>	game::allDisplayObjects;	//Contains all object to be displayed to the screen
glm::vec2					game::screenSize;			//Contains the Size of the screen
bool						game::fullscreen;			//is the game fullscreen (default false)

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
	this->screenSize = size;
}

void game::init(void)
{
	init_glut();
	init_glew();

	this->default_shader =setupShaders(std::string("resources\\shaders\\vertex_shader_Matrix.vert"), std::string("resources\\shaders\\texture_fragment_shader.frag"));

	image_object::init();

}

void game::mainloop()
{
	//Example of creating a game object
	allDisplayObjects.push_back(Factory::create_object(Factory::SUPER_AWSOME_PLAYER_SHIP));
	allDisplayObjects.push_back(Factory::create_object(Factory::UI));
	allDisplayObjects.push_back(Factory::create_object(Factory::Test_Text));
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

	int elapsedTime = clock() - last;
	last = clock();

	//If the time taken to do everything would put the frame rate above MAX_FRAME_RATE then hold here till the specific time has passed
	while (elapsedTime < ((1.0f / CLOCKS_PER_SEC) * MAX_FRAME_RATE)){	
		elapsedTime = clock() - last;
	}
	
	for (list<display_object*>::iterator i = allDisplayObjects.begin();
					i != allDisplayObjects.end();
					i++)
	{
		(*i)->draw(glm::mat4(1.0f));
	}

	glutSwapBuffers();
}

void game::event_mouseMove(int x, int y)
{
#ifdef DEBUG_MOUSE_LOC
	printf("Mouse Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
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

	glutInitWindowSize((int)screenSize.x, (int)screenSize.y);
	glutInitWindowPosition(1920, 0);
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
