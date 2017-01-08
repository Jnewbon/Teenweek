#include "factory.h"
#include "texture_loader.h"
#include "cls_game.h"
#include <memory>

using namespace std;

display_object * Factory::create_object(Types obj_type)
{
	display_object* new_obj = nullptr;			//The parent node used for passing the object back to the caller
	image_object* new_Img_obj = nullptr;		//Contains all static image objects, The GUI and similer
	Dynamic_image_obj* new_Dyn_obj = nullptr;	//Contains all dynamic image objects, Ships and games specific onjects
	
	

	switch (obj_type)
	{
	case Factory::PLAYER_SHIP:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\player\\player.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	case Factory::ENEMY_ONE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.2f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\enemies\\enemy_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	case Factory::BULLET_ONE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.0001f, 0.0001f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\bullet_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	case Factory::BULLET_TWO:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\bullet_two.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	case Factory::BULLET_THREE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\bullet_three.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	case Factory::ANSWER_CAPSULE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\answer_capsule.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	case Factory::MISSLE_ONE:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\missle_one.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	case Factory::MISSLE_TWO:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(0.1f, 0.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\misc\\missle_two.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
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

		//Set the created objet into the parent node for passing back
		new_obj = new_Img_obj;
		break;
	case Factory::BACKGROUND:
		//Create the specific type required
		new_Img_obj = new image_object();

		//Location, Just set it to 0
		new_Img_obj->setLocation(-1.0f, -1.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Img_obj->setScale(2.0f, 2.0f);

		//The texture that will be used by the object
		new_Img_obj->set_Texture(loadTexture(L"resources\\textures\\background\\bg_one.png"));

		//Texture is a square so tell the object that.
		new_Img_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Img_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Img_obj;
		break;
	default:
		break;
	}


	return new_obj;
}

Factory::Factory()
{
}