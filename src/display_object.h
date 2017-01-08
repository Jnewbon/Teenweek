#include <glm\glm.hpp>
#include "texture_loader.h"

class display_object
{
public:
	enum display_obj_type { IMAGE, 
							TEXT };
	display_object();
	//####################
	//		Setters
	//####################	
	virtual void	setLocation(	glm::vec2 loc);
	virtual void	setLocation(	int x,
									int y);
	//####################
	//		Getters
	//####################
	
	virtual glm::vec2	getLocation();
	virtual glm::vec2	getScale();

	//####################
	//		Modifiers
	//####################
	//These function will move the object by the amount parsed
	virtual void	transpose(		glm::vec2 loc);
	virtual void	transpose(		int x,
									int y);

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