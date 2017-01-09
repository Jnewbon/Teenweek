#pragma once
#include "dynamic_image_obj.h"

class dynamic_obj_action
{
public:
	dynamic_obj_action(Dynamic_image_obj* parent = nullptr);

	virtual void do_action() = 0;

protected:
	Dynamic_image_obj* parent;
};