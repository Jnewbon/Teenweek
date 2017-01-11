#include "factory.h"
#include "texture_loader.h"
#include "cls_game.h"
#include "player_object.h"
#include <memory>
#include "dynamic_obj_action.h"
#include "action_shoot.h"
#include "explosion_object.h"

using namespace std;
using namespace glm;

display_object * Factory::create_object(Types obj_type)
{
	display_object* new_obj = nullptr;			//The parent node used for passing the object back to the caller
	image_object* new_Img_obj = nullptr;		//Contains all static image objects, The GUI and similer
	Dynamic_image_obj* new_Dyn_obj = nullptr;	//Contains all dynamic image objects, Ships and games specific onjects
	text_object* new_Txt_obj = nullptr;			//Contains all the textual content on the screen
	player_object* new_Ply_obj = nullptr;		//Contains all the textual content on the screen
	explosion_object* new_exp_obj = nullptr;



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

		new_Dyn_obj->setAction(create_object(WPN_ENEMY_DIRECTED, new_Dyn_obj));

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

		new_Txt_obj->setColour(vec3(1.0f, 0.0f, 0.0f));


		break;
	case Factory::SCORE_TEXT:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(vec2(0.8f, -0.68f));

		new_Txt_obj->setColour(vec3(1.0f, 0.0f, 0.0f));


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
	else if (new_exp_obj)
		new_obj = new_exp_obj;


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