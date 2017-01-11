#pragma once
#include "display_object.h"
#include <GL\glut.h>
#include <string.h>
#include <vector>
class text_object : public display_object
{
public:
	text_object();
	//####################
	//		Setters
	//####################	
	void			setColour(glm::vec3 colour);

	//####################
	//		Getters
	//####################

	//####################
	//		Modifiers
	//####################
	void			clearText();
	void			clearTextWOreset();
	void			addText(std::string text);


	void			draw(glm::mat4 display_matrix);



private:

	std::vector<std::string>			text;		//Text to display 
	glm::vec3							colour;		//Colour of the text

	int									NoCharToDisp;
};