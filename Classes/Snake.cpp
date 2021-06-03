#include "Snake.h"
USING_NS_CC;
SnakeSprite* SnakeSprite::createBody(int x, int y)
{
	SnakeSprite* body = new SnakeSprite();
	if (body && body->init())
	{
		body->autorelease();
		body->bodyInit(x, y);
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
void SnakeSprite::bodyDelete2(int x, int y)
{
	body = Sprite::create("texture.png");
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