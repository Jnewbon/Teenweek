#pragma once
#include "dynamic_obj_action.h"

class action_shoot: public dynamic_obj_action
{
public:
	enum weapons_types {
		BASIC
	};
	action_shoot(Dynamic_image_obj* parent);


	void do_action();

private:

	weapons_types weapon;

};