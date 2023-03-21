// #pragma once

#ifndef InfoFourScene_H
#define InfoFourScene_H

#include "cocos2d.h"
USING_NS_CC;

class InfoFourScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(InfoFourScene);
	void createBack();
	void createNext();
	void doClose(Ref* pSender);
	void doClose2(Ref* pSender);
	cocos2d::CCSprite* person;
	cocos2d::CCSprite* person2;
	cocos2d::CCSprite* person3;
	cocos2d::CCSprite* stage;
	void createStage();
	void createPerson();
	void createPerson2();
	void createPerson3();
private:
	void type(float dt);
	Label* label;
	Label* label2;
	Label* label3;
	Label* label4;
	Sprite* letter;
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
};

#endif