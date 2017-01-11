#pragma once
#include "Dynamic_image_obj.h"
class boss_object : public Dynamic_image_obj
{
public:

	boss_object();
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


	//####################
	//		Actions
	//####################

	void move(float elapsedtime);



protected:

private:

	int fireRate;
	//####################
	//		Variables
	//####################


};