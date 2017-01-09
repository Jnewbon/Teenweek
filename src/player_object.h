#pragma once
#include "Dynamic_image_obj.h"
class player_object : public Dynamic_image_obj
{
public:
	enum keys{
		LEFT_KEY,
		RIGHT_KEY,
		SPACE_KEY,
		NUM_OF_KEYS
	};

	player_object();
	//####################
	//		Setters
	//####################	

	void setMaxSpeed(glm::vec2 maxSpeed);
	void setinertia(glm::vec2 inertia);

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

	void event_SpeckeyPress(int key, bool State);
	void event_keyPress(char key, bool State);


protected:

private:

	glm::vec2			inertia;	//Controls how fast the ships accelarates
	glm::vec2			maxSpeed;	//Set the max limit for speed

	bool				keysdown[NUM_OF_KEYS];

	//####################
	//		Variables
	//####################


};