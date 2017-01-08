#include "image_object.h"
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

void image_object::set_Texture(GLuint texture)
{
	this->object_Texture = texture;
}

void image_object::draw(mat4 display_matrix)
{
	mat4 temp = display_matrix * glm::translate(mat4(1.0f), vec3(this->getLocation(), 0.0f)) * glm::scale(mat4(1.0f), vec3(this->getScale(), 0.0f));

	glEnable(GL_TEXTURE_2D);
	glUseProgram(object_Shader);
	glBindVertexArray(object_VAO);

	glBindTexture(GL_TEXTURE_2D, object_Texture);
	glUniformMatrix4fv(glGetUniformLocation(object_Shader, "m_transform"), 1, GL_FALSE, (GLfloat*)&(temp));
	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_BYTE, (GLvoid*)0);
	glBindVertexArray(0);
}


void image_object::setShader(GLuint shader)
{
	this->object_Shader = shader;
}

