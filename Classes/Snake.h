#ifndef SNAKE_H
#define SNAKE_H

#include "cocos2d.h"
class Snake :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Snake);
};

#endif