#include "dynamic_image_obj.h"
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

void Dynamic_image_obj::transpose(glm::vec2 loc)
{
	this->location += loc;
}

void Dynamic_image_obj::transpose(int x, int y)
{
	this->transpose(vec2(x, y));
}
