// #pragma once

#ifndef InfoTwoScene_H
#define InfoTwoScene_H

#include "cocos2d.h"
USING_NS_CC;

class InfoTwoScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(InfoTwoScene);
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
	Label* label5;
	Label* label6;
	Label* label7;
	Label* label8;
	Label* label9;
	Label* label10;
	Label* label11;
	Label* label12;
	Label* label13;
	Label* label14;
	Label* label15;
	Label* label16;
	Label* label17;
	Label* label18;
	Label* label19;
	Sprite* letter;
	int i = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;
	int h = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int o = 0;
	int p = 0;
	int q = 0;
	int r = 0;
	int s = 0;
};

#endif