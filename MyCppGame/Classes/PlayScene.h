// #pragma once

#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "cocos2d.h"
USING_NS_CC;

class PlayScene :public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(PlayScene);
	void doClose(Ref* pSender);
};

#endif
