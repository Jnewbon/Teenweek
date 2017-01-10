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
	enum text_location {
		TEXT_QUESTION,
		TEXT_INFO,
		TEXT_ANSWER,
		No_Text_Objects
	};
	enum text_mod_type {
		APPEND,
		REPLACE
	};

	game(int argc, char** argv);

	void set_screensize(int size_x, int size_y, bool fullscreen);
	void set_screensize(glm::vec2 size, bool fullscreen);

	void init(void);

	void mainloop();
	static void collision();
	static bool isColliding(Dynamic_image_obj* first, Dynamic_image_obj* second);




	static GLuint				default_shader;
	static glm::vec2			screenSize;			//Contains the Size of the screen

	static bool	recive_message(game_msg newMsg);

private:
//#####	Functions ######

	void init_glut();
	void init_glew();

	static void	addScore(int score);


	static void showText(text_location, text_mod_type, std::string);

	
//#####	Variables ######

	//Startup 
	int					argc;
	char**				argv;


	//Game Variables

	static std::list<display_object*>		allDisplayObjects;				//Contains all object to be displayed to the screen
	static display_object*					player;							// This will be the player
	static unsigned	int						score;							//This will be the players score
	//static text_object*						text_panels[No_Text_Objects];	//This will be the text panels displayed on the screen

	//OpenGL Variables

	static bool					fullscreen;			//is the game fullscreen (default false)

	//callbacks
	//These dont need to be made public as there address is passed out to glut
	static void display();
	static void event_mouseMove(int x,int y);
	static void event_mouseClick(int button, int state, int x, int y);
	static void event_keyPress(unsigned char key, int x, int y);
	static void event_keyPressUP(unsigned char key, int x, int y);
	static void event_specialkey(int key, int x, int y);
	static void event_specialkeyUP(int key, int x, int y);
};