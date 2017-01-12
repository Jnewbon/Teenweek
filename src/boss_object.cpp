#include "boss_object.h"
#include <glm\gtc\matrix_transform.hpp>
#include "GL\glut.h"
#include "dynamic_obj_action.h"
#include "defines.h"
#include "game_messages.h"
#include "cls_game.h"
#include "factory.h"

using namespace glm;


text_object* boss_object::Left_text = (text_object*)Factory::create_object(Factory::LEFT_BOSS);
text_object* boss_object::Right_text = (text_object*)Factory::create_object(Factory::RIGHT_BOSS);
text_object* boss_object::score_text = (text_object*)Factory::create_object(Factory::SCORE_BOSS);

boss_object::boss_object()
{
	Dynamic_image_obj::Dynamic_image_obj();
	this->type  = BOSS_OBJECT;
	this->renderLayer = GAME_SPACE;
	this->setObjectType(SHIP);
	this->fireRate = 0;
	desructionSequ = false;
	dieTimer = 120;
	CurrentQuestion = 0;
	CorrectIsLeft = (bool)((int)rand()%2);
	QuestionSent = false;
	isImmune = true;
	thisScore = 5000;

}

void boss_object::addQuestion(question newQuestion)
{
	Questions.push_back(newQuestion);
}


bool boss_object::bossHit(vec2 hitLocation)
{
	if (isImmune)
		return false;

	if (hitLocation.x < this->location.x + (this->scale.x / 2.0f))
	{
		//Hit Left Side
		if (CorrectIsLeft)
		{
			if (++CurrentQuestion == Questions.size())
			{
				this->setDestroyed();
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (!CorrectIsLeft)
		{
			if (++CurrentQuestion == Questions.size())
			{
				this->setDestroyed();
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	CurrentWrongAnswer = ((int)rand() % 2);
	sendQuestion(CurrentQuestion);
	QuestionSent = true;
	Right_text->clearText();
	Left_text->clearText();
	if (CorrectIsLeft)
	{
		Left_text->addText(Questions[CurrentQuestion].CorrectAnswer);
		Right_text->addText(Questions[CurrentQuestion].WrongAnswers[CurrentWrongAnswer]);
	}
	else
	{
		Right_text->addText(Questions[CurrentQuestion].CorrectAnswer);
		Left_text->addText(Questions[CurrentQuestion].WrongAnswers[CurrentWrongAnswer]);
	}
}

void boss_object::draw(glm::mat4 display_matrix)
{
	if (!isImmune)
	{
		Left_text->setLocation(vec2((this->getLocation().x - 0.05f), this->getScale().y / 2.0f));
		Right_text->setLocation(vec2((this->getLocation().x + this->getScale().x), this->getScale().y / 2.0f));
		score_text->setLocation(vec2((this->getLocation().x + (this->getScale().x/2.0f)), this->getScale().y + 0.15f));
		Left_text->draw(display_matrix);
		Right_text->draw(display_matrix);
		score_text->draw(display_matrix);
	}


	Dynamic_image_obj::draw(display_matrix);
}

void boss_object::move(float elapsedtime)
{

	if (this->getLocation().y < GAME_SPACE_TOP - (this->getScale().y +0.05f))
	{
		this->speed = vec2(0.0f);
		if (!QuestionSent)
		{
			CurrentWrongAnswer = ((int)rand() % 2);
			sendQuestion(CurrentQuestion);
			QuestionSent = true;
			isImmune = false;
				Right_text->clearText();
				Left_text->clearText();
			if (CorrectIsLeft)
			{
				Left_text->addText(Questions[CurrentQuestion].CorrectAnswer);
				Right_text->addText(Questions[CurrentQuestion].WrongAnswers[CurrentWrongAnswer]);
			}
			else
			{
				Right_text->addText(Questions[CurrentQuestion].CorrectAnswer);
				Left_text->addText(Questions[CurrentQuestion].WrongAnswers[CurrentWrongAnswer]);
			}
		}
	}

	if ((this->location.x < -0.25f && this->speed.x < 0.0f) || (this->location.x + this->scale.x > 0.653f && this->speed.x > 0.0f))
		this->speed.x = 0.0f;

	this->location += this->speed * elapsedtime;

	static int fireRate = 0;

	if (fireRate++ > 1 && desructionSequ)
	{
		game_msg newmsg;
		newmsg.msg_type = CREATE_OBJECT;
		newmsg.msg_contents.create_obj.newType = Factory::EXPLOSION;
		newmsg.msg_contents.create_obj.action = NO_ACTION;
		newmsg.msg_contents.create_obj.spawnLocation = vec2(this->getLocation().x + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / ((this->getLocation().x + this->getScale().x) - this->getLocation().x))),
															this->getLocation().y + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / ((this->getLocation().y + this->getScale().y) - this->getLocation().y))));
		newmsg.msg_contents.create_obj.spawnScale = vec2(this->getScale().x * 0.3);
		newmsg.msg_contents.create_obj.speed = vec2(0.0f);
		game::recive_message(newmsg);
		dieTimer--;
		fireRate = 0;
		if (dieTimer <= 0)
			this->isDestroyed = true;
	}
	static int framescoreRate = 0;
	if (!isImmune && framescoreRate++ >= BOSS_SCORE_DROP_EVERY && !isDestroyed)
	{
		if (thisScore > 0)
			thisScore -= BOSS_SCORE_DROP_PER;
		else if (thisScore < 0)
			thisScore = 0;
		score_text->clearTextWOreset();
		score_text->addText(std::to_string(thisScore));
	}

}

void boss_object::setDestroyed()
{
	desructionSequ = true;
	isImmune = true;
	game::addScore(thisScore);
}

void boss_object::sendQuestion(int)
{
	game::showText(game::TEXT_QUESTION, game::REPLACE, Questions[CurrentQuestion].Question[0]);
	if (Questions[CurrentQuestion].Question.size() > 1)
		for (int i = 1; i < Questions[CurrentQuestion].Question.size(); i++)
		{
			game::showText(game::TEXT_QUESTION, game::APPEND, Questions[CurrentQuestion].Question[i]);
		}

}
