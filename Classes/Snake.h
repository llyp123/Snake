#ifndef SNAKE_H
#define SNAKE_H

#include "cocos2d.h"
class SnakeSprite :public cocos2d::Sprite
{
public:
	Sprite* body;
	void bodyDelete(int x, int y);
	static SnakeSprite* createBody(int x, int y, int type);
	void bodyInit(int x, int y);
	void foodInit(int x, int y);
	void headInit(int x, int y);
	void bodyDelete2(int x, int y);
	virtual bool init();
	void SnakeSprite::update(float dt);
	CREATE_FUNC(SnakeSprite);
};

#endif#pragma once
