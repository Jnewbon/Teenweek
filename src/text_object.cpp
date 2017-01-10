#include "text_object.h"
#include <string>
#include "cls_game.h"

#define TYPEWRITER_SPEED 0.1

text_object::text_object()
{
	this->type = TEXT_OBJECT;
	this->renderLayer = UI_FOREGROUND;
	NoCharToDisp = 0;
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

	int total_len = 0, len, i, linenum = 0;


	for (std::vector<std::string>::iterator textItor = text.begin(); textItor != text.end(); textItor++)
	{
		glRasterPos2f(this->location.x, this->location.y - ((linenum++)*0.035));
		std::string  textstr = (*textItor);

		len = (int)textstr.length();
		if (NoCharToDisp == -1)
		{
			for (i = 0; i < len; i++) {
				glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int)textstr[i]);
			}
		}
		else
		{
			for (i = 0; i < len; i++) {
				if (i + total_len < NoCharToDisp / TYPEWRITER_SPEED)
					glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int)textstr[i]);
			}
			total_len += len;
		}
	
	}
	if (NoCharToDisp > total_len*TYPEWRITER_SPEED*2)
		NoCharToDisp = -1;
	else if (NoCharToDisp == -1) {}
	else
		NoCharToDisp++;

}
