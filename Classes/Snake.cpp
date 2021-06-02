#include "Snake.h"

USING_NS_CC;
Scene* Snake::createScene()
{
	auto scene = Scene::create();
	auto layer = Snake::create();
	scene->addChild(layer);
	return scene;
}
bool Snake::init()
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


	return true;
}