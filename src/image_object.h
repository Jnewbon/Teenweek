#include "display_object.h"
class image_object : public display_object
{
public:
	//####################
	//		Setters
	//####################	
	void		set_Texture(GLuint texture);


	//####################
	//		Getters
	//####################

	//####################
	//		Modifiers
	//####################
	void			draw(glm::mat4 display_matrix);

	void			setShader(GLuint shader);
protected:

private:

	//####################
	//		Variables
	//####################

	GLuint					object_Texture;		// Texture of the object
	GLuint					object_Shader;		// The shader used by this object

	//OpenGL specific variables
	GLuint					object_VAO;			// Object Vertex Array Object used to idetify the object on the GPU


};