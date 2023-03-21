#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PlayScene.h"

class HelloWorld : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(HelloWorld);
    cocos2d::CCSprite* sanitizer;
    cocos2d::CCSprite* dirtymask;
    cocos2d::CCSprite* virus1;
    cocos2d::CCSprite* virus2;
    void createSanitizer();
    void createMask();
    void createVirus1();
    void createVirus2();
    void menuCallback(cocos2d::Ref* sender);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void doReplaceScene(cocos2d::Ref* pSender);

    int distancex, distancey;

};

#endif