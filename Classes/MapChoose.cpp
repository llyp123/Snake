
#include "MapChoose.h"
#include "Level1.h"
#include "Level2.h"
#include "RankingList1.h"
#include "RankingList2.h"
USING_NS_CC;

Scene* MapChoose::createScene()
{
    return MapChoose::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MapChoose::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(MapChoose::menuCloseCallback, this));


    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(x, y));





    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    //create BEGIN
    auto Level1_Button = MenuItemImage::create(
        "smallmap1.png",
        "psmallmap1.png",
        CC_CALLBACK_1(MapChoose::Level1Start, this));
    auto Level1 = Menu::create(Level1_Button, NULL);
    Level1->setPosition(250, 300);
    this->addChild(Level1, 1);
    //////////////////////////
    auto Level1_label = Label::createWithTTF("Level 1", "fonts/Marker Felt.ttf", 40);
    Level1_label->setPosition(250, 500);
    this->addChild(Level1_label, 1);

    auto ranking1Button = MenuItemImage::create(
        "begin.png",
        "pbegin.png",
        CC_CALLBACK_1(MapChoose::RankingList1Start, this));
    auto ranking1 = Menu::create(ranking1Button, NULL);
    ranking1->setPosition(250, 100);
    this->addChild(ranking1, 1);
    auto ranking1label = Label::createWithTTF("Ranking List", "fonts/Marker Felt.ttf", 30);
    ranking1label->setPosition(250, 100);
    this->addChild(ranking1label, 1);

    auto Level2_Button = MenuItemImage::create(
        "smallmap2.png",
        "psmallmap2.png",
        CC_CALLBACK_1(MapChoose::Level2Start, this));
    auto Level2 = Menu::create(Level2_Button, NULL);
    Level2->setPosition(774, 300);
    this->addChild(Level2, 1);
    //////////////////////////
    auto Level2_label = Label::createWithTTF("Level 2", "fonts/Marker Felt.ttf", 40);
    Level2_label->setPosition(774, 500);
    this->addChild(Level2_label, 1);

    auto ranking2Button = MenuItemImage::create(
        "begin.png",
        "pbegin.png",
        CC_CALLBACK_1(MapChoose::RankingList2Start, this));
    auto ranking2 = Menu::create(ranking2Button, NULL);
    ranking2->setPosition(774, 100);
    this->addChild(ranking2, 1);
    auto ranking2label = Label::createWithTTF("Ranking List", "fonts/Marker Felt.ttf", 30);
    ranking2label->setPosition(774, 100);
    this->addChild(ranking2label, 1);
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("CHOOSE YOUR MAP", "fonts/Marker Felt.ttf", 96);
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);


    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("MapChoose.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y ));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}


void MapChoose::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void MapChoose::Level1Start(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(Level1::createScene());

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
void MapChoose::Level2Start(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(Level2::createScene());

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
void MapChoose::update(float dt)
{
    CCLOG("update:%d,%f", GetCurrentTime(), dt);
}
void MapChoose::RankingList1Start(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(RankingList1::createScene());

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
void MapChoose::RankingList2Start(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(RankingList2::createScene());

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}