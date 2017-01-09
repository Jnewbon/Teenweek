#pragma once
#include "image_object.h"
class dynamic_obj_action;
class Dynamic_image_obj : public image_object
{
public:
	Dynamic_image_obj();
	//####################
	//		Setters
	//####################	
	void	setSpeed(glm::vec2 newSpeed);
	void	setAction(dynamic_obj_action* newAction);

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

	dynamic_obj_action*	action;
private:
	//TODO: Health

	//TODO: movment behaviour

	//TODO: Attack Strategy Pattern



};