// #pragma once

#ifndef QuizFourScene_H
#define QuizFourScene_H

#include "cocos2d.h"
USING_NS_CC;

class QuizFourScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizFourScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doReplaceScene(cocos2d::Ref* pSender);
	void doPushQuiz_o(Ref* pSender);
	void doPushQuiz_x(Ref* pSender);
};

#endif