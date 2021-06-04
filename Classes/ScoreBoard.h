#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H

#include "cocos2d.h"

class ScoreBoard : public cocos2d::Layer
{
public:
    int score;
    cocos2d::Label* scoreLabel;
    static ScoreBoard* createScoreBroad(int x, int y, int score);
    bool ScoreBoard::init();
    void scoreInit(int x, int y, int score);

    CREATE_FUNC(ScoreBoard);
};

#endif // __HELLOWORLD_SCENE_H__

