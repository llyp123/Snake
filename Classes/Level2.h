#ifndef LEVEL2_H
#define LEVEL2_H
#include "Snake.h"
#include "ScoreBoard.h"
#include <vector>
class Level2 :public cocos2d::Layer
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

	ScoreBoard* ScoreBoard;
	std::vector<SnakeSprite*> body;
	SnakeSprite* Food;
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Level2);
	virtual void update(float dt);
	void check_map_death();
	void check_selfdeath();
	void clean();
	void eat_food();
	void move();
	void back(Ref* pSender);
	void restart(Ref* pSender);
};

#endif