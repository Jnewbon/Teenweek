#include "cls_game.h"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <texture_loader.h>
#include "Shader_Setup.h"
#include <iostream>
#include "wtypes.h"
#include "defines.h"
#include "factory.h"
#include "player_object.h"
#include <chrono>

using namespace std;

GLuint game::default_shader = 0;

//clock_t						game::last = 0;
std::list<display_object*>	game::allDisplayObjects;	//Contains all object to be displayed to the screen
glm::vec2					game::screenSize;			//Contains the Size of the screen
bool						game::fullscreen;			//is the game fullscreen (default false)
display_object*				game::player = nullptr;
unsigned int				game::score = 0;

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

	allDisplayObjects.push_back(Factory::create_object(Factory::BACKGROUND));
	allDisplayObjects.push_back(Factory::create_object(Factory::BACKGROUND2));
	player = Factory::create_object(Factory::PLAYER_SHIP);

	allDisplayObjects.push_back(player);
	allDisplayObjects.push_back(Factory::create_object(Factory::ENEMY_ONE));
	allDisplayObjects.push_back(Factory::create_object(Factory::GAME_UI));
	allDisplayObjects.push_back(Factory::create_object(Factory::INFO_TEXT));
	allDisplayObjects.push_back(Factory::create_object(Factory::QUESTION_TEXT));
	allDisplayObjects.push_back(Factory::create_object(Factory::ANSWER_TEXT));

	while (true)
	{
	
		//TODO Remove this and put it in a better location

		static int spawnrate = 0;

		if (spawnrate++ > 150)
		{
			allDisplayObjects.push_back(Factory::create_object(Factory::ENEMY_ONE));
			spawnrate = 0;
		}




		static text_object* Score = (text_object*)Factory::create_object(Factory::ANSWER_TEXT);




		static std::chrono::steady_clock::time_point lasttime = std::chrono::steady_clock::now();
		std::chrono::steady_clock::time_point thistime = std::chrono::steady_clock::now();

		long long elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(thistime - lasttime).count();

		while (elapsedTime < (1000000 / MAX_FRAME_RATE))
		{
			//cout << "Waiting " << (1000000 / MAX_FRAME_RATE) - elapsedTime << "ms" << endl;

			std::chrono::steady_clock::time_point thistime = std::chrono::steady_clock::now();

			elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(thistime - lasttime).count();
		}
		lasttime = thistime;

		//Enter glut events and display
		glutPostRedisplay();
		glutMainLoopEvent();


		for (list<display_object*>::iterator i = allDisplayObjects.begin();
			i != allDisplayObjects.end();
			i++)
		{
			if ((*i)->getType() == display_object::GAME_OBJECT ||
				(*i)->getType() == display_object::PLAYER_OBJECT || 
				(*i)->getRenderLayer() == display_object::BACKGROUND)
			{
				((Dynamic_image_obj*)(*i))->move((float)elapsedTime/1000000);
			}
		}

		collision();

	}

	shutdownCOM();

}

