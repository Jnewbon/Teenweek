#pragma once
#include "image_object.h"
class Dynamic_image_obj : public image_object
{
public:
	Dynamic_image_obj();
	//####################
	//		Setters
	//####################	

	//####################
	//		Getters
	//####################

	//####################
	//		Modifiers
	//####################

	//####################
	//		Actions
	//####################
	//These function will move the object by the amount parsed
	virtual void	move(float elapsedtime);



protected:
	//####################
	//		Variables
	//####################
	glm::vec2			speed;		//The object current Speed
private:
	//TODO: Health

	//TODO: movment behaviour

	//TODO: Attack Strategy Pattern



};