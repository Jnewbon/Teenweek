#include "explosion_object.h"
#include "defines.h"
explosion_object::explosion_object()
{
	frames_till_death = MAX_FRAME_RATE / 2;
	this->setType(GAME_OBJECT);
	frameChange = MAX_FRAME_RATE /4;
}

void explosion_object::move(float elapsedtime)
{
	if (this->frames_till_death <= 0)
		this->setDestroyed();
	--frames_till_death;
	Dynamic_image_obj::move(elapsedtime);
}

void explosion_object::setExplosionsVAOs(GLuint exp1, GLuint exp2)
{
	this->explosion_one = exp1;
	this->explosion_two = exp2;
	this->set_Texture(this->explosion_one);


}

void explosion_object::draw(glm::mat4 display_matrix)
{
	if (frameChange <= 0)
	{
		if (this->object_Texture == this->explosion_one)
			this->set_Texture(this->explosion_two);
		else
			this->set_Texture(this->explosion_one);
		frameChange = MAX_FRAME_RATE / 4;
	}
	frameChange--;
	Dynamic_image_obj::draw(display_matrix);
}

void explosion_object::setTimeToLive(int timeToLive)
{
	this->frames_till_death = timeToLive;
}
