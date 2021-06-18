#ifndef MAP_CHOOSE_H
#define MAP_CHOOSE_H

#include "cocos2d.h"

class MapChoose : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void Level2Start(Ref* pSender);
    void Level1Start(Ref* pSender);
    virtual void update(float dt);
    void RankingList1Start(Ref* pSender);
    void RankingList2Start(Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(MapChoose);
};

#endif // __HELLOWORLD_SCENE_H__
