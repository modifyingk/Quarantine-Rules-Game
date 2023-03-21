// #pragma once

#ifndef QuizOneAnswerScene_H
#define QuizOneAnswerScene_H

#include "cocos2d.h"
USING_NS_CC;

class QuizOneAnswerScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizOneAnswerScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doReplaceScene(cocos2d::Ref* pSender);
	void doPushQuiz_Answer(Ref* pSender);
};

#endif
