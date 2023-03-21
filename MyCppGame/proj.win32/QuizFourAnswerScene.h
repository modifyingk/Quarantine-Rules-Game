#ifndef QuizFourAnswerScene_H
#define QuizFourAnswerScene_H

#include "cocos2d.h"
USING_NS_CC;

class QuizFourAnswerScene : public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizFourAnswerScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
	void doPushQuiz_Answer(Ref* pSender);
};

#endif
