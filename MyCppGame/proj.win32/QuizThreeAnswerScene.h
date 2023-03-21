// #pragma once

#ifndef QuizThreeAnswerScene_H
#define QuizThreeAnswerScene_H

#include "cocos2d.h"
USING_NS_CC;

class QuizThreeAnswerScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizThreeAnswerScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doReplaceScene(cocos2d::Ref* pSender);
	void doPushQuiz_Answer(Ref* pSender);
};

#endif
