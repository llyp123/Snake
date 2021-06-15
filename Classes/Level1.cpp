#include "level1.h"
USING_NS_CC;
bool Level1::init()
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
	direction = 27;
	score = 0;
	gamespeed = 0.1;
	myKeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode,
		cocos2d::Event* event)
	{
		direction = (int)keycode,
			CCLOG("key is pressed,keycode is %d", keycode);
	};
	srand(unsigned(time(0)));
	Foodx = (rand() % 33) * 30 + 32;
	srand(rand() * rand());
	Foody = (rand() % 22) * 30 + 29;
	Food = SnakeSprite::createBody(Foodx, Foody, 2);
	addChild(Food);
	len = 3;
	Snakex.push_back(92);
	Snakey.push_back(29);
	Snakex.push_back(62);
	Snakey.push_back(29);
	Snakex.push_back(32);
	Snakey.push_back(29);
	ScoreBoard = ScoreBoard::createScoreBroad(900, 600, score);
	addChild(ScoreBoard);
	for (int i = 0;i < len;i++)
	{
		body.push_back(SnakeSprite::createBody(Snakex[i], Snakey[i], 0));
		addChild(body[i]);
	}
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	schedule(CC_SCHEDULE_SELECTOR(Level1::update), gamespeed);
	return true;
}
void Level1::update(float dt)
{
	CCLOG("update:%d,%f", GetCurrentTime(), dt);
	MyWorld::check_selfdeath();
	if (direction < 30)
	{
		MyWorld::clean();
		MyWorld::eat_food();
		MyWorld::move();
		body.clear();
		body.push_back(SnakeSprite::createBody(Snakex[0], Snakey[0], 1));
		addChild(body[0]);
		for (int i = 1;i < len;i++)
		{
			body.push_back(SnakeSprite::createBody(Snakex[i], Snakey[i], 0));
			addChild(body[i]);
		}
	}

}