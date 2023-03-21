#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "cocos2d.h"
#include "HelloWorldScene.h"
USING_NS_CC;

class PlayScene :public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(PlayScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doPushScene_1(Ref* pSender);
	void doPushScene_2(Ref* pSender);
	void doPushScene_3(Ref* pSender);
	void doPushScene_4(Ref* pSender);
};

#endif
