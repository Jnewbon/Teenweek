#pragma once

//Target frame rate, The max FPS the game will run
#define MAX_FRAME_RATE	30
#define MAX_LEVELS		40	

#define SPACE_SPEED							-0.05f

#define PLAYER_SHIP_MAX_SPEED				0.25f
#define PLAYER_SHIP_ACCELARATION			0.25f
#define PLAYER_MAX_FIRE_RATE				30 //How many frames must pass before the weapon reloads Higher is slower


//Enemy ships stats 
#define ENEMY_BASE_SHIP_SPEED				0.1f
#define ENEMY_SHIP_SPEED_LEVEL_FACTOR		0.025f
#define ENEMY_SHIP_MISSILE_SPEED			0.3f

#define ENEMY_SHIP_SPAWN_BASE				200
#define ENEMY_SHIP_SPAWN_PER_LEVEL_FACTOR	20
#define ENEMY_SHIP_SPAWN_RANDOMNESS			50

#define GAME_SPACE_LEFT						-0.25f
#define GAME_SPACE_RIGHT					0.653f
#define GAME_SPACE_TOP						0.85f
#define GAME_SPACE_BOTTOM					-0.75f


//will output the mouse location to console
//#define DEBUG_MOUSE_LOC

//will output the key pressed to console
//#define DEBUG_KEY_PRESS

