// #pragma once

#ifndef StageThreeClearScene_H
#define StageThreeClearScene_H

#include "cocos2d.h"
#include "HelloWorldScene.h"
USING_NS_CC;

class StageThreeClearScene :public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StageThreeClearScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	//void doReplaceScene(cocos2d::Ref* pSender);
};

#endif