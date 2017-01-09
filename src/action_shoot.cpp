#include "action_shoot.h"
#include "dynamic_image_obj.h"
#include "game_messages.h"
#include "cls_game.h"

action_shoot::action_shoot(Dynamic_image_obj* parent)
{
	this->parent = parent;
}

void action_shoot::do_action()
{
	game_msg newMsg;
	newMsg.msg_type = CREATE_OBJECT;
	newMsg.msg_contents.create_obj.newType = Factory::BULLET_ONE;
	newMsg.msg_contents.create_obj.action = DUMB_TARGET;
	newMsg.msg_contents.create_obj.spawnLocation = this->parent->getLocation() + glm::vec2(0.045f,0.05f);
	newMsg.msg_contents.create_obj.speed = glm::vec2(0.0f, 0.9f);

	game::recive_message(newMsg);


	newMsg.msg_type = CREATE_OBJECT;
	newMsg.msg_contents.create_obj.newType = Factory::BULLET_ONE;
	newMsg.msg_contents.create_obj.action = TARGET_PLAYER;
	newMsg.msg_contents.create_obj.spawnLocation = glm::vec2(0.0f);
	newMsg.msg_contents.create_obj.speed = glm::vec2(0.0f, -0.9f);

	game::recive_message(newMsg);

}