#include "display_object.h"
#include <glm\gtc\matrix_transform.hpp>

using namespace std;
using namespace glm;

unsigned int display_object::class_id = 0;

display_object::display_object()
{
	//Increment the classid and assign it to this object
	this->OID = ++class_id;
}

void display_object::setLocation(vec2)
{
}

void display_object::setLocation(int x, int y)
{
	this->setLocation(vec2(x, y));
}

vec2 display_object::getLocation()
{
	return vec2();
}

vec2 display_object::getScale()
{
	return vec2();
}

void display_object::transpose(vec2 loc)
{
	this->location += loc;
}

void display_object::transpose(int x, int y)
{
	this->transpose(vec2(x, y));
}

