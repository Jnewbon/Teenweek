#include "boss_object.h"
#include <glm\gtc\matrix_transform.hpp>
#include "GL\glut.h"
#include "dynamic_obj_action.h"
#include "defines.h"

using namespace glm;

boss_object::boss_object()
{
	Dynamic_image_obj::Dynamic_image_obj();
	this->type  = GAME_OBJECT;
	this->renderLayer = GAME_SPACE;
	this->setObjectType(SHIP);
	this->fireRate = 0;
}


void boss_object::move(float elapsedtime)
{

	if (this->getLocation().y < GAME_SPACE_TOP - (this->getScale().y +0.05f))
	{
		this->speed = vec2(0.0f);
	}

	if ((this->location.x < -0.25f && this->speed.x < 0.0f) || (this->location.x + this->scale.x > 0.653f && this->speed.x > 0.0f))
		this->speed.x = 0.0f;

	this->location += this->speed * elapsedtime;

	static int fireRate = 0;

	if (fireRate++ > 60 && this->action)
	{
		this->action->do_action();
		fireRate = 0;
	}

}
