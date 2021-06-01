#ifndef MY_WORLD_H
#define MY_WORLD_H

#include "cocos2d.h"
class MyWorld :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MyWorld);
};

#endif