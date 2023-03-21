// #pragma once

#ifndef QuizTwoScene_H
#define QuizTwoScene_H

#include "cocos2d.h"
USING_NS_CC;

class QuizTwoScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizTwoScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doReplaceScene(cocos2d::Ref* pSender);
	void doPushQuiz_o(Ref* pSender);
	void doPushQuiz_x(Ref* pSender);
};

#endif