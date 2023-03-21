// #pragma once

#ifndef StageOneScene_H
#define StageOneScene_H

#include "cocos2d.h"
USING_NS_CC;

class StageOneScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StageOneScene);
	void doClose(Ref* pSender);
	int distancex, distancey;
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
	void doAction1(Ref* pSender);
	void doAction2(Ref* pSender);
	void doAction3(Ref* pSender);
	void doAction4(Ref* pSender);
	void doAction5(Ref* pSender);
	void doAction6(Ref* pSender);
	void doAction7(Ref* pSender);
	void doAction8(Ref* pSender);
	bool isLeftKeyArrow;
	bool isRightKeyArrow;
	bool isUpKeyArrow;
	bool isDownKeyArrow;
	virtual void onEnter();
	virtual void onExit();
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void startMovingBackground();
	void stopMovingBackground();
	void moveBackground(float t);
};

#endif