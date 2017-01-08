#pragma once
#include "texture_loader.h"
#include "dynamic_image_obj.h"
#include "text_object.h"

class Factory
{
public:
	enum Types {
		//Game Objects (Dynamic Content)
		SUPER_AWSOME_PLAYER_SHIP,

		//UI Objects (Static Content)
		UI,

		//Text Objects
		Test_Text

	};
	static display_object*		create_object(Types obj_type);


protected:

	Factory();



};