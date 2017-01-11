#include "action_shoot.h"
#include "dynamic_image_obj.h"
#include "game_messages.h"
#include "cls_game.h"

action_shoot::action_shoot(Dynamic_image_obj* parent, weapons_types type)
{
	this->parent = parent;
	this->weapon = type;
}

void action_shoot::do_action()
{
	game_msg newMsg;
	newMsg.msg_type = CREATE_OBJECT;
	newMsg.msg_contents.create_obj.newType = Factory::BULLET_ONE;

	if (this->weapon == BASIC)
	newMsg.msg_contents.create_obj.action = DUMB_TARGET;
	else if (this->weapon == SMART)
		newMsg.msg_contents.create_obj.action = TARGET_PLAYER;

	
	if (this->parent->getType() == Dynamic_image_obj::PLAYER_OBJECT)
	{
		newMsg.msg_contents.create_obj.speed = glm::vec2(0.0f, 0.9f);
		newMsg.msg_contents.create_obj.newType = Factory::BULLET_ONE; 
		newMsg.msg_contents.create_obj.spawnLocation = this->parent->getLocation() + glm::vec2(0.045f, 0.05f);

	}
	else
	{
		newMsg.msg_contents.create_obj.speed = glm::vec2(0.0f, -0.5f);
		newMsg.msg_contents.create_obj.newType = Factory::MISSLE_ONE;
		newMsg.msg_contents.create_obj.spawnLocation = this->parent->getLocation() + glm::vec2(0.045f, -0.01f);

	}


	game::recive_message(newMsg);

}
