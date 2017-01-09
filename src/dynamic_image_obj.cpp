#include "dynamic_image_obj.h"
#include <glm\gtc\matrix_transform.hpp>
#include "dynamic_obj_action.h"

using namespace glm;

Dynamic_image_obj::Dynamic_image_obj()
{
	this->type = GAME_OBJECT;
	this->renderLayer = GAME_SPACE;
	this->isDestroyed = false;
}

void Dynamic_image_obj::setSpeed(glm::vec2 newSpeed)
{
	this->speed = newSpeed;
}

void Dynamic_image_obj::setAction(dynamic_obj_action * newAction)
{
	if (this->action)
		delete this->action;
	this->action = newAction;
}

void Dynamic_image_obj::setObjectType(objectType gameObjectType)
{
	this->gameObjectType = gameObjectType;
}

void Dynamic_image_obj::setDestroyed()
{
	this->isDestroyed = true;
}

Dynamic_image_obj::objectType Dynamic_image_obj::getObjectType()
{
	return this->gameObjectType;
}

bool Dynamic_image_obj::getDestroyed()
{
	return this->isDestroyed;
}

void Dynamic_image_obj::move(float elapsedtime)
{
	this->location += this->speed * elapsedtime;
	if (this->action)
		this->action->do_action();
	if (this->renderLayer == display_object::BACKGROUND)
	{
		if (this->getLocation().y < -3.0f)
			this->setLocation(this->getLocation() + vec2(0.0f, 4.0f));
	}

}
