#pragma once
#include "explosion_object.h"
#include "dynamic_image_obj.h"
#include <glm\glm.hpp>

class explosion_object :public Dynamic_image_obj
{
public:
	explosion_object();
	void move(float elapsedtime);
	void setExplosionsVAOs(GLuint exp1, GLuint exp2);
	void draw(glm::mat4 display_matrix);
	void setTimeToLive(int timeToLive);


protected:
	int frames_till_death;
	int frameChange;

	GLuint explosion_one;
	GLuint explosion_two;
};