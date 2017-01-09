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

void display_object::setLocation(vec2 loc)
{
	this->location = loc;
}

void display_object::setLocation(float x, float y)
{
	this->setLocation(vec2(x, y));
}

void display_object::setScale(glm::vec2 scale)
{
	this->scale = scale;
}

void display_object::setScale(float x, float y)
{
	this->setScale(vec2(x, y));
}

void display_object::setRenderLayer(renderLayers newLayer)
{
	this->renderLayer = newLayer;
}

vec2 display_object::getLocation()
{
	return this->location;
}

vec2 display_object::getScale()
{
	return this->scale;
}

display_object::display_obj_type display_object::getType()
{
	return this->type;
}

display_object::renderLayers display_object::getRenderLayer()
{
	return this->renderLayer;
}
