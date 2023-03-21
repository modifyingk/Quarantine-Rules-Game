// #pragma once

#ifndef StageTwoScene_H
#define StageTwoScene_H

#include "cocos2d.h"
USING_NS_CC;

#define TAG_SPRITE_IMAGE  1000
#define TAG_SPRITE_IMAGE_1  500
#define TAG_SPRITE_IMAGE_2  250

class StageTwoScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(StageTwoScene);
    void doClose(Ref* pSender);
    cocos2d::CCSprite* door;
    cocos2d::CCSprite* table;
    cocos2d::CCSprite* sanitizer;
    cocos2d::CCSprite* hand;
    cocos2d::CCSprite* Vir;
    cocos2d::CCSprite* picture;
    cocos2d::CCSprite* dirtymask;
    cocos2d::CCSprite* virusmass;
    cocos2d::CCSprite* virusmass2;
    cocos2d::CCSprite* bread;
    void createBackgroundParallax();
    void createDoor();
    void createTable();
    void createBread();
    void createSanitizer();
    void createHand();
    void createVir();
    void createPicture();
    void createMask();
    void createVirusMass();
    void createVirusMass2();
    void doAction(Ref* pSender);

    //마우스 이벤트를 위해 추가, 아래 함수들의 정의를 모두 해주어야 요류가 나지 않음
    EventListenerTouchOneByOne* listener;
    EventListenerTouchOneByOne* listenerVir;

    void setMove(Vec2 location);
    void setMoveVir(Vec2 location);
    bool onTouchBegan(Touch* touch, Event* unused_event);
    void onTouchMoved(Touch* touch, Event* unused_event);
    bool onTouchBeganVir(Touch* touch, Event* unused_event);
    void onTouchEnded(Touch* touch, Event* unused_event);



};

#endif StageTwoScene_H