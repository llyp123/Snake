#include "MyWorld.h"
#include "Snake.h"
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
	label->setPosition(512, 721);

	// add the label as a child to this layer
	this->addChild(label, 1);
	auto test = Sprite::create("map1.png");
	test->setPosition(512, 384);
	this->addChild(test);
	///////////////////////////
	auto myKeyListener = EventListenerKeyboard::create();
	myKeyListener->onKeyPressed = [](EventKeyboard::KeyCode keycode,
		cocos2d::Event* event)
	{
		CCLOG("key is pressed,keycode is %d", keycode);
	};
	len = 3;
	Snakex[0] = 92;
	Snakey[0] = 89;
	Snakex[1] = 62;
	Snakey[1] = 29;
	Snakex[2] = 32;
	Snakey[2] = 29;
	
	for (int i = 0;i < len;i++)
	{
		body[i] = SnakeSprite::createBody(Snakex[i], Snakey[i]);
		addChild(body[i]);
	}
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	schedule(CC_SCHEDULE_SELECTOR(MyWorld::update), 1.0f);
	return true;
}
void MyWorld::update(float dt)
{
	CCLOG("update:%d,%f", GetCurrentTime(), dt);
	
	for (int i = 0;i < len;i++)
	{
		body[i]->bodyDelete(Snakex[i], Snakey[i]);
	}
	MyWorld::left();
	for (int i = 0;i < len;i++)
	{
		body[i] = SnakeSprite::createBody(Snakex[i], Snakey[i]);
		addChild(body[i]);
	}
	
}
void MyWorld::left()
{
	for (int i = len - 1;i > 0;i--)
	{
		if (Snakex[i] == 992)
			Snakex[i] = 32;
		else
		{
			Snakex[i] = Snakex[i - 1];
			Snakey[i] = Snakey[i - 1];
		}
	}
	if (Snakex[0] == 32)
		Snakex[0] = 992;
	else
		Snakex[0] -= 30;
}
void MyWorld::right()
{
	for (int i = len - 1;i > 0;i--)
	{
		if (Snakex[i] == 992)
			Snakex[i] = 32;
		else
		{
			Snakex[i] = Snakex[i - 1];
			Snakey[i] = Snakey[i - 1];
		}
	}
	if (Snakex[0] == 992)
		Snakex[0] = 32;
	else
		Snakex[0] += 30;
}
void MyWorld::up()
{
	for (int i = len - 1;i > 0;i--)
	{
		
		Snakex[i] = Snakex[i - 1];
		Snakey[i] = Snakey[i - 1];
		
	}
	if (Snakey[0] == 659)
		Snakey[0] = 29;
	else
		Snakey[0] += 30;
}
void MyWorld::down()
{
	for (int i = len - 1;i > 0;i--)
	{
		if (Snakex[i] == 992)
			Snakex[i] = 32;
		else
		{
			Snakex[i] = Snakex[i - 1];
			Snakey[i] = Snakey[i - 1];
		}
	}
	if (Snakey[0] == 29)
		Snakey[0] = 659;
	else
		Snakey[0] -= 30;
}