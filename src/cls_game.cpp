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
#include "boss_object.h"

using namespace std;

GLuint game::default_shader = 0;

//clock_t						game::last = 0;
std::list<display_object*>	game::allDisplayObjects;	//Contains all object to be displayed to the screen
glm::vec2					game::screenSize;			//Contains the Size of the screen
bool						game::fullscreen;			//is the game fullscreen (default false)
display_object*				game::player = nullptr;
int							game::score = 0;
bool						game::start = true;
int							game::startscreen = 1;
bool						game::displayed = false;

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
	allDisplayObjects.push_back(Factory::create_object(Factory::GAME_UI));
	allDisplayObjects.push_back(Factory::create_object(Factory::INFO_TEXT));
	allDisplayObjects.push_back(Factory::create_object(Factory::QUESTION_TEXT));
	allDisplayObjects.push_back(Factory::create_object(Factory::ANSWER_TEXT));

	//display this after 20 seconds of finishing information 1
	//boss 1
		//question 1

		showText(TEXT_QUESTION, REPLACE, "What is an example of a common VARIABLE?");
		showText(TEXT_QUESTION, APPEND, "");
		showText(TEXT_QUESTION, APPEND, "Remember to look at the INFORMATION SCREEN below");
		showText(TEXT_QUESTION, APPEND, "and ANSWERS to the right!");

	//boss 2
		//question 1

		showText(TEXT_QUESTION, REPLACE, "What is the process of repeating sections of a");
		showText(TEXT_QUESTION, APPEND, "program to achieve a particular target or goal?");
		showText(TEXT_QUESTION, APPEND, "");
		showText(TEXT_QUESTION, APPEND, "Remember to look at the INFORMATION SCREEN below");
		showText(TEXT_QUESTION, APPEND, "and ANSWERS to the right!");

		//question 2

		showText(TEXT_QUESTION, REPLACE, "What is an algorithm?");

	//boss 3
		//question 1

		showText(TEXT_QUESTION, REPLACE, "What is a set of rules about how to use a particular");
		showText(TEXT_QUESTION, APPEND, "language?");
		showText(TEXT_QUESTION, APPEND, "");
		showText(TEXT_QUESTION, APPEND, "Remember to look at the INFORMATION SCREEN below");
		showText(TEXT_QUESTION, APPEND, "and ANSWERS to the right!");

		//question 2

		showText(TEXT_QUESTION, REPLACE, "What is a single action in a computer program?");

		//question 3

		showText(TEXT_QUESTION, REPLACE, "What is a value called when used within a Statement?");

	//boss 4
		//question 1

		showText(TEXT_QUESTION, REPLACE, "What is one of the most important processes when");
		showText(TEXT_QUESTION, APPEND, "creating new software?");
		showText(TEXT_QUESTION, APPEND, "");
		showText(TEXT_QUESTION, APPEND, "Remember to look at the INFORMATION SCREEN below");
		showText(TEXT_QUESTION, APPEND, "and ANSWERS to the right!");

		//question 2

		showText(TEXT_QUESTION, REPLACE, "What is used to explain the function of different sections of code?");

		//question 3

		showText(TEXT_QUESTION, REPLACE, "What system is used to track changes in the development");
		showText(TEXT_QUESTION, APPEND, "of your software?");

		//question 4

		showText(TEXT_QUESTION, REPLACE, "What is the process of working through the program");
		showText(TEXT_QUESTION, APPEND, "in a systematic way to eliminate any flaws or glitches?");

	//boss 1
		//information 1

		showText(TEXT_INFO, REPLACE, "The Mothership approaches!");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "To destroy the Mothership, we'll need to disable");
		showText(TEXT_INFO, APPEND, "its defences.");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "To do this, you'll need to select the correct ANSWER");
		showText(TEXT_INFO, APPEND, "to the QUESTION displayed above.");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "Shoot at either the LEFT or RIGHT side of the Mothership");
		showText(TEXT_INFO, APPEND, "to answer the question.");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "Here comes the first question now, look up!");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "Press SPACE to continue.");

		showText(TEXT_INFO, REPLACE, "VARIABLES could be used to store the score in a game,");
		showText(TEXT_INFO, APPEND, "the number of cars in a car park or the cost of items");
		showText(TEXT_INFO, APPEND, "on a till.");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "They work in a similar way to algebra, where a letter");
		showText(TEXT_INFO, APPEND, "in your code can stand for a number.");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "Check the ANSWER screen to the right for examples of");
		showText(TEXT_INFO, APPEND, "common VARIABLES!");

	//boss 2
		//information 1

		showText(TEXT_INFO, REPLACE, "Computer programs can use different types of loops.");
		showText(TEXT_INFO, APPEND, "");
		showText(TEXT_INFO, APPEND, "Infinite - ITERATES forever");
		showText(TEXT_INFO, APPEND, "Count-controlled - ITERATES a set amount of times");
		showText(TEXT_INFO, APPEND, "Condition-controlled - ITERATES until something happens");

		//information 2

		showText(TEXT_INFO, REPLACE, "Algorithms are sets of step - by - step instructions");
		showText(TEXT_INFO, APPEND, "for the computer to follow. They are at the heart of all");
		showText(TEXT_INFO, APPEND, "computer programs.");

		//boss 3
			//information 1

			showText(TEXT_INFO, REPLACE, "In the same way that English has rules, so do");
			showText(TEXT_INFO, APPEND, "programming languages.");
			showText(TEXT_INFO, APPEND, "For example, the SYNTAX for Python 'print' is always");
			showText(TEXT_INFO, APPEND, "typed in lower case and then followed by an argument.");

			//information 2

			showText(TEXT_INFO, REPLACE, "In a recipe for making a sandwich, a STATEMENT could be");
			showText(TEXT_INFO, APPEND, "written as 'place bread down' or 'spread butter'.");
			showText(TEXT_INFO, APPEND, "A simple statement in a computer program could be this one,");
			showText(TEXT_INFO, APPEND, "written in Python :");
			showText(TEXT_INFO, APPEND, "");
			showText(TEXT_INFO, APPEND, "print(\"Hello World\")");

			//information 3

			showText(TEXT_INFO, REPLACE, "EXPRESSIONS are used within statements when working with");
			showText(TEXT_INFO, APPEND, "values.");
			showText(TEXT_INFO, APPEND, "");
			showText(TEXT_INFO, APPEND, "For example, 2 + 2 is an expression that returns the value of 4.");
			showText(TEXT_INFO, APPEND, "In a computer program, an expression to work out your age might");
			showText(TEXT_INFO, APPEND, "look like this:");
			showText(TEXT_INFO, APPEND, "");
			showText(TEXT_INFO, APPEND, "AgeNextYear = CurrentAge + 1");

		//boss 4
			//information 1

			showText(TEXT_INFO, REPLACE, "Without TESTING a new system thoroughly it can fail, resulting");
			showText(TEXT_INFO, APPEND, "in serious consequences for the developers and end users.");
			showText(TEXT_INFO, APPEND, "");
			showText(TEXT_INFO, APPEND, "It can be difficult to test every possible outcome and");
			showText(TEXT_INFO, APPEND, "even the most rigorous of testing may not catch every error");
			showText(TEXT_INFO, APPEND, "in the program.");
			 
			//information 2

			showText(TEXT_INFO, REPLACE, "If programmers leave helpful COMMENTS in the code, it makes");
			showText(TEXT_INFO, APPEND, "it easier for others to understand what purpose each section");
			showText(TEXT_INFO, APPEND, "of code performs.");

			//information 3

			showText(TEXT_INFO, REPLACE, "It is really important to keep detailed records of all the");
			showText(TEXT_INFO, APPEND, "tests that have been carried out as well as any changes that");
			showText(TEXT_INFO, APPEND, "have been carried out as well as any changes that have been made");
			showText(TEXT_INFO, APPEND, "after the tests.");
			showText(TEXT_INFO, APPEND, "");
			showText(TEXT_INFO, APPEND, "Sometimes errors can be found in the software later on.");
			showText(TEXT_INFO, APPEND, "The tracking that VERSION CONTROL provides enables developers");
			showText(TEXT_INFO, APPEND, "to go back and see what changes were made.");

			//information 4

			showText(TEXT_INFO, REPLACE, "When a computer program does not do what you expect, it is likely");
			showText(TEXT_INFO, APPEND, "that the algorithm that you designed is flawed.Go back to your");
			showText(TEXT_INFO, APPEND, "algorithm and separate it into parts and see how this relates to");
			showText(TEXT_INFO, APPEND, "the program that you have created.");
			showText(TEXT_INFO, APPEND, "");
			showText(TEXT_INFO, APPEND, "Being able to see what is happening inside a program is very useful");
			showText(TEXT_INFO, APPEND, "when DEBUGGING.");				

	//possible answers

	//boss 1
		//possible answers

		showText(TEXT_ANSWER, REPLACE, "int");
		showText(TEXT_ANSWER, APPEND, "string");
		showText(TEXT_ANSWER, APPEND, "char");
		showText(TEXT_ANSWER, APPEND, "double");

	//boss 2
		//possible answers

		showText(TEXT_ANSWER, REPLACE, "Cycles");
		showText(TEXT_ANSWER, APPEND, "Turns");
		showText(TEXT_ANSWER, APPEND, "Iterates");
		showText(TEXT_ANSWER, APPEND, "Instructions");
		showText(TEXT_ANSWER, APPEND, "Devices");

	//boss 3
		//possible answers

		showText(TEXT_ANSWER, REPLACE, "Syntax");
		showText(TEXT_ANSWER, APPEND, "Statements");
		showText(TEXT_ANSWER, APPEND, "Expressions");
		showText(TEXT_ANSWER, APPEND, "Diversions");
		showText(TEXT_ANSWER, APPEND, "Semaphores");
		showText(TEXT_ANSWER, APPEND, "Types");

	//boss 4
		//possible answers

		showText(TEXT_ANSWER, REPLACE, "Zipped");
		showText(TEXT_ANSWER, APPEND, "Version Control");
		showText(TEXT_ANSWER, APPEND, "Mathmatics");
		showText(TEXT_ANSWER, APPEND, "Comments");
		showText(TEXT_ANSWER, APPEND, "Debugging");
		showText(TEXT_ANSWER, APPEND, "Development");
		showText(TEXT_ANSWER, APPEND, "Testing");

	static text_object* Scoretxt = (text_object*)Factory::create_object(Factory::SCORE_TEXT);
	allDisplayObjects.push_back(Scoretxt);

	static int level = 0;

	static int level_ships[MAX_LEVELS][Factory::NUMBER_OF_ENEMIES];

	for (unsigned int i = 0; i < MAX_LEVELS; i++)
	{
		for (unsigned int j = 0; j < Factory::NUMBER_OF_ENEMIES; j++)
		{
			level_ships[i][j] = 0;
		}
	}

	srand(1);

 	generateLevels(level_ships);

	bool quit = false;

	while (!quit)
	{
	
		if (!start)
		{

			if ((level + 1) % 10 == 0)
			{
				//Special cases for bosses
				switch (level)
				{
				case 9:

					break;
				case 19:

					break;
				case 29:

					break;
				case 39:

					break;
				}

			}

			//Handeling for all waves
			static int spawnrate = 0;
			int allcount = 0;
			int alivecount = 0;
			int shipcount = 0;


			for (unsigned int j = 0; j < Factory::NUMBER_OF_ENEMIES; j++)
			{
				allcount += level_ships[level][j];
			}
       			for (unsigned int j = Factory::ENEMY_ONE; j <= Factory::ENEMY_FIVE; j++)
			{
				shipcount += level_ships[level][j];
			}

			for (list<display_object*>::iterator i = allDisplayObjects.begin();
				i != allDisplayObjects.end();
				i++)
			{
				if (((Dynamic_image_obj*)(*i))->getObjectType() == Dynamic_image_obj::SHIP)
					alivecount++;
			}


			if (allcount + alivecount == 0)
			{
				level++;
				if (level == 9)
				{
					startscreen = level;
					displayed = false;
					start = true;
				}

				showText(TEXT_ANSWER, REPLACE, "Level: " + std::to_string(level+1));
			}

			if (level >= MAX_LEVELS)
			{
				quit = true;
				break;
			}


			if (shipcount > 0 && spawnrate++ > (ENEMY_SHIP_SPAWN_BASE - (ENEMY_SHIP_SPAWN_PER_LEVEL_FACTOR * level)) + (rand() % ENEMY_SHIP_SPAWN_RANDOMNESS))
			{
				spawnrate = 0;
				unsigned int ChosenShip = rand() % Factory::ENEMY_FIVE+1 ;
				while (level_ships[level][ChosenShip] == 0) {
					ChosenShip = rand() % (Factory::ENEMY_FIVE+1);
				}
				level_ships[level][ChosenShip]--;

				Dynamic_image_obj* temp = (Dynamic_image_obj*)Factory::create_object((Factory::Types)ChosenShip);

				temp->setLocation(glm::vec2(GAME_SPACE_LEFT + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (GAME_SPACE_RIGHT - GAME_SPACE_LEFT))), GAME_SPACE_TOP));
				temp->setSpeed(glm::vec2(0.0f, -(ENEMY_BASE_SHIP_SPEED + (ENEMY_SHIP_SPEED_LEVEL_FACTOR * float(level)))));
				allDisplayObjects.push_back(temp);

			}
			else if (shipcount == 0 && alivecount == 0 && allcount > 0 && spawnrate++ > 120)
			{
				unsigned int ChosenShip = (rand() % (Factory::NUMBER_OF_ENEMIES - Factory::ENEMY_FIVE )) + Factory::ENEMY_FIVE;
				while (level_ships[level][ChosenShip] == 0) {
					ChosenShip = (rand() % (Factory::NUMBER_OF_ENEMIES - Factory::ENEMY_FIVE)) + Factory::ENEMY_FIVE;
				}
				level_ships[level][ChosenShip]--;
				Dynamic_image_obj* temp = (Dynamic_image_obj*)Factory::create_object((Factory::Types)ChosenShip);

				temp->setLocation(glm::vec2(GAME_SPACE_LEFT + ((GAME_SPACE_RIGHT - GAME_SPACE_LEFT)/2) - (temp->getScale().x /2), GAME_SPACE_TOP));
				temp->setSpeed(glm::vec2(0.0f, -(ENEMY_BASE_SHIP_SPEED )));
				allDisplayObjects.push_back(temp);
				spawnrate = 0;
			}

		}
		else
		{				
			switch (startscreen)
			{
			case 1:
				if (!displayed)
				{
					showText(TEXT_INFO, REPLACE, "Welcome programming cadet!");
					showText(TEXT_INFO, APPEND, "You have been tasked with defending the Galaxy.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "This screen is the INFORMATION SCREEN.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "This will display helpful tips and programming");
					showText(TEXT_INFO, APPEND, "advice to help you battle the upcoming enemies.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Press SPACE to continue.");
					displayed = true;
				}
				break;
			case 2:

				if (!displayed)
				{
					showText(TEXT_INFO, REPLACE, "Above here is the QUESTION SCREEN.");
					showText(TEXT_INFO, APPEND, "When you fight against the Mothership you'll");
					showText(TEXT_INFO, APPEND, "have to disable their shields in order to attack.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "To do this you'll need to answer programming");
					showText(TEXT_INFO, APPEND, "and computer science related questions.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "To the right is your GENERATED ANSWERS.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "As you defeat enemy ships, you'll begin");
					showText(TEXT_INFO, APPEND, "collecting important enemy intel for");
					showText(TEXT_INFO, APPEND, "when you fight the Mothership.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Press SPACE to continue.");
					displayed = true;
				}
				break;
			case 3:
				if (!displayed)
				{
					showText(TEXT_INFO, REPLACE, "Ahead of you is the Evil Empire.");
					showText(TEXT_INFO, APPEND, "They threaten all that is good in the world.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Dodge them and their attacks!  We'll keep score");
					showText(TEXT_INFO, APPEND, "of how many you destroy.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "After 9 waves you'll fight the Mothership.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "We'll give you more information here when you get");
					showText(TEXT_INFO, APPEND, "there!");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Press SPACE to continue.");
					displayed = true;
				}
			case 4:
				if (!displayed)
				{
					showText(TEXT_INFO, REPLACE, "Press SPACE to begin fighting.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Remember: Use LEFT and RIGHT to move. ");
					showText(TEXT_INFO, APPEND, "SPACE to fire.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Good luck!");
					displayed = true;
				}
			case 9:
				if (!displayed)
				{
					showText(TEXT_INFO, REPLACE, "The Mothership approaches!");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "To destroy the Mothership, we'll need to disable");
					showText(TEXT_INFO, APPEND, "its defences.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "To do this, you'll need to select the correct ANSWER");
					showText(TEXT_INFO, APPEND, "to the QUESTION displayed above.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Shoot at either the LEFT or RIGHT side of the Mothership");
					showText(TEXT_INFO, APPEND, "to answer the question.");
					showText(TEXT_INFO, APPEND, "");
					showText(TEXT_INFO, APPEND, "Here comes the first question now, look up!");
					showText(TEXT_INFO, APPEND, "Press SPACE");
					displayed = true;
				}
		 
			default:
				break;
			}
		}

		Scoretxt->clearTextWOreset();
		Scoretxt->addText(std::to_string(score));
		

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

		//printf("Array Objs: %i\n", allDisplayObjects.size());

		for (list<display_object*>::iterator i = allDisplayObjects.begin();
			i != allDisplayObjects.end();
			i++)
		{
			if ((*i)->getType() == display_object::GAME_OBJECT ||
				(*i)->getType() == display_object::PLAYER_OBJECT ||
				(*i)->getType() == display_object::BOSS_OBJECT ||
				(*i)->getRenderLayer() == display_object::BACKGROUND)
			{
				((Dynamic_image_obj*)(*i))->move((float)elapsedTime/1000000);
			}
		}

		collision();

	}
	std::printf("Congratulations your score is %i \nPlease call the Attendant to record your score...", game::score);

	std::system("PAUSE");
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
				 (*i)->getType() == display_object::GAME_OBJECT) ||
				 ((*j)->getType() == display_object::BOSS_OBJECT &&
				 (*i)->getType() == display_object::GAME_OBJECT) ||
				 ((*j)->getType() == display_object::GAME_OBJECT &&
				 (*i)->getType() == display_object::BOSS_OBJECT))
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
							std::printf("oooo player done bad\n");
							bullet->setDestroyed();
							addScore(-100);

						}
					}
				}
				if (player && ship)
				{
 					if (isColliding(player, ship))
					{
						std::printf("oooo player done bad\n");
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
							std::printf("Player gets points yey\n");
							bullet->setDestroyed();
							if (ship->getType() == Dynamic_image_obj::BOSS_OBJECT)
							{
								if (!((boss_object*)ship)->bossHit(bullet->getLocation()))
									addScore(-100);
								
							}
							else
							{
								ship->setDestroyed();
								addScore(100);
							}
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
		if ((((Dynamic_image_obj*)(*i))->getType() == display_object::GAME_OBJECT || 
			((Dynamic_image_obj*)(*i))->getType() == display_object::BOSS_OBJECT) &&
			((*i)->getLocation().x < GAME_SPACE_LEFT ||
			(*i)->getLocation().x + ((Dynamic_image_obj*)(*i))->getScale().x >  GAME_SPACE_RIGHT ||
			(*i)->getLocation().y + ((Dynamic_image_obj*)(*i))->getScale().y < GAME_SPACE_BOTTOM ||
			(*i)->getLocation().y >  GAME_SPACE_TOP + 0.5f ||
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
	if (start)
	{
		if (key == ' ')
		{
			if (startscreen == 4 || startscreen == 9)
				start = false;
			else
			{
				startscreen++;
				displayed = false;
			}
		}
	}
	else
	{
		((player_object*)player)->event_keyPress(key, true);
	}

#ifdef DEBUG_KEY_PRESS
	printf("KeyPress: '%c' Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", key, x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
#endif
}

void game::event_keyPressUP(unsigned char key, int x, int y)
{
	if (!start)
	{
		((player_object*)player)->event_keyPress(key, false);
	}
#ifdef DEBUG_KEY_PRESS
		printf("KeyPress: '%c' Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", key, x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
#endif
}

void game::event_specialkey(int key, int x, int y)
{
	if (!start)
	{
		((player_object*)player)->event_SpeckeyPress(key, true);
	}
#ifdef DEBUG_KEY_PRESS
	printf("SpecKeyDN: '%i' Loc {%4i,%4i}\t {%7.4f,%7.4f}\n", key, x, y, ((2.0f / screenSize.x) * x) - 1.0f, -(((2.0f / screenSize.y) * y) - 1.0f));
#endif
}

void game::event_specialkeyUP(int key, int x, int y)
{
	if (!start)
	{
		((player_object*)player)->event_SpeckeyPress(key, false);
	}
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
		((Dynamic_image_obj*)new_obj)->setSpeed(cre_msg->speed*(cre_msg->spawnScale.x * 5));
		if (cre_msg->newType == Factory::EXPLOSION)
		{
			((Dynamic_image_obj*)new_obj)->setScale(cre_msg->spawnScale);
		}

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
			targetDirection = cre_msg->spawnLocation - (player->getLocation() + glm::vec2((player->getScale().x / 2.0f),0.0f));
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
#ifdef _DEBUG
	//gets the Desktop resolution size for the current hardware
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
#endif

	initCOM();
	glutInit(&argc, argv);

	glutInitContextVersion(3, 1);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize((int)screenSize.x, (int)screenSize.y);
#ifdef _DEBUG
	glutInitWindowPosition(desktop.right, 0);
#else
	glutInitWindowPosition(0, 0);
#endif

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
	printf("Score Change %i\n", score);
	if (game::score + score < 0)
		game::score = 0;
	else
		game::score += score;
}

void game::showText(text_location loc, text_mod_type type, std::string text)
{
	//One time run Create the objects, 
	static text_object* answer_Pane = nullptr;
	static text_object* info_Pane = nullptr;
	static text_object* question_Pane = nullptr;

	text_object* current_ptr = nullptr;

	if (!answer_Pane)
	{
		answer_Pane = dynamic_cast<text_object*>(Factory::create_object(Factory::ANSWER_TEXT));
		info_Pane = dynamic_cast<text_object*>(Factory::create_object(Factory::INFO_TEXT));
		question_Pane = dynamic_cast<text_object*>(Factory::create_object(Factory::QUESTION_TEXT));
		allDisplayObjects.push_back(answer_Pane);
		allDisplayObjects.push_back(info_Pane);
		allDisplayObjects.push_back(question_Pane);
	}

	switch (loc)
	{
	case game::TEXT_QUESTION:
		current_ptr = question_Pane;
		break;
	case game::TEXT_INFO:
		current_ptr = info_Pane;
		break;
	case game::TEXT_ANSWER:
		current_ptr = answer_Pane;
		break;
	default:
		break;
	}
	switch (type)
	{
	case game::APPEND:
		current_ptr->addText(text);
		break;
	case game::REPLACE:
		current_ptr->clearText();
		current_ptr->addText(text);
		break;
	default:
		break;
	}
}

void game::generateLevels(int levels[MAX_LEVELS][Factory::NUMBER_OF_ENEMIES])
{
	//All levels are initilized to 0, so only need to set the ones that have non 0 numbers

	//  levels[MAX_LEVELS][Factory::<SHIPTYPE>]
	/*levels[0][Factory::ENEMY_ONE] = 2;

	levels[1][Factory::ENEMY_ONE] = 3;

	levels[2][Factory::ENEMY_ONE] = 4;

	levels[3][Factory::ENEMY_ONE] = 5;

	levels[4][Factory::ENEMY_ONE] = 5;

	levels[5][Factory::ENEMY_ONE] = 5;
	levels[5][Factory::ENEMY_TWO] = 1;

	levels[6][Factory::ENEMY_ONE] = 5;
	levels[6][Factory::ENEMY_TWO] = 2;

	levels[7][Factory::ENEMY_ONE] = 5;
	levels[7][Factory::ENEMY_TWO] = 3;

	levels[8][Factory::ENEMY_ONE] = 5;
	levels[8][Factory::ENEMY_TWO] = 4;*/

	levels[9][Factory::BOSS_ONE] = 1;

	levels[10][Factory::ENEMY_ONE] = 5;
	levels[10][Factory::ENEMY_TWO] = 5;

	levels[11][Factory::ENEMY_ONE] = 2;
	levels[11][Factory::ENEMY_TWO] = 2;
	levels[11][Factory::ENEMY_THREE] = 1;

	levels[12][Factory::ENEMY_ONE] = 3;
	levels[12][Factory::ENEMY_TWO] = 2;
	levels[12][Factory::ENEMY_THREE] = 1;

	levels[13][Factory::ENEMY_ONE] = 2;
	levels[13][Factory::ENEMY_TWO] = 3;
	levels[13][Factory::ENEMY_THREE] = 1;

	levels[14][Factory::ENEMY_THREE] = 10;

	levels[15][Factory::ENEMY_ONE] = 2;
	levels[15][Factory::ENEMY_TWO] = 2;
	levels[15][Factory::ENEMY_THREE] = 2;

	levels[16][Factory::ENEMY_ONE] = 2;
	levels[16][Factory::ENEMY_TWO] = 2;
	levels[16][Factory::ENEMY_THREE] = 2;

	levels[17][Factory::ENEMY_ONE] = 3;
	levels[17][Factory::ENEMY_TWO] = 2;
	levels[17][Factory::ENEMY_THREE] = 2;

	levels[18][Factory::ENEMY_ONE] = 3;
	levels[18][Factory::ENEMY_TWO] = 3;
	levels[18][Factory::ENEMY_THREE] = 2;

	levels[19][Factory::BOSS_TWO] = 1;

	levels[20][Factory::ENEMY_ONE] = 5;
	levels[20][Factory::ENEMY_TWO] = 5;

	levels[21][Factory::ENEMY_ONE] = 2;
	levels[21][Factory::ENEMY_TWO] = 2;
	levels[21][Factory::ENEMY_THREE] = 1;
	levels[21][Factory::ENEMY_FOUR] = 1;

	levels[22][Factory::ENEMY_ONE] = 5;
	levels[22][Factory::ENEMY_TWO] = 2;
	levels[22][Factory::ENEMY_THREE] = 1;
	levels[22][Factory::ENEMY_FOUR] = 2;

	levels[23][Factory::ENEMY_ONE] = 3;
	levels[23][Factory::ENEMY_TWO] = 3;
	levels[23][Factory::ENEMY_THREE] = 2;
	levels[23][Factory::ENEMY_FOUR] = 3;

	levels[24][Factory::ENEMY_THREE] = 5;
	levels[24][Factory::ENEMY_FOUR] = 5;

	levels[25][Factory::ENEMY_ONE] = 2;
	levels[25][Factory::ENEMY_TWO] = 2;
	levels[25][Factory::ENEMY_THREE] = 2;
	levels[25][Factory::ENEMY_FOUR] = 2;

	levels[26][Factory::ENEMY_ONE] = 2;
	levels[26][Factory::ENEMY_TWO] = 2;
	levels[26][Factory::ENEMY_THREE] = 2;
	levels[26][Factory::ENEMY_FOUR] = 4;

	levels[27][Factory::ENEMY_ONE] = 3;
	levels[27][Factory::ENEMY_TWO] = 2;
	levels[27][Factory::ENEMY_THREE] = 2;
	levels[27][Factory::ENEMY_FOUR] = 4;

	levels[28][Factory::ENEMY_ONE] = 3;
	levels[28][Factory::ENEMY_TWO] = 3;
	levels[28][Factory::ENEMY_THREE] = 2;
	levels[28][Factory::ENEMY_FOUR] = 5;

	levels[29][Factory::BOSS_THREE] = 1;

	levels[30][Factory::ENEMY_ONE] = 5;
	levels[30][Factory::ENEMY_TWO] = 5;
	levels[30][Factory::ENEMY_THREE] = 5;

	levels[31][Factory::ENEMY_ONE] = 2;
	levels[31][Factory::ENEMY_TWO] = 2;
	levels[31][Factory::ENEMY_THREE] = 1;
	levels[31][Factory::ENEMY_FOUR] = 1;
	levels[31][Factory::ENEMY_FIVE] = 1;

	levels[32][Factory::ENEMY_ONE] = 5;
	levels[32][Factory::ENEMY_TWO] = 2;
	levels[32][Factory::ENEMY_THREE] = 1;
	levels[32][Factory::ENEMY_FOUR] = 2;
	levels[32][Factory::ENEMY_FIVE] = 2;

	levels[33][Factory::ENEMY_ONE] = 3;
	levels[33][Factory::ENEMY_TWO] = 3;
	levels[33][Factory::ENEMY_THREE] = 2;
	levels[33][Factory::ENEMY_FOUR] = 3;
	levels[33][Factory::ENEMY_FIVE] = 3;

	levels[34][Factory::ENEMY_THREE] = 5;
	levels[34][Factory::ENEMY_FOUR] = 5;
	levels[34][Factory::ENEMY_FIVE] = 5;

	levels[35][Factory::ENEMY_ONE] = 2;
	levels[35][Factory::ENEMY_TWO] = 2;
	levels[35][Factory::ENEMY_THREE] = 2;
	levels[35][Factory::ENEMY_FOUR] = 3;
	levels[35][Factory::ENEMY_FIVE] = 5;

	levels[36][Factory::ENEMY_ONE] = 2;
	levels[36][Factory::ENEMY_TWO] = 3;
	levels[36][Factory::ENEMY_THREE] = 2;
	levels[36][Factory::ENEMY_FOUR] = 4;
	levels[36][Factory::ENEMY_FIVE] = 5;

	levels[37][Factory::ENEMY_ONE] = 3;
	levels[37][Factory::ENEMY_TWO] = 4;
	levels[37][Factory::ENEMY_THREE] = 2;
	levels[37][Factory::ENEMY_FOUR] = 4;
	levels[37][Factory::ENEMY_FIVE] = 5;

	levels[38][Factory::ENEMY_ONE] = 5;
	levels[38][Factory::ENEMY_TWO] = 5;
	levels[38][Factory::ENEMY_THREE] = 5;
	levels[38][Factory::ENEMY_FOUR] = 5;
	levels[38][Factory::ENEMY_FIVE] = 5;

	levels[39][Factory::BOSS_FOUR] = 1;
}
