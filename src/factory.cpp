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
	text_object* new_Txt_obj = nullptr;			//Contains all the textual content on the screen
	
	//Used for Text objects
	vector<std::string> text;

	switch (obj_type)
	{
	case Factory::SUPER_AWSOME_PLAYER_SHIP:
		//Create the specific type required
		new_Dyn_obj = new Dynamic_image_obj();

		//Location, Just set it to 0
		new_Dyn_obj->setLocation(0.0f, 0.0f);
		//This is the scale of the object, minus numbers will flip the image on that axis 
		new_Dyn_obj->setScale(1.1f, 1.1f);

		//The texture that will be used by the object
		new_Dyn_obj->set_Texture(loadTexture(L"resources\\textures\\player\\player.png"));

		//Texture is a square so tell the object that.
		new_Dyn_obj->set_VAO(image_object::SquareVAO);

		//The deafult Shader, This will be the same for most objects
		new_Dyn_obj->setShader(game::default_shader);
		
		break;
	case Factory::UI:
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

	case Factory::Test_Text:
		new_Txt_obj = new text_object();

		new_Txt_obj->setLocation(glm::vec2(-0.5f));

		new_Txt_obj->setColour(glm::vec3(1.0f,0.0f,0.0f ));

		text.push_back("This is some test text to test the text output to screen");
		text.push_back("This is the second line of the test text");

		new_Txt_obj->setText(text);

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


	return new_obj;
}

Factory::Factory()
{
}