#pragma once
#include <glm\glm.hpp>
#include "texture_loader.h"

class display_object
{
public:
	enum display_obj_type { GUI_OBJECT,
							GAME_OBJECT,
							TEXT_OBJECT };
	display_object();
	//####################
	//		Setters
	//####################	
	virtual void	setLocation(	glm::vec2 loc);
	virtual void	setLocation(	int x,
									int y);
	virtual void	setScale(		glm::vec2 scale);
	virtual void	setScale(		int x,
									int y);
	//####################
	//		Getters
	//####################
	
	virtual glm::vec2	getLocation();
	virtual glm::vec2	getScale();



	virtual void	draw(glm::mat4 ) = 0;


protected:

//####################
//		Variables
//####################
	static unsigned int		class_id;			//the static class id generator

	unsigned int			OID;				// Object ID
	glm::vec2				location;			// Location of the object
	glm::vec2				scale;				// Object Scale/Size
	display_obj_type		type;				// Type of the object


	

};