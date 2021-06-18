#include <fstream>
#include "RankingList1.h"
#include "MapChoose.h"
#include "ScoreBoard.h"
USING_NS_CC;

Scene* RankingList1::createScene()
{
    return RankingList1::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool RankingList1::init()
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
        CC_CALLBACK_1(RankingList1::menuCloseCallback, this));


    float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
    float y = origin.y + closeItem->getContentSize().height / 2;
    closeItem->setPosition(Vec2(x, y));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    //create BEGIN
    auto label1 = Label::createWithTTF("No.1", "fonts/Marker Felt.ttf", 35);
    label1->setPosition(300, 532);
    this->addChild(label1, 1);
    auto label2 = Label::createWithTTF("No.2", "fonts/Marker Felt.ttf", 35);
    label2->setPosition(300, 452);
    this->addChild(label2, 1);
    auto label3 = Label::createWithTTF("No.3", "fonts/Marker Felt.ttf", 35);
    label3->setPosition(300, 372);
    this->addChild(label3, 1);
    auto label4 = Label::createWithTTF("No.4", "fonts/Marker Felt.ttf", 35);
    label4->setPosition(300, 292);
    this->addChild(label4, 1);
    auto label5 = Label::createWithTTF("No.5", "fonts/Marker Felt.ttf", 35);
    label5->setPosition(300, 211);
    this->addChild(label5, 1);

  

    
    
 


    


    auto label = Label::createWithTTF("CHOOSE YOUR MAP", "fonts/Marker Felt.ttf", 96);
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);


    auto backButton = MenuItemImage::create(
        "begin.png",
        "pbegin.png",
        CC_CALLBACK_1(RankingList1::back, this));
    auto back = Menu::create(backButton, NULL);
    back->setPosition(512, 100);
    this->addChild(back, 1);
    //////////////////////////
    auto backlabel = Label::createWithTTF("Back", "fonts/Marker Felt.ttf", 30);
    backlabel->setPosition(512, 100);
    this->addChild(backlabel, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("MapChoose.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    std::string path = FileUtils::getInstance()->fullPathForFilename("Score1.txt");
    std::ifstream infile(path);
    int num;
    std::vector<int> players;
    while (infile >> num)
    {
        players.push_back(num);
    }
    infile.close();
    while (players.size() < 5)
        players.push_back(0);
    sort(players.begin(), players.end());
    scoreboard1 = ScoreBoard::createScoreBroad(600, 532, players[players.size() - 1]);
    addChild(scoreboard1);
    scoreboard2 = ScoreBoard::createScoreBroad(600, 452, players[players.size() - 2]);
    addChild(scoreboard2);
    scoreboard3 = ScoreBoard::createScoreBroad(600, 372, players[players.size() - 3]);
    addChild(scoreboard3);
    scoreboard4 = ScoreBoard::createScoreBroad(600, 292, players[players.size() - 4]);
    addChild(scoreboard4);
    scoreboard5 = ScoreBoard::createScoreBroad(600, 212, players[players.size() - 5]);
    addChild(scoreboard5);

    return true;
}


void RankingList1::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}


void RankingList1::back(Ref* pSender)
{
    Director::getInstance()->replaceScene(MapChoose::createScene());
}