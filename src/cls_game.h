#pragma once
#include <glm/glm.hpp>
#include <GL\glew.h>
#include <time.h>
#include <list>

#include "display_object.h"
#include "game_messages.h"

class game
{
public:
	game(int argc, char** argv);

	void set_screensize(int size_x, int size_y, bool fullscreen);
	void set_screensize(glm::vec2 size, bool fullscreen);

	void init(void);

	void mainloop();
	static void collision();
	static bool isColliding(Dynamic_image_obj* first, Dynamic_image_obj* second);


	//callbacks

	static void display();
	static void event_mouseMove(int x,int y);
	static void event_mouseClick(int button, int state, int x, int y);
	static void event_keyPress(unsigned char key, int x, int y);
	static void event_keyPressUP(unsigned char key, int x, int y);
	static void event_specialkey(int key, int x, int y);
	static void event_specialkeyUP(int key, int x, int y);


	static GLuint				default_shader;
	static glm::vec2			screenSize;			//Contains the Size of the screen

	static bool	recive_message(game_msg newMsg);

private:
//#####	Functions ######

	void init_glut();
	void init_glew();

	static void	addScore(int score);
	
//#####	Variables ######

	//Startup 
	int					argc;
	char**				argv;


	//Game Variables

	//static clock_t							last;				// Contains the time of the last frames, used to calculate how log has passed sine last execute time
	static std::list<display_object*>		allDisplayObjects;	//Contains all object to be displayed to the screen

	static display_object*				player;

	static unsigned	int					score;

	//OpenGL Variables

	static bool					fullscreen;			//is the game fullscreen (default false)

};