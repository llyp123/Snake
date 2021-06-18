#include "Level1.h"
#include "Snake.h"
#include "cstdlib"
#include "MainMenu.h"
#include "ScoreBoard.h"
#include "cocos2d.h"
#include <fstream>
#include <vector>
#include <algorithm>
USING_NS_CC;
Scene* Level1::createScene()
{
	auto scene = Scene::create();
	auto layer = Level1::create();
	scene->addChild(layer);
	return scene;
}
bool Level1::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto label = Label::createWithTTF("The Greedy Snake", "fonts/Marker Felt.ttf", 24);
	label->setPosition(512, 721);
	this->addChild(label, 1);

	auto test = Sprite::create("map1.png");
	test->setPosition(512, 384);
	this->addChild(test);
	///////////////////////////
	auto myKeyListener = EventListenerKeyboard::create();
	direction = 27;
	score = 0;
	gamespeed = 0.1;
	srand(unsigned(time(0)));
	Foodx = (rand() % 31) * 30 + 62;
	srand(rand() * rand());
	Foody = (rand() % 20) * 30 + 59;
	Food = SnakeSprite::createBody(Foodx, Foody, 2);
	addChild(Food);
	len = 3;
	Snakex.push_back(122);
	Snakey.push_back(59);
	Snakex.push_back(92);
	Snakey.push_back(59);
	Snakex.push_back(62);
	Snakey.push_back(59);
	myKeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode,
		cocos2d::Event* event)
	{
		direction = (int)keycode;
	};

	scoreboard = ScoreBoard::createScoreBroad(900, 600, score);
	addChild(scoreboard);
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
	Level1::check_selfdeath();
	if (direction < 30)
	{
		Level1::clean();
		Level1::move();
		body.clear();
		Level1::eat_food();
		
		for (int i = 1;i < len;i++)
		{
			body.push_back(SnakeSprite::createBody(Snakex[i], Snakey[i], 0));
			addChild(body[i]);
		}
	}
}



void Level1::left()
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
void Level1::right()
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
void Level1::up()
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
void Level1::down()
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
void Level1::check_selfdeath()
{
	for (int i = 1;i < len;i++)
	{
		if (Snakex[0] == Snakex[i] && Snakey[0] == Snakey[i])
		{
			this->unschedule(CC_SCHEDULE_SELECTOR(Level1::update));
			auto restartButton = MenuItemImage::create(
				"begin.png",
				"pbegin.png",
				CC_CALLBACK_1(Level1::restart, this));
			auto restart = Menu::create(restartButton, NULL);
			restart->setPosition(512, 200);
			this->addChild(restart, 1);
			//////////////////////////
			auto restartlabel = Label::createWithTTF("Restart", "fonts/Marker Felt.ttf", 30);
			restartlabel->setPosition(512, 200);
			this->addChild(restartlabel, 1);
			direction = 59;

			auto backButton = MenuItemImage::create(
				"begin.png",
				"pbegin.png",
				CC_CALLBACK_1(Level1::back, this));
			auto back = Menu::create(backButton, NULL);
			back->setPosition(512, 100);
			this->addChild(back, 1);
			//////////////////////////
			auto backlabel = Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 30);
			backlabel->setPosition(512, 100);
			this->addChild(backlabel, 1);

			std::string path = FileUtils::getInstance()->fullPathForFilename("Score1.txt");
			std::ifstream infile(path);
			int num;
			std::vector<int> players;
			while (infile >> num)
			{
				players.push_back(num);
			}
			players.push_back(score);
			sort(players.begin(), players.end());

			std::ofstream outfile(path);
			for (int i = 0; i < players.size(); i++)
			{
				outfile << players[i] << std::endl;
			}
			infile.close();
			outfile.close();
			
		}
	}
}
void Level1::clean()
{
	for (int i = 0;i < len;i++)
	{
		body[i]->removeFromParent();
	}
}
void Level1::eat_food()
{
	if (Snakex[0] == Foodx && Snakey[0] == Foody)
	{
		Food->removeFromParent();
		srand(rand() * rand());
		Foodx = (rand() % 33) * 30 + 32;
		srand(rand() * rand());
		Foody = (rand() % 22) * 30 + 29;
		Food = SnakeSprite::createBody(Foodx, Foody, 2);
		addChild(Food);
		len++;
		Snakex.push_back(0);
		Snakey.push_back(0);
		score += 10;
		scoreboard->removeFromParent();
		scoreboard = ScoreBoard::createScoreBroad(900, 600, score);
		addChild(scoreboard);
		body.push_back(SnakeSprite::createBody(Snakex[0], Snakey[0], 3));
		addChild(body[0]);
		if (score > 100&& score < 200)
		{
			this->unschedule(CC_SCHEDULE_SELECTOR(Level1::update));
			gamespeed = 0.08;
			schedule(CC_SCHEDULE_SELECTOR(Level1::update), gamespeed);
		}
		else if (score > 200)
		{
			this->unschedule(CC_SCHEDULE_SELECTOR(Level1::update));
			gamespeed = 0.05;
			schedule(CC_SCHEDULE_SELECTOR(Level1::update), gamespeed);
		}
	}
	else
	{
		body.push_back(SnakeSprite::createBody(Snakex[0], Snakey[0], 1));
		addChild(body[0]);
	}
}
void Level1::move()
{
	switch (direction)
	{
	case 27:
		Level1::right();
		break;
	case 28:
		Level1::up();
		break;
	case 26:
		Level1::left();
		break;
	case 29:
		Level1::down();
		break;
	}
}
void Level1::back(Ref* pSender)
{
	Director::getInstance()->replaceScene(MainMenu::createScene());
}
void Level1::restart(Ref* pSender)
{
	Director::getInstance()->replaceScene(Level1::createScene());
}
