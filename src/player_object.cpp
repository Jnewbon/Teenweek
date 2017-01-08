#include "player_object.h"
#include <glm\gtc\matrix_transform.hpp>
#include "GL\glut.h"

using namespace glm;

player_object::player_object()
{
	Dynamic_image_obj::Dynamic_image_obj();
	this->type = PLAYER_OBJECT;
	this->inertia = vec2(0.0f);
	this->maxSpeed = vec2(0.0f);
	for (unsigned int i = 0; i < NUM_OF_KEYS; i++)
		keysdown[i] = false;
}

void player_object::setMaxSpeed(glm::vec2 maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void player_object::setinertia(glm::vec2 inertia)
{
	this->inertia = inertia;
}

void player_object::move(float elapsedtime)
{
	if (keysdown[LEFT_KEY])
	{
		if (this->speed.x > -this->maxSpeed.x)
		{
			if (this->speed.x > 0.0f)
				this->speed.x -= (this->inertia.x * elapsedtime)*2.0f;
			else
				this->speed.x -= this->inertia.x * elapsedtime;
		}
	}
	else if (keysdown[RIGHT_KEY])
	{
		if (this->speed.x < this->maxSpeed.x)
		{
			if (this->speed.x < 0.0f)
				this->speed.x += (this->inertia.x * elapsedtime)*2.0f;
			else
				this->speed.x += (this->inertia.x) * elapsedtime;
		}
	}
	else
	{
		if (this->speed.x > (this->inertia.x) * elapsedtime)
			this->speed.x -= (this->inertia.x) * elapsedtime;
		else if (this->speed.x < -(this->inertia.x) * elapsedtime)
			this->speed.x += (this->inertia.x) * elapsedtime;
		else
			this->speed.x = 0.0f;
	}

	Dynamic_image_obj::move(elapsedtime);
}

void player_object::event_keyPress(int key, bool State)
{
	if (key == GLUT_KEY_LEFT)
	{
		keysdown[LEFT_KEY] = State;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		keysdown[RIGHT_KEY] = State;
	}
}
