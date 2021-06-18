#ifndef LEVEL1_H
#define LEVEL1_H
#include "Snake.h"
#include "ScoreBoard.h"
#include <vector>
class Level1 :public cocos2d::Layer
{
public:
	int len;
	int direction;
	int Foodx, Foody;
	double gamespeed;
	std::vector<int> Snakex;
	std::vector<int> Snakey;
	int score;

	void right();
	void left();
	void up();
	void down();

	ScoreBoard* scoreboard;
	std::vector<SnakeSprite*> body;
	SnakeSprite* Food;
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Level1);
	virtual void update(float dt);

	void check_selfdeath();
	void clean();
	void eat_food();
	void move();
	void back(Ref* pSender);
	void restart(Ref* pSender);
};

#endif