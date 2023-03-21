#ifndef QuizFinalScene_H
#define QuizFinalScene_H

#include "cocos2d.h"
#include "HelloWorldScene.h"
USING_NS_CC;

class QuizFinalScene :public LayerColor
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(QuizFinalScene);
	void doClose(Ref* pSender);
	void menuCallback(cocos2d::Ref* sender);
};

#endif