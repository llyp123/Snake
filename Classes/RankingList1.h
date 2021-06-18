#ifndef RANKING_LIST1_H
#define RANKING_LIST1_H

#include "cocos2d.h"
#include "ScoreBoard.h"
class RankingList1 : public cocos2d::Scene
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

    void back(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(RankingList1);
};

#endif // __HELLOWORLD_SCENE_H__