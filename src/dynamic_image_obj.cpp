#include "dynamic_image_obj.h"
#include <glm\gtc\matrix_transform.hpp>
#include "dynamic_obj_action.h"
#include "cls_game.h"

using namespace glm;

Dynamic_image_obj::Dynamic_image_obj()
{
	this->type = GAME_OBJECT;
	this->renderLayer = GAME_SPACE;
	this->isDestroyed = false;
	fireRate = 30;
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
	if (this->gameObjectType == SHIP || this->gameObjectType == ENEMY_WPN || this->gameObjectType == PLAYER_WPN)
	{
		game_msg newMsg;
		newMsg.msg_type = CREATE_OBJECT;
		newMsg.msg_contents.create_obj.newType = Factory::EXPLOSION;
		newMsg.msg_contents.create_obj.action = NO_ACTION;
		newMsg.msg_contents.create_obj.spawnLocation = this->getLocation();
		newMsg.msg_contents.create_obj.speed = this->speed; // glm::vec2(0.0f, 0.0f);
		newMsg.msg_contents.create_obj.spawnScale = this->getScale();

		game::recive_message(newMsg);

	}
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
//	if (this->action)
//		this->action->do_action();
	if (this->renderLayer == display_object::BACKGROUND)
	{
		if (this->getLocation().y < -3.0f)
			this->setLocation(this->getLocation() + vec2(0.0f, 4.0f));
	}

	if (fireRate++ > ENEMY_MAX_FIRE_RATE && this->action)
	{
		this->action->do_action();
		fireRate = 0;
	}
}
