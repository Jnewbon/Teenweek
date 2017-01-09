#pragma once
#include "factory.h"
enum game_message_type {
	CREATE_OBJECT,
	UPDATE_SCORE,
};
enum create_obj_action {
	NO_ACTION,
	DUMB_TARGET,			//Will travel directally down from spawn loaction given
	TARGET_PLAYER			//Will Travel towards the ship at time of creation
};

struct Create_object
{
	Factory::Types		newType;			//obj type to create
	glm::vec2			spawnLocation;		//obj spawn location
	create_obj_action	action;
	glm::vec2			speed;
	
};

struct Score_update
{
	int					change_score;	//Contain the change to the score
};

struct game_msg
{
	game_message_type	msg_type;
	union U {
		Create_object	create_obj;
		Score_update	update_score;
		U() {}
	} msg_contents;
};