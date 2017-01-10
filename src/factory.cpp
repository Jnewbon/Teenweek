#include "factory.h"
#include "texture_loader.h"
#include "cls_game.h"
#include "player_object.h"
#include <memory>
#include "dynamic_obj_action.h"
#include "action_shoot.h"

using namespace std;
using namespace glm;

display_object * Factory::create_object(Types obj_type)
{
	display_object* new_obj = nullptr;			//The parent node used for passing the object back to the caller
	image_object* new_Img_obj = nullptr;		//Contains all static image objects, The GUI and similer
	Dynamic_image_obj* new_Dyn_obj = nullptr;	//Contains all dynamic image objects, Ships and games specific onjects
	text_object* new_Txt_obj = nullptr;			//Contains all the textual content on the screen
	player_object* new_Ply_obj = nullptr;		



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
		new_Ply_obj->setinertia(vec2(0.25f));
		new_Ply_obj->setMaxSpeed(vec2(0.25f));


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
		new_Dyn_obj->setLocation(0.1638f, 1.2f);
		
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setSpeed(vec2(0.0f, -0.4f));

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		break;
	case Factory::ENEMY_TWO:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_two.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

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

		break;
	case Factory::BOSS_ONE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.2f, 0.65f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		break;
	case Factory::BOSS_TWO:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.4f, 0.35f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_two.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		break;
	case Factory::BOSS_THREE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.5f, 0.8f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_three.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

		break;
	case Factory::BOSS_FOUR:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.35f, 0.75f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\boss_four.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		new_Dyn_obj->setObjectType(Dynamic_image_obj::SHIP);

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
		new_Dyn_obj->setScale(0.05f, 0.1f);

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

		new_Txt_obj->setColour(glm::vec3(1.0f, 1.0f, 1.0f));

		text.push_back("               //INFORMATION SCREEN");
		text.push_back("");

		//game start
		text.push_back("Welcome programming cadet!");
		text.push_back("You have been tasked with defending the Galaxy.");
		text.push_back("");
		text.push_back("Move the Ship using the LEFT and RIGHT arrow keys.");
		text.push_back("Fire by pressing or holding the SPACE key.");
		text.push_back("");
		text.push_back("Give this a try!");

		//wait 10-20 seconds

		text.push_back("");
		text.push_back("");
		text.push_back("");
		text.push_back("");
		text.push_back("");

		new_Txt_obj->setText(text);

		break;
	case Factory::ANSWER_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.72f, 0.8f));

		new_Txt_obj->setColour(vec3(1.0f, 1.0f, 1.0f));

		text.push_back(" //COLLECTED ANSWERS");

		new_Txt_obj->setText(text);

		break;
	case Factory::QUESTION_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(-0.93f, 0.8f));

		new_Txt_obj->setColour(vec3(1.0f, 1.0f, 1.0f));

		text.push_back("               //QUESTION SCREEN");

		new_Txt_obj->setText(text);

		break;
	case Factory::BACKGROUND:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(-1.0f, -1.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(2.0f, 2.0f);

		new_Dyn_obj->setSpeed(vec2(0.0f, -0.1f));

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

		new_Dyn_obj->setSpeed(vec2(0.0f, -0.1f));

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


	return new_obj;
}

dynamic_obj_action * Factory::create_object(action_type obj_type, Dynamic_image_obj* parent)
{

	dynamic_obj_action* new_action = nullptr;
	action_shoot* newActShoot = nullptr;

	switch (obj_type)
	{
	case WPN_PLAYER_BASIC:
		newActShoot = new action_shoot(parent);

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