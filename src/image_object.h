#pragma once
#include "display_object.h"
class image_object : public display_object
{
public:
	image_object();
	//####################
	//		Variables
	//####################	
	static GLuint			SquareVAO;			//Contains the VAO for the Sqaure shaped object


	//####################
	//		Setters
	//####################	
	static void	init();

	void		set_Texture(GLuint texture);
	void		set_VAO(GLuint VAO);

	//####################
	//		Getters
	//####################

	//####################
	//		Modifiers
	//####################
	virtual void			draw(glm::mat4 display_matrix);

	void					setShader(GLuint shader);

protected:
	GLuint					object_Texture;		// Texture of the object

private:

	//####################
	//		Variables
	//####################

	GLuint					object_Shader;		// The shader used by this object

	//OpenGL specific variables
	GLuint					object_VAO;			// Object Vertex Array Object used to idetify the object on the GPU



	

};