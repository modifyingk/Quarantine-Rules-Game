// #pragma once

#ifndef QuizThreeScene_H
#define QuizThreeScene_H

#include "cocos2d.h"
USING_NS_CC;

class QuizThreeScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizThreeScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doReplaceScene(cocos2d::Ref* pSender);
	void doPushQuiz_o(Ref* pSender);
	void doPushQuiz_x(Ref* pSender);
};

#endif