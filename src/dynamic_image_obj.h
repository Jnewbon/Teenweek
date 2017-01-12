#pragma once
#include "image_object.h"
class dynamic_obj_action;
class Dynamic_image_obj : public image_object
{
public:

	enum objectType {
		NOCOLLIDE,
		PLAYER,
		SHIP,
		PLAYER_WPN,
		ENEMY_WPN
	};

	Dynamic_image_obj();
	//####################
	//		Setters
	//####################	
	void	setSpeed(glm::vec2 newSpeed);
	void	setAction(dynamic_obj_action* newAction);
	void	setObjectType(objectType gameObjectType);
	virtual void	setDestroyed();
	//####################
	//		Getters
	//####################
	objectType			getObjectType();
	bool				getDestroyed();

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

	objectType			gameObjectType;

	bool				isDestroyed;

private:
	int fireRate;
	//TODO: Health

	//TODO: movment behaviour

	//TODO: Attack Strategy Pattern
};