void game::collision()
{

	for (list<display_object*>::iterator i = allDisplayObjects.begin();
		i != allDisplayObjects.end();
		i++)
	{
		for (list<display_object*>::iterator j = std::next(i);
			j != allDisplayObjects.end();
			j++)
		{
			if (((*i)->getType() == display_object::PLAYER_OBJECT && 
				(*j)->getType() == display_object::GAME_OBJECT) ||
				((*j)->getType() == display_object::PLAYER_OBJECT &&
				(*i)->getType() == display_object::GAME_OBJECT) ||
				((*j)->getType() == display_object::GAME_OBJECT &&
				(*i)->getType() == display_object::GAME_OBJECT))
			{
				
				Dynamic_image_obj* bullet = nullptr;
				Dynamic_image_obj* ship = nullptr;
				player_object*	player = nullptr;

				switch (((Dynamic_image_obj*)(*i))->getObjectType())
				{
				case Dynamic_image_obj::PLAYER:
					player = (player_object*)(*i);
					break;
				case Dynamic_image_obj::PLAYER_WPN:
					bullet = (Dynamic_image_obj*)(*i);
					break;
				case Dynamic_image_obj::ENEMY_WPN:
					bullet = (Dynamic_image_obj*)(*i);
					break;
				case Dynamic_image_obj::SHIP:
					ship = (Dynamic_image_obj*)(*i);
					break;
				}
				switch (((Dynamic_image_obj*)(*j))->getObjectType())
				{
				case Dynamic_image_obj::PLAYER:
					player = (player_object*)(*j);
					break;
				case Dynamic_image_obj::PLAYER_WPN:
					bullet = (Dynamic_image_obj*)(*j);
					break;
				case Dynamic_image_obj::ENEMY_WPN:
					bullet = (Dynamic_image_obj*)(*j);
					break;
				case Dynamic_image_obj::SHIP:
					ship = (Dynamic_image_obj*)(*j);
					break;
				}
				if (player && bullet)
				{
					if (isColliding(player, bullet))
					{
						//just make sure its not the players bullet
						if (bullet->getObjectType() != Dynamic_image_obj::PLAYER_WPN)
						{
							printf("oooo player done bad\n");
							bullet->setDestroyed();
							addScore(-100);

						}
					}
				}
				if (player && ship)
				{
 					if (isColliding(player, ship))
					{
						printf("oooo player done bad\n");
						ship->setDestroyed();
						addScore(-100);
					}
				}
				else if ((ship && bullet))
				{
					if (isColliding(ship, bullet))
					{
						//just make sure its not the ships bullet
						if (bullet->getObjectType() != Dynamic_image_obj::ENEMY_WPN)
						{
							printf("Player gets points yey\n");
							bullet->setDestroyed();
							ship->setDestroyed();
							addScore(100);
						}
					}	
				}
			}
		}
	}

	for (list<display_object*>::iterator i = allDisplayObjects.begin();
		i != allDisplayObjects.end();
		i++)
	{
		if (((Dynamic_image_obj*)(*i))->getType() == display_object::GAME_OBJECT &&
			((*i)->getLocation().x < -1.5f ||
			(*i)->getLocation().x >  1.5f ||
			(*i)->getLocation().y < -1.5f ||
			(*i)->getLocation().y >  1.5f || 
			((Dynamic_image_obj*)(*i))->getDestroyed()))
		{
			allDisplayObjects.erase(i);
			i = allDisplayObjects.begin();
		}
	}
	//printf("Array Size: %i\n", allDisplayObjects.size());

}

bool game::isColliding(Dynamic_image_obj * first, Dynamic_image_obj * second)
{
	glm::vec2 frLoc = first->getLocation();
	glm::vec2 scLoc = second->getLocation();
	glm::vec2 frSca = first->getScale();
	glm::vec2 scSca = second->getScale();
	//printf("{%i%i%i%i}\t{%f,%f}\n", frLoc.y + frSca.y < scLoc.y, frLoc.x < scLoc.x + scSca.x, frLoc.x + frSca.x > scLoc.x, frLoc.y > scLoc.y + scSca.y, frLoc.y + frSca.y,scLoc.y);

	if (frLoc.y + frSca.y < scLoc.y)//is first to far below second to collid?
		return false;
	if (frLoc.x > scLoc.x + scSca.x)//is first too far to the right to collide?
		return false;
	if (frLoc.x + frSca.x < scLoc.x)//is first too far to the left to collide?
		return false;
	if (frLoc.y > scLoc.y + scSca.y)//is first too far to the above to collide?
		return false;

	//If we get here then the two objects have collided

	return true;


}

