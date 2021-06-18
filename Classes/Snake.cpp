#include "Snake.h"
USING_NS_CC;
SnakeSprite* SnakeSprite::createBody(int x, int y, int type)
{
	SnakeSprite* body = new SnakeSprite();
	if (body && body->init())
	{
		body->autorelease();
		if (type == 0)
			body->bodyInit(x, y);
		else if (type == 1)
			body->headInit(x, y);
		else if (type == 2)
			body->foodInit(x, y);
		else if(type == 3)
			body->bigheadInit(x, y);
		return body;
		body->autorelease();		
		body->headInit(x, y);
		return body;
	}
	CC_SAFE_DELETE(body);
	return NULL;
}
bool SnakeSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}
void SnakeSprite::bodyInit(int x,int y)
{
	body = Sprite::create("body.png");
	body->setPosition(x, y);
	addChild(body);
}
void SnakeSprite::headInit(int x, int y)
{
	body = Sprite::create("head.png");
	body->setPosition(x, y);
	addChild(body);
}
void SnakeSprite::bigheadInit(int x, int y)
{
	body = Sprite::create("bighead.png");
	body->setPosition(x, y);
	addChild(body);
}
void SnakeSprite::foodInit(int x, int y)
{
	body = Sprite::create("food.png");
	body->setPosition(x, y);
	addChild(body);
}
void SnakeSprite::bodyDelete(int x, int y)
{
	body = Sprite::create("texture.png");
	body->setPosition(x, y);
	addChild(body);
}
void SnakeSprite::update(float dt)
{
	CCLOG("update:%d,%f", GetCurrentTime(), dt);
}