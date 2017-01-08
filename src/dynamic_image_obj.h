#pragma once
#include "image_object.h"
class Dynamic_image_obj : public image_object
{
public:
	//####################
	//		Setters
	//####################	

	//####################
	//		Getters
	//####################

	//####################
	//		Modifiers
	//####################
	//These function will move the object by the amount parsed
	virtual void	transpose(glm::vec2 loc);
	virtual void	transpose(int x,
		int y);



protected:

private:
	//TODO: Health

	//TODO: movment behaviour

	//TODO: Attact Strategy Pattern

	//####################
	//		Variables
	//####################


};