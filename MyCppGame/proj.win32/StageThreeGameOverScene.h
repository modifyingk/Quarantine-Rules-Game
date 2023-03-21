// #pragma once

#ifndef StageThreeGameOverScene_H
#define StageThreeGameOverScene_H

#include "cocos2d.h"
#include "HelloWorldScene.h"
USING_NS_CC;

class StageThreeGameOverScene :public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StageThreeGameOverScene);
	void doClose(Ref* pSender);
	void doClose2(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
};

#endif