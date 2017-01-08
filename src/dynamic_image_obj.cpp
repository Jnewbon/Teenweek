#include "dynamic_image_obj.h"
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

Dynamic_image_obj::Dynamic_image_obj()
{
	this->type = GAME_OBJECT;
}

void Dynamic_image_obj::move(float elapsedtime)
{
	this->location += this->speed * elapsedtime;
}
