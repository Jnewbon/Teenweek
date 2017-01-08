#pragma once
#include "texture_loader.h"
#include "dynamic_image_obj.h"

class Factory
{
public:
	enum Types {
		SUPER_AWSOME_PLAYER_SHIP,
	};
	static display_object*		create_object(Types obj_type);


protected:

	Factory();



};