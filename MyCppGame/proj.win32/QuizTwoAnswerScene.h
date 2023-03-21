// #pragma once

#ifndef QuizTwoAnswerScene_H
#define QuizTwoAnswerScene_H

#include "cocos2d.h"
USING_NS_CC;

class QuizTwoAnswerScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizTwoAnswerScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doReplaceScene(cocos2d::Ref* pSender);
	void doPushQuiz_Answer(Ref* pSender);
};

#endif
