#pragma once
#include "dynamic_obj_action.h"

class action_shoot: public dynamic_obj_action
{
public:
	enum weapons_types {
		BASIC,
		SMART
	};
	action_shoot(Dynamic_image_obj* parent, weapons_types type);


	void do_action();

	weapons_types weapon;
private:


};