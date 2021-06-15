#include "level2.h"
#include "Snake.h"
#include "cstdlib"
#include "MainMenu.h"
#include "ScoreBoard.h"

USING_NS_CC;
Scene* Level2::createScene()
{
	auto scene = Scene::create();
	auto layer = Level2::create();
	scene->addChild(layer);
	return scene;
}
bool Level2::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto label = Label::createWithTTF("The Greedy Snake", "fonts/Marker Felt.ttf", 24);
	label->setPosition(512, 721);

	// add the label as a child to this layer
	this->addChild(label, 1);
	auto test = Sprite::create("map2.png");
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
	Snakex.push_back(122);
	Snakey.push_back(59);
	Snakex.push_back(92);
	Snakey.push_back(59);
	Snakex.push_back(62);
	Snakey.push_back(59);
	ScoreBoard = ScoreBoard::createScoreBroad(900, 600, score);
	addChild(ScoreBoard);
	for (int i = 0;i < len;i++)
	{
		body.push_back(SnakeSprite::createBody(Snakex[i], Snakey[i], 0));
		addChild(body[i]);
	}
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	schedule(CC_SCHEDULE_SELECTOR(Level2::update), gamespeed);
	return true;
}
void Level2::update(float dt)
{
	CCLOG("update:%d,%f", GetCurrentTime(), dt);
	
	if (direction < 30)
	{
		Level2::clean();
		Level2::eat_food();
		Level2::move();
		body.clear();
		Level2::check_selfdeath();
		Level2::check_map_death();
		body.push_back(SnakeSprite::createBody(Snakex[0], Snakey[0], 1));
		addChild(body[0]);
		for (int i = 1;i < len;i++)
		{
			body.push_back(SnakeSprite::createBody(Snakex[i], Snakey[i], 0));
			addChild(body[i]);
		}
	}

}


void Level2::left()
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
void Level2::right()
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
void Level2::up()
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
void Level2::down()
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
void Level2::check_selfdeath()
{
	for (int i = 1;i < len;i++)
	{
		if (Snakex[0] == Snakex[i] && Snakey[0] == Snakey[i])
		{
			Director::getInstance()->replaceScene(MainMenu::createScene());
		}
	}
}
void Level2::clean()
{
	for (int i = 0;i < len;i++)
	{
		body[i]->removeFromParent();
	}
}
void Level2::eat_food()
{
	if (Snakex[0] == Foodx && Snakey[0] == Foody)
	{
		Food->removeFromParent();
		srand(rand() * rand());
		Foodx = (rand() % 31) * 30 + 62;
		srand(rand() * rand());
		Foody = (rand() % 20) * 30 + 59;
		Food = SnakeSprite::createBody(Foodx, Foody, 2);
		addChild(Food);
		len++;
		Snakex.push_back(0);
		Snakey.push_back(0);
		score += 10;
		ScoreBoard->removeFromParent();
		ScoreBoard = ScoreBoard::createScoreBroad(900, 600, score);
		addChild(ScoreBoard);
		if (score > 20)
			gamespeed = 0.1;
	}
}
void Level2::move()
{
	switch (direction)
	{
	case 27:
		Level2::right();
		break;
	case 28:
		Level2::up();
		break;
	case 26:
		Level2::left();
		break;
	case 29:
		Level2::down();
		break;
	}
}

void Level2::check_map_death()
{
	for (int i = 1;i < 23;i++)
	{
		if ((Snakex[0] == 32|| Snakex[0] == 992) && Snakey[0] == 30*i-1)
		{
			Director::getInstance()->replaceScene(MainMenu::createScene());
		}
	}
	for (int i = 1;i < 34;i++)
	{
		if ((Snakey[0] == 29 || Snakey[0] == 659) && Snakex[0] == 30 * i +2)
		{
			Director::getInstance()->replaceScene(MainMenu::createScene());
		}
	}
}