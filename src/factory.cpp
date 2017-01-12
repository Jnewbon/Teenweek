#include "factory.h"
#include "texture_loader.h"
#include "cls_game.h"
#include "player_object.h"
#include <memory>
#include "dynamic_obj_action.h"
#include "action_shoot.h"
#include "explosion_object.h"
#include "boss_object.h"

using namespace std;
using namespace glm;

display_object * Factory::create_object(Types obj_type)
{
	display_object* new_obj = nullptr;			//The parent node used for passing the object back to the caller
	image_object* new_Img_obj = nullptr;		//Contains all static image objects, The GUI and similer
	Dynamic_image_obj* new_Dyn_obj = nullptr;	//Contains all dynamic image objects, Ships and games specific onjects
	boss_object* new_Bos_obj = nullptr;	//Contains all dynamic image objects, Ships and games specific onjects
	text_object* new_Txt_obj = nullptr;			//Contains all the textual content on the screen
	player_object* new_Ply_obj = nullptr;		//Contains all the textual content on the screen
	explosion_object* new_exp_obj = nullptr;


	question newQuestion;

	//Used for Text objects
	vector<std::string> text;

	switch (obj_type)
	{
	case Factory::PLAYER_SHIP:
		//Create the specific type required
		new_Ply_obj = new player_object();

		//Location, Just set it to 0
		new_Ply_obj->setLocation(0.1638f, -0.6467f);
		
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Ply_obj->setScale(0.1f, 0.1f);
		new_Ply_obj->setinertia(vec2(PLAYER_SHIP_ACCELARATION));
		new_Ply_obj->setMaxSpeed(vec2(PLAYER_SHIP_MAX_SPEED));


		//The texture that will be used by the object
		new_Ply_obj->set_Texture(loadTexture(L"resources\\textures\\player\\player.png"));

		//Texture is a square so tell the object that.
		new_Ply_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Ply_obj->setShader(game::default_shader);

		new_Ply_obj->setAction(Factory::create_object(WPN_PLAYER_BASIC, new_Ply_obj));
		
		new_Ply_obj->setObjectType(Dynamic_image_obj::PLAYER);

		break;
	case Factory::ENEMY_ONE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.1638f, 0.85f);
		
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setSpeed(vec2(0.0f, -0.3f));

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		new_Dyn_obj->setAction(create_object(WPN_ENEMY_BASIC, new_Dyn_obj));

		break;
	case Factory::ENEMY_TWO:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 1.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_two.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);
		new_Dyn_obj->setSpeed(vec2(0.0f, -0.35f));

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		new_Dyn_obj->setAction(create_object(WPN_ENEMY_BASIC, new_Dyn_obj));

		break;
	case Factory::ENEMY_THREE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_three.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		new_Dyn_obj->setAction(create_object(WPN_ENEMY_BASIC, new_Dyn_obj));

		break;
	case Factory::ENEMY_FOUR:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_four.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		new_Dyn_obj->setAction(create_object(WPN_ENEMY_BASIC, new_Dyn_obj));

		break;
	case Factory::ENEMY_FIVE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_five.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		new_Dyn_obj->setAction(create_object(WPN_ENEMY_BASIC, new_Dyn_obj));

		break;
	case Factory::BOSS_ONE:
		//Create the specific type required
		new_Bos_obj = new boss_object();

		//Location, Just set it to 0
		new_Bos_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Bos_obj->setScale(0.2f, 0.65f);

		//The texture that will be used by the object
		new_Bos_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_one.png"));

		//Texture is a square so tell the object that.
		new_Bos_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Bos_obj->setShader(game::default_shader);

		new_Bos_obj->setObjectType(Dynamic_image_obj::SHIP);
		//new_Bos_obj->setAction(create_object(WPN_ENEMY_DIRECTED, new_Dyn_obj));


		newQuestion.Question.push_back("What is an example of a common VARIABLE?");
		newQuestion.Question.push_back("");
		newQuestion.Question.push_back("Remember to look at the INFORMATION SCREEN below");
		newQuestion.Question.push_back("and ANSWERS to the right!");

		newQuestion.CorrectAnswer = "int";

		newQuestion.WrongAnswers.push_back("vec2");
		newQuestion.WrongAnswers.push_back("matrix");
		newQuestion.WrongAnswers.push_back("chrono");


		newQuestion.Info.push_back("VARIABLES could be used to store the score in ");
		newQuestion.Info.push_back("a game, the number of cars in a car park or the ");
		newQuestion.Info.push_back("cost of items on a till.");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("They work in a similar way to algebra, where a ");
		newQuestion.Info.push_back("letter in your code can stand for a number.");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("Check the ANSWER screen to the right for examples ");
		newQuestion.Info.push_back("of common VARIABLES!");

		new_Bos_obj->addQuestion(newQuestion);
		

		break;
	case Factory::BOSS_TWO:
		//Create the specific type required
		new_Bos_obj = new boss_object();

		//Location, Just set it to 0
		new_Bos_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Bos_obj->setScale(0.4f, 0.35f);

		//The texture that will be used by the object
		new_Bos_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_two.png"));

		//Texture is a square so tell the object that.
		new_Bos_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Bos_obj->setShader(game::default_shader);

		new_Bos_obj->setObjectType(Dynamic_image_obj::SHIP);
		
		newQuestion = question();

		newQuestion.Question.push_back("What is the process of repeating sections of a");
		newQuestion.Question.push_back("program to achieve a particular target or goal?");
		newQuestion.Question.push_back("");
		newQuestion.Question.push_back("Remember to look at the INFORMATION SCREEN below");
		newQuestion.Question.push_back("and ANSWERS to the right!");

		newQuestion.CorrectAnswer = "Iterates";
		newQuestion.WrongAnswers.push_back("Cycles");
		newQuestion.WrongAnswers.push_back("Turns");
		newQuestion.WrongAnswers.push_back("Instructions");
		newQuestion.WrongAnswers.push_back("Devices");

		

		newQuestion.Info.push_back("Computer programs can use different types of loops.");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("Infinite - ITERATES forever");
		newQuestion.Info.push_back("Count-controlled - ITERATES a set amount of times");
		newQuestion.Info.push_back("Condition-controlled - ITERATES until something");
		newQuestion.Info.push_back("happens");


		new_Bos_obj->addQuestion(newQuestion);

		newQuestion = question();

		newQuestion.Question.push_back("What is an algorithm?");

		newQuestion.CorrectAnswer = "Instructions";
		newQuestion.WrongAnswers.push_back("Iterates");
		newQuestion.WrongAnswers.push_back("Cycles");
		newQuestion.WrongAnswers.push_back("Turns");;
		newQuestion.WrongAnswers.push_back("Devices");

		newQuestion.Info.push_back("Algorithms are sets of step - by - step ");
		newQuestion.Info.push_back("instructions for the computer to follow. ");
		newQuestion.Info.push_back("They are at the heart of allcomputer programs.");

		new_Bos_obj->addQuestion(newQuestion);


		break;
	case Factory::BOSS_THREE:
		//Create the specific type required
		new_Bos_obj = new boss_object();

		//Location, Just set it to 0
		new_Bos_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Bos_obj->setScale(0.5f, 0.8f);

		//The texture that will be used by the object
		new_Bos_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_three.png"));

		//Texture is a square so tell the object that.
		new_Bos_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Bos_obj->setShader(game::default_shader);

		new_Bos_obj->setObjectType(Dynamic_image_obj::SHIP);
		newQuestion = question();

		newQuestion.Question.push_back("What is a set of rules about how to use a particular");
		newQuestion.Question.push_back("language?");
		newQuestion.Question.push_back("");
		newQuestion.Question.push_back("Remember to look at the INFORMATION SCREEN below");
		newQuestion.Question.push_back("and ANSWERS to the right!");

		newQuestion.CorrectAnswer = "Syntax";
		newQuestion.WrongAnswers.push_back("Statement");
		newQuestion.WrongAnswers.push_back("Expression");
		newQuestion.WrongAnswers.push_back("Diversion");
		newQuestion.WrongAnswers.push_back("Semaphore");
		newQuestion.WrongAnswers.push_back("Type");

		newQuestion.Info.push_back("In the same way that English has rules, so do");
		newQuestion.Info.push_back("programming languages.");
		newQuestion.Info.push_back("For example, the SYNTAX for Python 'print' is ");
		newQuestion.Info.push_back("always typed in lower case and then followed by");
		newQuestion.Info.push_back("an argument.");

		new_Bos_obj->addQuestion(newQuestion);
		newQuestion = question();

		newQuestion.Question.push_back("What is a single action in a computer program?");
		newQuestion.Question.push_back("");

		newQuestion.CorrectAnswer = "Statements";
		newQuestion.WrongAnswers.push_back("Expression");
		newQuestion.WrongAnswers.push_back("Diversion");
		newQuestion.WrongAnswers.push_back("Semaphore");
		newQuestion.WrongAnswers.push_back("Type");
		newQuestion.WrongAnswers.push_back("Syntax");

		newQuestion.Info.push_back("In a recipe for making a sandwich, a STATEMENT ");
		newQuestion.Info.push_back("could be written as 'place bread down' or");
		newQuestion.Info.push_back(" 'spread butter'. A simple statement in a computer ");
		newQuestion.Info.push_back("program could be this one, written in Python :");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("print(\"Hello World\")"); 
		new_Bos_obj->addQuestion(newQuestion);
		newQuestion = question();

		newQuestion.Question.push_back("What is a value called when used within a Statement?");
		newQuestion.Question.push_back("");

		newQuestion.CorrectAnswer = "Expression";
		newQuestion.WrongAnswers.push_back("Statement");
		newQuestion.WrongAnswers.push_back("Expression");
		newQuestion.WrongAnswers.push_back("Diversion");
		newQuestion.WrongAnswers.push_back("Semaphore");
		newQuestion.WrongAnswers.push_back("Type");
		newQuestion.WrongAnswers.push_back("Syntax");

		newQuestion.Info.push_back("EXPRESSIONS are used within statements when working ");
		newQuestion.Info.push_back("with values.");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("For example, 2 + 2 is an expression that returns ");
		newQuestion.Info.push_back("the value of 4. In a computer program, an ");
		newQuestion.Info.push_back("expression to work out your age mightlook like ");
		newQuestion.Info.push_back("this:");
		newQuestion.Info.push_back("AgeNextYear = CurrentAge + 1");

		new_Bos_obj->addQuestion(newQuestion);

		break;
	case Factory::BOSS_FOUR:
		//Create the specific type required
		new_Bos_obj = new boss_object();

		//Location, Just set it to 0
		new_Bos_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Bos_obj->setScale(0.35f, 0.75f);

		//The texture that will be used by the object
		new_Bos_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_four.png"));

		//Texture is a square so tell the object that.
		new_Bos_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Bos_obj->setShader(game::default_shader);

		new_Bos_obj->setObjectType(Dynamic_image_obj::SHIP);
		newQuestion = question();

		newQuestion.Question.push_back("What is one of the most important processes when");
		newQuestion.Question.push_back("creating new software?");
		newQuestion.Question.push_back("");
		newQuestion.Question.push_back("Remember to look at the INFORMATION SCREEN below");
		newQuestion.Question.push_back("and ANSWERS to the right!");

		newQuestion.CorrectAnswer = "Testing";

		newQuestion.WrongAnswers.push_back("Zipped");
		newQuestion.WrongAnswers.push_back("Version Control");
		newQuestion.WrongAnswers.push_back("Mathmatics");
		newQuestion.WrongAnswers.push_back("Comments");
		newQuestion.WrongAnswers.push_back("Debugging");
		newQuestion.WrongAnswers.push_back("Development");

		newQuestion.Info.push_back("Without TESTING a new system thoroughly it can ");
		newQuestion.Info.push_back("fail, resulting in serious consequences for the ");
		newQuestion.Info.push_back("developers and end users.");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("It can be difficult to test every possible outcome ");
		newQuestion.Info.push_back("and even the most rigorous of testing may not ");
		newQuestion.Info.push_back("catch every error in the program.");

		new_Bos_obj->addQuestion(newQuestion);
		newQuestion = question();

		newQuestion.Question.push_back("What is used to explain the function of different");
		newQuestion.Question.push_back("sections of code?");


		newQuestion.CorrectAnswer = "Comments";

		newQuestion.WrongAnswers.push_back("Zipped");
		newQuestion.WrongAnswers.push_back("Version Control");
		newQuestion.WrongAnswers.push_back("Mathmatics");
		newQuestion.WrongAnswers.push_back("Debugging");
		newQuestion.WrongAnswers.push_back("Development");
		newQuestion.WrongAnswers.push_back("Testing");

		newQuestion.Info.push_back("If programmers leave helpful COMMENTS in the code,");
		newQuestion.Info.push_back("it makes it easier for others to understand what ");
		newQuestion.Info.push_back("purpose each section of code performs.");

		new_Bos_obj->addQuestion(newQuestion);
		newQuestion = question();

		newQuestion.Question.push_back("What system is used to track changes in the ");
		newQuestion.Question.push_back("development of your software?");

		newQuestion.CorrectAnswer = "Version Control";

		newQuestion.WrongAnswers.push_back("Zipped");
		newQuestion.WrongAnswers.push_back("Mathmatics");
		newQuestion.WrongAnswers.push_back("Comments");
		newQuestion.WrongAnswers.push_back("Debugging");
		newQuestion.WrongAnswers.push_back("Development");
		newQuestion.WrongAnswers.push_back("Testing");

		newQuestion.Info.push_back("It is really important to keep detailed records");
		newQuestion.Info.push_back(" of all the tests that have been carried out as ");
		newQuestion.Info.push_back("well as any changes that have been carried out ");
		newQuestion.Info.push_back("as well as any changes that have been made after ");
		newQuestion.Info.push_back("the tests.");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("Sometimes errors can be found in the software ");
		newQuestion.Info.push_back("later on. The tracking that VERSION CONTROL ");
		newQuestion.Info.push_back("provides enables developers to go back and see");
		newQuestion.Info.push_back("what changes were made.");

		new_Bos_obj->addQuestion(newQuestion);
		newQuestion = question();

		newQuestion.Question.push_back("What is the process of working through the program");
		newQuestion.Question.push_back("in a systematic way to eliminate any flaws or");
		newQuestion.Question.push_back("glitches?");

		newQuestion.CorrectAnswer = "Debugging";

		newQuestion.WrongAnswers.push_back("Zipped");
		newQuestion.WrongAnswers.push_back("Version Control");
		newQuestion.WrongAnswers.push_back("Mathmatics");
		newQuestion.WrongAnswers.push_back("Comments");
		newQuestion.WrongAnswers.push_back("Development");
		newQuestion.WrongAnswers.push_back("Testing");

		newQuestion.Info.push_back("When a computer program does not do what you");
		newQuestion.Info.push_back("expect, it is likely that the algorithm that ");
		newQuestion.Info.push_back("you designed is flawed. Go back to your algorithm ");
		newQuestion.Info.push_back("and separate it into parts and see how this relates ");
		newQuestion.Info.push_back("to the program that you have created.");
		newQuestion.Info.push_back("");
		newQuestion.Info.push_back("Being able to see what is happening inside a ");
		newQuestion.Info.push_back("program is very useful when DEBUGGING.");

		new_Bos_obj->addQuestion(newQuestion);

		break;
	case Factory::BULLET_ONE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.01f, 0.06f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\bullet_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::PLAYER_WPN);

		break;
	case Factory::BULLET_TWO:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.025f, 0.025f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\bullet_two.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::PLAYER_WPN);

		break;
	case Factory::BULLET_THREE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.025f, 0.025f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\bullet_three.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::PLAYER_WPN);

		break;
	case Factory::EXPLOSION:
		//Create the specific type required
		new_exp_obj = new explosion_object();

		//Location, Just set it to 0
		new_exp_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_exp_obj->setScale(0.1f, 0.1f);

		//The texture that will be used by the object
		new_exp_obj->setExplosionsVAOs(loadTexture(L"resources\\textures\\misc\\explosion_one.png"), loadTexture(L"resources\\textures\\misc\\explosion_two.png"));

		//Texture is a square so tell the object that.
		new_exp_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_exp_obj->setShader(game::default_shader);

		break;
	case Factory::ANSWER_CAPSULE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.05f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\answer_capsule.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		break;
	case Factory::MISSLE_ONE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.025f, 0.05f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\missle_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::ENEMY_WPN);

		break;
	case Factory::MISSLE_TWO:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.03f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\missle_two.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::ENEMY_WPN);

		break;
	case Factory::GAME_UI:
		//Create the specific type required
		new_Img_obj = new image_object();

		//Location, Just set it to 0
		new_Img_obj->setLocation(-1.0f, -1.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Img_obj->setScale(2.0f, 2.0f);

		//The texture that will be used by the object
		new_Img_obj->set_Texture(loadTexture(L"resources\\textures\\ui\\ui.png"));

		//Texture is a square so tell the object that.
		new_Img_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Img_obj->setShader(game::default_shader);
		
		break;
	case Factory::INFO_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(glm::vec2(-0.93f, 0.0f));

		new_Txt_obj->setColour(glm::vec3(0.0f, 1.0f, 0.0f));

		break;
	case Factory::ANSWER_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.72f, 0.8f));

		new_Txt_obj->setColour(vec3(0.0f, 1.0f, 0.0f));

		break;
	case Factory::QUESTION_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(-0.93f, 0.8f));

		new_Txt_obj->setColour(vec3(0.0f, 1.0f, 0.0f));


		break;
	case Factory::SCORE_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.81f, -0.68f));

		new_Txt_obj->setColour(vec3(1.0f, 1.0f, 1.0f));


		break;
	case Factory::START_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.8f, 0.0f));

		new_Txt_obj->setColour(vec3(1.0f, 0.0f, 0.0f));
		break;
	case Factory::LEFT_BOSS:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.8f, 0.0f));

		new_Txt_obj->setColour(vec3(1.0f, 0.0f, 0.0f));
		break;
	case Factory::RIGHT_BOSS:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.8f, 0.0f));

		new_Txt_obj->setColour(vec3(1.0f, 0.0f, 0.0f));
		break;
	case Factory::SCORE_BOSS:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.8f, 0.0f));

		new_Txt_obj->setColour(vec3(0.0f, 1.0f, 0.0f));


		break;
	case Factory::BACKGROUND:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(-1.0f, -1.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(2.0f, 2.0f);

		new_Dyn_obj->setSpeed(vec2(0.0f, SPACE_SPEED));

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\background\\bg_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the render layer of the object if diffrent from default
		new_Dyn_obj->setRenderLayer(display_object::BACKGROUND);
		new_Dyn_obj->setType(display_object::GUI_OBJECT);

		break;
	case Factory::BACKGROUND2:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(-1.0f, 1.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(2.0f, 2.0f);

		new_Dyn_obj->setSpeed(vec2(0.0f, SPACE_SPEED));

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\background\\bg_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the render layer of the object if diffrent from default
		new_Dyn_obj->setRenderLayer(display_object::BACKGROUND);
		new_Dyn_obj->setType(display_object::GUI_OBJECT);

		break;

	default:
		break;
	}


	//Set the created object into the parent node
	if (new_Img_obj)
		new_obj = new_Img_obj;
	else if (new_Dyn_obj)
		new_obj = new_Dyn_obj;
	else if (new_Txt_obj)
		new_obj = new_Txt_obj;
	else if (new_Ply_obj)
		new_obj = new_Ply_obj;
	else if (new_exp_obj)
		new_obj = new_exp_obj;
	else if (new_Bos_obj)
		new_obj = new_Bos_obj;


	return new_obj;
}

dynamic_obj_action * Factory::create_object(action_type obj_type, Dynamic_image_obj* parent)
{

	dynamic_obj_action* new_action = nullptr;
	action_shoot* newActShoot = nullptr;

	switch (obj_type)
	{
	case WPN_PLAYER_BASIC:
	case WPN_ENEMY_BASIC:
		newActShoot = new action_shoot(parent, action_shoot::BASIC);
		break;

	case WPN_ENEMY_DIRECTED:
		newActShoot = new action_shoot(parent, action_shoot::SMART);
		break;
	default:
		break;
	}
	if (newActShoot)
		new_action = newActShoot;

	return new_action;


}

Factory::Factory()
{
}