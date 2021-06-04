#ifndef MY_WORLD_H
#define MY_WORLD_H
#include "Snake.h"
#include "cocos2d.h"
#include "ScoreBoard.h"
class MyWorld :public cocos2d::Layer
{
public:
	int len;
	int direction;
	int Foodx, Foody;
	int Snakex[500];
	int Snakey[500];
	int score;
	void MyWorld::right();
	void MyWorld::left();
	void MyWorld::up();
	void MyWorld::down();
	ScoreBoard* ScoreBoard;
	SnakeSprite* body[500];
	SnakeSprite* Food;
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MyWorld);
	virtual void update(float dt);
};

#endif