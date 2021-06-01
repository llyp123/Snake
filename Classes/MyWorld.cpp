#include "MyWorld.h"
USING_NS_CC;
Scene* MyWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = MyWorld::create();
	scene->addChild(layer);
	return scene;
}
bool MyWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto a = Sprite::create("CloseNormal.png");
	this->addChild(a);

	return true;
}