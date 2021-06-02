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
	auto label = Label::createWithTTF("The Greedy Snake", "fonts/Marker Felt.ttf", 24);
	label->setPosition(512,721);

	// add the label as a child to this layer
	this->addChild(label, 1);
	auto test = Sprite::create("map1.png");
	test->setPosition(512,384);
	this->addChild(test);
	///////////////////////////
	auto myKeyListener = EventListenerKeyboard::create();
	myKeyListener->onKeyPressed = [](EventKeyboard::KeyCode keycode,
		cocos2d::Event *event)
	{
		CCLOG("key is pressed,keycode is %d", keycode);
	};
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	return true;
}