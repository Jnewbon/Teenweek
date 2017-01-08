#include "text_object.h"
#include <string>
#include "cls_game.h"

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
	//glDisable(GL_TEXTURE_2D);
	//glOrtho(0.0f, game::screenSize.x, game::screenSize.y, 0.0f, -1.0f, 1.0f);
	glColor3f(colour.r, colour.g, colour.b);
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, 0.0f);


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