void game::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	for (int j = 0; j < display_object::Num_of_Layers; j++)
	{
		for (list<display_object*>::iterator i = allDisplayObjects.begin();
			i != allDisplayObjects.end();
			i++)
		{

			if ((*i)->getRenderLayer() == j)
			{
				(*i)->draw(glm::mat4(1.0f));
			}
		}
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

void game::event_keyPress(unsigned char key, int x, int y)
{
	((player_object*)player)->event_keyPress(key, true);
#ifdef DEBUG_KEY_PRESS
	printf("KeyPress: '%c' Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", key, x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
#endif
}

void game::event_keyPressUP(unsigned char key, int x, int y)
{
	((player_object*)player)->event_keyPress(key, false);
#ifdef DEBUG_KEY_PRESS
		printf("KeyPress: '%c' Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", key, x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
#endif
}

void game::event_specialkey(int key, int x, int y)
{
	((player_object*)player)->event_SpeckeyPress(key, true);
#ifdef DEBUG_KEY_PRESS
	printf("SpecKeyDN: '%i' Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", key, x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
#endif
}

void game::event_specialkeyUP(int key, int x, int y)
{
	((player_object*)player)->event_SpeckeyPress(key, false);
#ifdef DEBUG_KEY_PRESS
	printf("SpecKeyUP: '%i' Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", key, x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
#endif
}

bool game::recive_message(game_msg newMsg)
{
	display_object* new_obj = nullptr;			//The parent node used for passing the object back to the caller
	image_object* new_Img_obj = nullptr;		//Contains all static image objects, The GUI and similer
	Dynamic_image_obj* new_Dyn_obj = nullptr;	//Contains all dynamic image objects, Ships and games specific onjects
	text_object* new_Txt_obj = nullptr;			//Contains all the textual content on the screen
	player_object* new_Ply_obj = nullptr;

	Create_object* cre_msg = nullptr;
	
	glm::vec2 targetDirection;
	switch (newMsg.msg_type)
	{
	case CREATE_OBJECT:
		cre_msg = &newMsg.msg_contents.create_obj;
		new_obj = Factory::create_object(cre_msg->newType);
		switch (cre_msg->action)
		{
		case NO_ACTION:
			new_obj->setLocation(cre_msg->spawnLocation);
			break;
		case DUMB_TARGET:
			((Dynamic_image_obj*)new_obj)->setLocation(cre_msg->spawnLocation);
			((Dynamic_image_obj*)new_obj)->setSpeed(cre_msg->speed);
			break;
		case TARGET_PLAYER:
			((Dynamic_image_obj*)new_obj)->setLocation(cre_msg->spawnLocation);
			//Target Players Current Location
			targetDirection = cre_msg->spawnLocation - (player->getLocation() + (player->getScale() / 2.0f));
			((Dynamic_image_obj*)new_obj)->setSpeed(glm::normalize(targetDirection)* cre_msg->speed.y) ;
			break;
		default:
			break;
		}
		//Add the new object to the stack
		allDisplayObjects.push_back(new_obj);
		break;
	case UPDATE_SCORE:

		break;
	default:
		break;
	}


	return true;
}

void game::init_glut()
{
	//gets the Desktop resolution size for the current hardware
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	initCOM();
	glutInit(&argc, argv);

	glutInitContextVersion(3, 1);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);


	glutInitWindowSize((int)screenSize.x, (int)screenSize.y);
	glutInitWindowPosition(desktop.right, 0);
	glutCreateWindow("Teen Week Interactive Game");

	if (fullscreen)
		glutFullScreenToggle();

	// display callback
	glutDisplayFunc(game::display);
	glutMouseFunc(game::event_mouseClick);
	glutPassiveMotionFunc(game::event_mouseMove);
	glutKeyboardFunc(game::event_keyPress);
	glutKeyboardUpFunc(game::event_keyPressUP);
	glutSpecialFunc(game::event_specialkey);
	glutSpecialUpFunc(game::event_specialkeyUP);


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

void game::addScore(int score)
{
	if (game::score + score < 0)
		game::score = 0;
	else
		game::score += score;
}
