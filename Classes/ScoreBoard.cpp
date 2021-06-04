#include "ScoreBoard.h"
#include <string>
USING_NS_CC;
ScoreBoard* ScoreBoard::createScoreBroad(int x, int y, int score)
{
	ScoreBoard* scoreboard= new ScoreBoard();
	if (scoreboard && scoreboard->init())
	{
		scoreboard->autorelease();
		scoreboard->scoreInit(x, y, score);
		return scoreboard;
	}
	CC_SAFE_DELETE(scoreboard);
	return NULL;
}
bool ScoreBoard::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void ScoreBoard::scoreInit(int x, int y, int score)
{
	scoreLabel = Label::createWithTTF(std::to_string(score), "fonts/Marker Felt.ttf", 96);
	scoreLabel->setPosition(x, y);
	addChild(scoreLabel);
}