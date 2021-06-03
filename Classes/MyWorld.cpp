#include "MyWorld.h"
#include "Snake.h"
#include "cstdlib"
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
	direction = 26;
	myKeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode,
		cocos2d::Event* event)
	{
		direction=(int)keycode,
		CCLOG("key is pressed,keycode is %d", keycode);
	};
	srand(unsigned(time(0)));
	Foodx = (rand() % 33) * 30 + 32;
	srand(rand() * rand());
	Foody = (rand() % 22) * 30 + 29;
	Food = SnakeSprite::createBody(Foodx, Foody, 2);
	addChild(Food);
	len = 3;
	Snakex[2] = 32;
	Snakey[2] = 29;
	Snakex[1] = 62;
	Snakey[1] = 29;
	Snakex[0] = 92;
	Snakey[0] = 29;
	
	for (int i = 0;i < len;i++)
	{
		body[i] = SnakeSprite::createBody(Snakex[i], Snakey[i],0);
		addChild(body[i]);
	}
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	schedule(CC_SCHEDULE_SELECTOR(MyWorld::update), 0.2f);
	return true;
}
void MyWorld::update(float dt)
{
	CCLOG("update:%d,%f", GetCurrentTime(), dt);
	
	for (int i = 0;i < len;i++)
	{
		body[i]->removeFromParent();
	}
	if (Snakex[0] == Foodx&&Snakey[0] == Foody)
	{
		Food->bodyDelete(Foodx, Foody);
		srand(rand() * rand());
		Foodx = (rand() % 33) * 30 + 32;
		srand(rand() * rand());
		Foody = (rand() % 22) * 30 + 29;
		Food = SnakeSprite::createBody(Foodx, Foody, 2);
		addChild(Food);
		len++;
	}
	switch (direction)
	{
	case 27:
		MyWorld::right();
		break;
	case 28:
		MyWorld::up();
		break;
	case 26:
		MyWorld::left();
		break;
	case 29:
		MyWorld::down();
		break;
	}
	body[0] = SnakeSprite::createBody(Snakex[0], Snakey[0], 1);
	addChild(body[0]);
	
	for (int i = 1;i < len;i++)
	{
		body[i] = SnakeSprite::createBody(Snakex[i], Snakey[i],0);
		addChild(body[i]);
	}
	
}



void MyWorld::left()
{
	for (int i = len - 1;i > 0;i--)
	{
		Snakex[i] = Snakex[i - 1];
		Snakey[i] = Snakey[i - 1];
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
		Snakex[i] = Snakex[i - 1];
		Snakey[i] = Snakey[i - 1];
		
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
			Snakex[i] = Snakex[i - 1];
			Snakey[i] = Snakey[i - 1];
	}
	if (Snakey[0] == 29)
		Snakey[0] = 659;
	else
		Snakey[0] -= 30;
}