#include "text_object.h"
#include <string>
#include "cls_game.h"

text_object::text_object()
{
	this->type = TEXT_OBJECT;
}

void text_object::setText(std::vector<std::string> text)
{
	this->text = text;
}

void text_object::setColour(glm::vec3 colour)
{
	this->colour = colour;
}

void text_object::draw(glm::mat4 display_matrix)
{
	glUseProgram(0); 
	glDisable(GL_TEXTURE);
	glDisable(GL_TEXTURE_2D);
	glColor3f(colour.r, colour.g, colour.b);

	int len, i, linenum = 0;

	for (std::vector<std::string>::iterator textItor = text.begin(); textItor != text.end(); textItor++)
	{
		glRasterPos2f(this->location.x, this->location.y - ((linenum++)*0.025));
		std::string  textstr = (*textItor);

		len = (int)textstr.length();
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)textstr[i]);
		}
	
	}
}
