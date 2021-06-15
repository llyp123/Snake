#ifndef LEVEL1_H
#define LEVEL1_H
#include "MyWorld.h"
#include "cocos2d.h"
class Level1:public MyWorld
{
	bool init();
	CREATE_FUNC(Level1);
	void chech_mapdeath();
	void update(float dt);
};
#endif