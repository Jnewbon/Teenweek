#pragma once
#include "texture_loader.h"
#include "dynamic_image_obj.h"

class Factory
{
public:
	enum Types {
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
		GAME_UI,
		BACKGROUND
	};
	static display_object*		create_object(Types obj_type);


protected:

	Factory();



};