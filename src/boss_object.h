#pragma once
#include "Dynamic_image_obj.h"
#include "vector"
#include "text_object.h"


struct question
{
	std::vector<std::string> Question;
	std::vector<std::string> WrongAnswers;
	std::string CorrectAnswer;

};

class boss_object : public Dynamic_image_obj
{
public:

	boss_object();
	//####################
	//		Setters
	//####################	
	
	void addQuestion(question newQuestion);

	//####################
	//		Getters
	//####################

	//####################
	//		Modifiers
	//####################
	//These function will move the object by the amount parsed
	bool					bossHit(glm::vec2 hitLocation);
	virtual void			draw(glm::mat4 display_matrix);
	//####################
	//		Actions
	//####################

	void move(float elapsedtime);
	void setDestroyed();


protected:

	void sendQuestion(int);
private:
	std::vector<question> Questions;
	//std::vector<
	bool desructionSequ;
	int dieTimer;
	int fireRate;
	int CurrentQuestion;
	int CurrentWrongAnswer;
	bool CorrectIsLeft;
	bool QuestionSent;
	bool isImmune;
	int thisScore;

	static text_object* Left_text;
	static text_object* Right_text;
	static text_object* score_text;
	//####################
	//		Variables
	//####################


};