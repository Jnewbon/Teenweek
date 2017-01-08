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
	case Factory::SUPER_AWSOME_PLAYER_SHIP:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0, 0);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(1, 1);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"Resourses\\Textures\\1.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);

		//Set the created objet into the parent node for passing back
		new_obj = new_Dyn_obj;
		break;
	default:
		break;
	}


	return new_obj;
}

Factory::Factory()
{
}