#ifndef BreadFailScene_H
#define BreadFailScene_H

#include "cocos2d.h"
USING_NS_CC;

#define TAG_SPRITE_IMAGE  1000
#define TAG_SPRITE_IMAGE_1  500

class BreadFailScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(BreadFailScene);
    void doClose(Ref* pSender);
    void doClose2(Ref* pSender);
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
    cocos2d::CCSprite* game;
    cocos2d::CCSprite* over;
    void createBackgroundParallax();
    void createDoor();
    void createTable();
    void createBread();
    void createSanitizer();
    void createHand();
    void createPicture();
    void createMask();
    void createVirusMass();
    void createVirusMass2();
    void createGame();
    void createOver();
    void createVir();
};

#endif