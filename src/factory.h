#pragma once
#include "texture_loader.h"
#include "dynamic_image_obj.h"
#include "text_object.h"

class Factory
{
public:
	enum Types {
		//Game Objects
		PLAYER_SHIP,
		ENEMY_ONE,
		ENEMY_TWO,
		ENEMY_THREE,
		ENEMY_FOUR,
		ENEMY_FIVE,
		BOSS_ONE,
		BOSS_TWO,
		BOSS_THREE,
		BOSS_FOUR,
		BULLET_ONE,
		BULLET_TWO,
		BULLET_THREE,
		ANSWER_CAPSULE,
		MISSLE_ONE,
		MISSLE_TWO,
		EXPLOSION_ONE,
		EXPLOSION_TWO,
		//UI Objects
		GAME_UI,
		BACKGROUND,
		BACKGROUND2,
		//Text Objects
		INFO_TEXT,
		ANSWER_TEXT,
		QUESTION_TEXT
	};

	enum action_type {
		WPN_PLAYER_BASIC
	};

	static display_object*		create_object(Types obj_type);
	static dynamic_obj_action*	create_object(action_type obj_type, Dynamic_image_obj* parent);


protected:

	Factory();



};