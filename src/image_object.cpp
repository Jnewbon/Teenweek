#include "image_object.h"
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

unsigned int image_object::SquareVAO = 0;

image_object::image_object()
{
	this->type = GUI_OBJECT;
	this->renderLayer = UI_FOREGROUND;
}

void image_object::init()
{
	GLuint framePosVBO, frameColourVBO, frameTexCoordVBO, frameIndicesVBO;
	//

	// Packed vertex arrays for the frame object

	// 1) Position Array - Store vertices as (x,y) pairs
	GLfloat frameVertices[] = {
		//x, y
		0.0f, 0.0f,	// Bottom Left
		1.0f, 0.0f,	// Bottom Right
		0.0f, 1.0f,	// Top Left
		1.0f, 1.0f	// Top Right
	};

	// 2) Colour Array - Store RGB values as unsigned bytes
	GLubyte frameColors[] = {
		139, 69, 19, 255,	// Colour:  Chocolate Brown
		139, 69, 19, 255,
		139, 69, 19, 255,
		139, 69, 19, 255
	};

	// 3) Texture coordinate array (store uv coordinates as floating point values)
	float frameTextureCoords[] = {
		0.0f, 1.0f,	// Bottom Left
		1.0f, 1.0f,	// Bottom Right
		0.0f, 0.0f,	// Top Left
		1.0f, 0.0f	// Top Right
	};

	// 4) Index Array - Store indices to frame vertices - this determines the order the vertices are to be processed
	GLubyte frameVertexIndices[] = { 0, 1, 2, 3 };

	// Create and bind the vertex array object.  This remembers the vertex buffer object bindings below so we don't have to specify them at render time.
	glGenVertexArrays(1, &SquareVAO);
	glBindVertexArray(SquareVAO);

	// setup the frame position VBO
	glGenBuffers(1, &framePosVBO);
	glBindBuffer(GL_ARRAY_BUFFER, framePosVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(frameVertices), frameVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
	glEnableVertexAttribArray(0);

	// setup the frame colour VBO
	glGenBuffers(1, &frameColourVBO);
	glBindBuffer(GL_ARRAY_BUFFER, frameColourVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(frameColors), frameColors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, (const GLvoid*)0);
	glEnableVertexAttribArray(1);

	// setup the frame texture coordinate VBO
	glGenBuffers(1, &frameTexCoordVBO);
	glBindBuffer(GL_ARRAY_BUFFER, frameTexCoordVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(frameTextureCoords), frameTextureCoords, GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid*)0);
	glEnableVertexAttribArray(2);

	// setup frame vertex index array
	glGenBuffers(1, &frameIndicesVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, frameIndicesVBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(frameVertexIndices), frameVertexIndices, GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void image_object::set_Texture(GLuint texture)
{
	this->object_Texture = texture;
}

void image_object::set_VAO(GLuint VAO)
{
	this->object_VAO = VAO;
}

void image_object::draw(mat4 display_matrix)
{
	mat4 temp = display_matrix * glm::translate(mat4(1.0f), vec3(this->getLocation(), 0.0f)) * glm::scale(mat4(1.0f), vec3(this->getScale(), 1.0f));


	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

