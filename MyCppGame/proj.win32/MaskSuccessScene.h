#ifndef MaskSuccessScene_H
#define MaskSuccessScene_H

#include "cocos2d.h"
USING_NS_CC;

class MaskSuccessScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MaskSuccessScene);
	void doClose(Ref* pSender);

	cocos2d::CCSprite* mask;
	cocos2d::CCSprite* virus1;
	cocos2d::CCSprite* virus2;
	cocos2d::CCSprite* virus3;
	cocos2d::CCSprite* virus4;
	cocos2d::CCSprite* virus5;
	cocos2d::CCSprite* virus6;
	cocos2d::CCSprite* virus7;
	cocos2d::CCSprite* virus8;
	cocos2d::CCSprite* person;
	cocos2d::CCSprite* back;
	cocos2d::CCSprite* clear;
	void createBackgroundParallax();
	void createmask();
	void createVirus1();
	void createVirus2();
	void createVirus3();
	void createVirus4();
	void createVirus5();
	void createVirus6();
	void createVirus7();
	void createVirus8();
	void createPerson();
	void createBack();
	void createClear();
	void doAction1(Ref* pSender);
	void doAction2(Ref* pSender);
	void doAction3(Ref* pSender);
	void doAction4(Ref* pSender);
	void doAction5(Ref* pSender);
	void doAction6(Ref* pSender);
	void doAction7(Ref* pSender);
	void doAction8(Ref* pSender);

	virtual void onExit();
};

#endif