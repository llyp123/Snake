#ifndef RANKING_LIST_2_H
#define RANKING_LIST_2_H

#include "cocos2d.h"
#include "ScoreBoard.h"
class RankingList2 : public cocos2d::Scene
{
public:
    ScoreBoard* scoreboard1;
    ScoreBoard* scoreboard2;
    ScoreBoard* scoreboard3;
    ScoreBoard* scoreboard4;
    ScoreBoard* scoreboard5;
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void Level2Start(Ref* pSender);
    void Level1Start(Ref* pSender);
    void back(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(RankingList2);
};

#endif // __HELLOWORLD_SCENE_H__