// #pragma once

#ifndef StageThreeScene_H
#define StageThreeScene_H

#include "cocos2d.h"
USING_NS_CC;

class StageThreeScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StageThreeScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doReplaceScene(cocos2d::Ref* pSender);

	cocos2d::CCSprite* people;
	cocos2d::CCSprite* people2;
	cocos2d::MenuItemImage* closeItem1;
	void createBackgroundParallax();
	void createPeople();
	void createPeople2();
	void createBack();
	bool isLeftKeyArrow;
	bool isRightKeyArrow;
	bool isUpKeyArrow;
	bool isDownKeyArrow;

	int distance;


	virtual void onEnter();
	virtual void onExit();
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void startMovingBackground();
	void stopMovingBackground();
	void menuCloseCallback(cocos2d::Ref* pSender);

	void moveBackground(float t);
	Label* labelTime;
	cocos2d::Sprite* _timerBG;
	void setTimer();
	float _countDownTimer;
	void updateTimer(float time);
};

#endif