#pragma once
#include <glm/glm.hpp>
#include <GL\glew.h>
#include <time.h>
#include <list>

#include "display_object.h"

class game
{
public:
	game(int argc, char** argv);

	void set_screensize(int size_x, int size_y, bool fullscreen);
	void set_screensize(glm::vec2 size, bool fullscreen);

	void init(void);

	void mainloop();


	//callbacks

	static void display();
	static void event_mouseMove(int x,int y);
	static void event_mouseClick(int button, int state, int x, int y);
	static void event_keyPress(int key, int state);


	static GLuint		default_shader;

private:
//#####	Functions ######

	void init_glut();
	void init_glew();
	
//#####	Variables ######

	//Startup 
	int					argc;
	char**				argv;


	//Game Variables

	static clock_t					last;				// Contains the time of the last frames, used to calculate how log has passed sine last execute time
	static std::list<display_object*>		allDisplayObjects;	//Contains all object to be displayed to the screen

	//OpenGL Variables

	glm::vec2			screeSize;			//Contains the Size of the screen
	bool				fullscreen;			//is the game fullscreen (default false)

};